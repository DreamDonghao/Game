//
// Created by donghao on 25-7-1.
//
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <array>
#include "co.hpp"
#include <base/entity.hpp>
#include "Circle.hpp"
#include <test/testitems.hpp>
#include <Item_Inventory.hpp>

namespace game {
    class Player : public Entity {
    public:
        Player(const float x, const float y, const float hitboxWidth, const float hitboxHeight,
               const float speed, const float maxSpeed, const double health)
            : Entity(x, y, hitboxWidth, hitboxHeight, speed, sfui::Angle(0), health), m_maxSpeed(maxSpeed) {
        }

        ~Player() override = default;

        void moveLift() {
            m_moveFlags[Left] = true;
            setSpeed(m_maxSpeed);
        }

        void moveUp() {
            m_moveFlags[Up] = true;
            setSpeed(m_maxSpeed);
        }

        void moveRight() {
            m_moveFlags[Right] = true;
            setSpeed(m_maxSpeed);
        }

        void moveDown() {
            m_moveFlags[Down] = true;
            setSpeed(m_maxSpeed);
        }

        void turn() {
            sf::Vector2f dir{0.f, 0.f};
            if (m_moveFlags[Left]) {
                dir.x -= 1.f;
            }
            if (m_moveFlags[Right]) {
                dir.x += 1.f;
            }
            if (m_moveFlags[Up]) {
                dir.y -= 1.f;
            }
            if (m_moveFlags[Down]) {
                dir.y += 1.f;
            }

            if (dir.x != 0.f || dir.y != 0.f) {
                setMoveAngle(std::atan2(-dir.y, dir.x));
            }
        }

        void resetMoveStatu() {
            m_moveFlags.fill(false);
            setSpeed(0.0f);
        }

        void obtainItems(const std::string &name, int num) {
            const auto it =
                    std::ranges::find_if(
                        m_items, [&](auto &item) {
                            return item.first->getName() == name;
                        });

            if (it != m_items.end()) {
                it->second += num;
            } else {
                m_items.emplace_back(ItemFactory::instance().create(name), num);
            }
        }


        virtual sfui::Task update(const float &dt) {
            while (isAlive()) {
                m_itemInventory.printItemMessage();
                turn();
                updateMovement(dt);
                resetMoveStatu();
                co_await std::suspend_always{};
            }
            co_return;
        }

        virtual void draw(sf::RenderWindow &window) {
            circle.setPosition(getX(), getY());
            circle.setRadius(10);
            circle.draw(window);
        }

    private:
        sfui::Circle circle;

        enum Direction { Left = 0, Up = 1, Right = 2, Down = 3 };

        std::array<bool, 4> m_moveFlags{false, false, false, false};
        float m_maxSpeed;

        std::vector<std::pair<std::unique_ptr<Item>, int> > m_items;

        Item_Inventory m_itemInventory{&m_items};
    };
} // game

#endif //PLAYER_HPP
