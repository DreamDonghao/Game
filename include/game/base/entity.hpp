//
// Created by donghao on 25-10-3.
//
#ifndef GAME_HPP
#define GAME_HPP
#include "angle.hpp"
#include "hitbox.hpp"

namespace game {
    class Entity{
    public:
        Entity():Entity(0,0,0.0f,0.0f,0.0f,sfui::Angle(0.0),0){}

        Entity(const float x, const float y, const float hitboxWidth, const float hitboxHeight,
               const float speed, const sfui::Angle moveAngle, const double health)
            : m_hitbox(x, y, hitboxWidth, hitboxHeight), m_speed(speed),
              m_moveAngle(moveAngle), m_health(health) {
        }

        virtual ~Entity() = default;

        void setX(const float x) {
            m_hitbox.setX(x);
        }

        void setY(const float y) {
            m_hitbox.setY(y);
        }

        void setSpeed(const float speed) {
            m_speed = speed;
        }

        void moveX(const float x) {
            m_hitbox.moveX(x);
        }

        void moveY(const float y) {
            m_hitbox.moveY(y);
        }

        void setMoveAngle(const float angle) {
            m_moveAngle.setAngle(angle);
        }

        virtual void updateMovement(const float dt) {
            m_hitbox.moveX(m_speed*dt*static_cast<float>(m_moveAngle.getCos()));

            m_hitbox.moveY(m_speed*dt*static_cast<float>(m_moveAngle.getSin()));
        }

        [[nodiscard]] float getX() const {
            return m_hitbox.getX();
        }

        [[nodiscard]] float getY() const {
            return m_hitbox.getY();
        }

        void setHealth(const float health) {
            m_health = health;
        }

        void changeHealth(const double health) {
            m_health += health;
        }

        [[nodiscard]] double getHealth() const {
            return m_health;
        }

        [[nodiscard]] Hitbox &getHitbox() {
            return m_hitbox;
        }

        bool isAlive() const {
            if (m_health <= 0) {
                return false;
            }else {
                return true;
            }
        }

    private:
        Hitbox m_hitbox;
        float m_speed;
        sfui::Angle m_moveAngle;
        double m_health;
    };
} // entity

#endif //GAME_HPP
