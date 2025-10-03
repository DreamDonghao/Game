//
// Created by donghao on 25-7-1.
//
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <hitbox.hpp>
//#include <timepiece.hpp>


namespace game {
    class Player {
    public:
        /**
        * @brief 构造函数，T 为 void 时调用
        *
        * @param x 玩家初始横坐标
        * @param y 玩家初始纵坐标
        * @param hitboxWidth 碰撞盒宽度
        * @param hitboxHeight 碰撞盒高度
        * @param speed 玩家移动速度
        * @param health 玩家生命值
        */
        Player(const float x, const float y, const float hitboxWidth, const float hitboxHeight,
               const float speed, const double health)
            : m_x(x), m_y(y), m_hitbox(x, y, hitboxWidth, hitboxHeight), m_speed(speed), m_health(health) {
        }


        virtual ~Player() = default;

        void setX(const float x) {
            m_x = x;
            m_hitbox.setPosition(m_x, m_y);
        }

        void setY(const float y) {
            m_y = y;
            m_hitbox.setPosition(m_x, m_y);
        }

        void setSpeed(const float speed) {
            m_speed = speed;
        }

        void moveX(const float x) {
            m_x += x;
            m_hitbox.setPosition(m_x, m_y);
        }

        void moveY(const float y) {
            m_y += y;
            m_hitbox.setPosition(m_x, m_y);
        }

        void moveLift(const double dt) {
            m_x -= m_speed * static_cast<float>(dt);
            //m_time.reset();
            m_hitbox.setPosition(m_x, m_y);
        }

        void moveUp(const double dt) {
            m_y -= m_speed * static_cast<float>(dt);
            //m_time.reset();
            m_hitbox.setPosition(m_x, m_y);
        }

        void moveRight(const double dt) {
            m_x += m_speed * static_cast<float>(dt);
            //m_time.reset();
            m_hitbox.setPosition(m_x, m_y);
        }

        void moveDown(const double dt) {
            std::cout<<dt<<std::endl;
            m_y += m_speed * static_cast<float>(dt);
            //m_time.reset();
            m_hitbox.setPosition(m_x, m_y);
        }

        [[nodiscard]] float getX() const {
            return m_x;
        }

        [[nodiscard]] float getY() const {
            return m_y;
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

        virtual void draw(sf::RenderWindow &window) = 0;

    private:
        //sfui::TimeInterval m_time;
        float m_x;
        float m_y;
        Hitbox m_hitbox;
        float m_speed;

        double m_health;
    };
} // game

#endif //PLAYER_HPP
