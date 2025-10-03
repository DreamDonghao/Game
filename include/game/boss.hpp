//
// Created by donghao on 25-7-2.
//
#ifndef BOSS_HPP
#define BOSS_HPP
#include "hitbox.hpp"
#include <co.hpp>
#include <tool.hpp>
#include <angle.hpp>


#include "bullet.hpp"
#include "button.hpp"
#include "Circle.hpp"


namespace game {

    class Boss {
    public:
        virtual ~Boss() = default;

        Boss(const float x, const float y, const float hitboxWidth, const float hitboxHeight, const double health)
            : m_x(x), m_y(y), m_hitbox(x, y, hitboxWidth, hitboxHeight), m_health(health) {
        }

        void move(double dt);

        const Hitbox &getHitbox() const {
            return m_hitbox;
        }

        float getX() const;

        float getY() const;

        void setX(float x);

        void setY(float y);

        float getSpeed() const {
            return m_speed;
        }

        void setSpeed(const float speed) {
            m_speed = speed;
        }

        void turnTo(float x, float y);

        void setMoveAngle(double angle);

        sfui::Angle getMoveAngle() const {
            return m_moveAngle;
        }

        double getHealth() const {
            return m_health;
        }

        void setHealth(const double health) {
            m_health = health;
        }

        void changeHealth(const double health) {
            m_health += health;
        }

        virtual sfui::Task<void> update(const double &dt,Barrage &barrage, float &playerX, float &playerY) {
            while (m_health > 0) {
                while (distance(m_x, m_y, playerX, playerY) < 1000) {
                    move(dt);
                    co_await std::suspend_always{};
                }
                while (distance(m_x, m_y, playerX, playerY) >= 1000) {
                    co_await std::suspend_always{};
                }
            }
            co_return;
        }

        virtual void draw(sf::RenderWindow &window) {

        }

    private:
        float m_x;
        float m_y;
        float m_speed{10000};
        sfui::Angle m_moveAngle{0};
        Hitbox m_hitbox;
        std::chrono::microseconds m_overTime{0};
        double m_health;
        int state{0};
    };
} // game

#endif //BOSS_HPP
