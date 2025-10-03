#pragma once

#include <Page.hpp>
#include <Circle.hpp>

#include <iostream>
#include <player.hpp>
#include <bullet.hpp>
#include <boss.hpp>

#include "test/boss_a.hpp"
#include <progressBar.hpp>

#include "test/player_a.hpp"
#include <word.hpp>

namespace game {
    class MainMenuPage : public sfui::Page {
    private:
        Word word;

        sfui::TextBox textBox;


        game::Player_a player;
        game::Boss_a boss;
        sfui::Task<void> bossUpdate;
        sfui::Task<void> playerUpdate;

        game::Barrage barrage;
        game::Barrage myBarrage;

        sfui::ProgressBar bossHealthBar;
        sfui::ProgressBar playerHealthBar;
        sfui::ProgressBar dodgeCooldownTimeBar;

        bool isBegin{false}, isEnd{false};

        sfui::TimeInterval t;

        sfui::TimeInterval timeInterval;
        double deltaTime = 0;
    public:
        explicit MainMenuPage(sfui::Window *p_window)
            : Page(p_window), word(0, 0),
              textBox(400, 300, 100, sf::Color::White,
                      R"(assets/ttf/zh-cn.ttf)",
                      L"F11 全屏\n B 开始\n 空格 冲刺\n 数字 切换武器"),
              player(0, 0.f, 50.f, 50.f, 100, 100),

              boss(500, 0, 100, 100, 10000),
              bossUpdate(boss.update(deltaTime,barrage, myBarrage, player)),
              playerUpdate(player.update(m_mouse, myBarrage, barrage, boss)),
              bossHealthBar(800, 50, 800, 30, 10000, 10000, sf::Color::White, sf::Color::Red),
              playerHealthBar(100, 30, 150, 20, 100, 100, sf::Color::White, sf::Color::Red),
              dodgeCooldownTimeBar(75, 60, 100, 15, 3, 3, sf::Color::White, sf::Color::Blue) {
        }

        // 初始化界面元素
        void init() override {
            m_ratio = 0.5;

            activeMap(sfui::Key::W, [&]() { player.moveUp(deltaTime); });
            activeMap(sfui::Key::S, [&]() { player.moveDown(deltaTime); });
            activeMap(sfui::Key::A, [&]() { player.moveLift(deltaTime); });
            activeMap(sfui::Key::D, [&]() { player.moveRight(deltaTime); });
            activeMap(sfui::Key::Space, [&]() { player.dodge(); });
            activeMap(sfui::Key::B, [&]() {
                textBox.setTestString(L"");
                t.reset();
                isBegin = true;
            });
            activeMap(sfui::Key::Num1, [&]() { player.setNowItemIndex(0); });
            activeMap(sfui::Key::Num2, [&]() { player.setNowItemIndex(1); });
        }


        void updateByMessage() override {
            //inputBox.run(mp_window->getEvent());
        }


        void update() override {

            deltaTime = static_cast<double>(t.elapsedUs())/1'000'000.0;
            t.reset();
            barrage.m_dt = deltaTime;
            myBarrage.m_dt = deltaTime;

            word.load();

            word.setPosition(player.getX() / 32 / 32 - (player.getX() >= 0 ? 0 : 1),
                             player.getY() / 32 / 32 - (player.getY() >= 0 ? 0 : 1));
            bossHealthBar.setX(static_cast<float>(getSfRenderWindow().getSize().x) / 2);
            dodgeCooldownTimeBar.updateCurrentValue(player.getDodgeCooldownTime());
            playerUpdate.resume();
            barrage.run();
            myBarrage.run();
            bossHealthBar.updateCurrentValue(boss.getHealth());
            playerHealthBar.updateCurrentValue(player.getHealth());
            if (isBegin && !isEnd) {
                boss.turnTo(player.getX(), player.getY());
                bossUpdate.resume();


                if (isCollide(player.getHitbox(), boss.getHitbox())) {
                    player.changeHealth(-1);
                }

                if (boss.getHealth() <= 0 || player.getHealth() <= 0) {
                    std::wstringstream wss;
                    wss << (boss.getHealth() > 0 ? std::wstring(L"失败\n") : std::wstring(L"成功\n"));
                    wss << L"用时:" << t.elapsedMs() / 1000 << "s\n";
                    wss << L"剩余血量:" << player.getHealth() << "\n";
                    textBox.setTestString(std::wstring(wss.str()));
                    isEnd = true;
                }
            }
            setViewCenter(player.getX(), player.getY());
        }

        // 渲染页面内容到窗口
        void render() override {
            const auto view = getWorldView();

            // 计算视图范围
            const sf::FloatRect rect(
                view.getCenter().x - view.getSize().x / 2.f,
                view.getCenter().y - view.getSize().y / 2.f,
                view.getSize().x,
                view.getSize().y
            );

            // 对齐到50像素的倍数
            constexpr float gridSize = 100.f;
            const float startX = std::floor(rect.left / gridSize) * gridSize;
            const float startY = std::floor(rect.top / gridSize) * gridSize;

            // 用 VertexArray 一次性画所有线
            sf::VertexArray lines(sf::Lines);

            const sf::Color color(0, 35, 35);
            // 竖线
            for (float x = startX; x < rect.left + rect.width; x += gridSize) {
                lines.append(sf::Vertex(sf::Vector2f(x, rect.top), color));
                lines.append(sf::Vertex(sf::Vector2f(x, rect.top + rect.height), color));
            }

            // 横线
            for (float y = startY; y < rect.top + rect.height; y += gridSize) {
                lines.append(sf::Vertex(sf::Vector2f(rect.left, y), color));
                lines.append(sf::Vertex(sf::Vector2f(rect.left + rect.width, y), color));
            }

            getSfRenderWindow().draw(lines);


            drawForView(
                //word,
                player,
                boss,
                barrage,
                myBarrage
            );
            drawForWindow(
                bossHealthBar,
                playerHealthBar,
                dodgeCooldownTimeBar,
                textBox
            );
        }
    };
}
