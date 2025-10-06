//
// Created by donghao on 25-10-3.
//
#ifndef MAIN_GAME_PAGE_HPP
#define MAIN_GAME_PAGE_HPP
#include <pages/Page.hpp>
#include <player.hpp>
#include <base/message_box.hpp>
#include "Rectangle.hpp"
#include "test/testnpc.hpp"

namespace game {
    class MainGamePage final : public sfui::Page {
        Player player;

        sfui::TaskScheduler tasks;
        TestNpc testNpc;
        sfui::Circle c;
        sfui::TimeInterval timeInterval;
        float dt = 0.0f;
        game::MessageBox *messageBox = nullptr;

    public:
        explicit MainGamePage(sfui::Window *p_window)
            : Page(p_window), player(100, 100, 10, 10, 10, 1000, 100),
              testNpc(200, 200, 30, 30), c(100, 100, 100, sf::Color::Green) {
        }

        void init() override {
            messageBox = new game::MessageBox(500, 500, "hello");

            tasks.addTask(player.update(dt));
            tasks.addTask(testNpc.update(dt));
            activeMap(sfui::Key::A, [this]() { player.moveLift(); });
            activeMap(sfui::Key::W, [this]() { player.moveUp(); });
            activeMap(sfui::Key::D, [this]() { player.moveRight(); });
            activeMap(sfui::Key::S, [this]() { player.moveDown(); });

            eventMap(
                sf::Mouse::Left,
                new sfui::Area(
                    testNpc.getX() - 150, testNpc.getX() + 150,
                    testNpc.getY() - 150,
                    testNpc.getY() + 150
                ),
                [&]() {
                    testNpc.interactive();
                }
            );
        }


        void updateByMessage() override {
        }


        void update() override {
            dt = static_cast<float>(timeInterval.elapsedUs()) / 1'000'000.0f;
            timeInterval.reset();
            tasks.resume();
        }


        void render() override {
            sfui::Rectangle r(testNpc.getX(), testNpc.getY(), 300, 300, sf::Color::Cyan, sf::Color::Cyan);
            sf::RectangleShape rect;
            rect.setSize({testNpc.getX() - 150, testNpc.getY() - 150});
            rect.setFillColor(sf::Color::Green);
            rect.setPosition({testNpc.getX() + 150, testNpc.getY() + 150});

            setWorldViewCenter(player.getX(), player.getY());
            drawForView(
                player,
                c,
                testNpc
            );
            getSfRenderWindow().draw(rect);
            drawForWindow(
                *messageBox
            );
        }
    };
} // game

#endif //MAIN_GAME_PAGE_HPP
