//
// Created by donghao on 25-7-2.
//
#ifndef HITBOX_HPP
#define HITBOX_HPP

#include <SFML/Graphics.hpp>

namespace game {
    class Hitbox {
        friend bool isCollide(const Hitbox &a, const Hitbox &b);

    public:
        Hitbox(const float x, const float y, const float width, const float height)
            : m_x(x), m_y(y), m_width(width), m_height(height) {
        };

        void setPosition(const float x, const float y) {
            m_x = x;
            m_y = y;
        }

        void setX(const float x) {
            m_x = x;
        }

        void setY(const float y) {
            m_y = y;
        }

        void moveX(const float x) {
            m_x += x;
        }

        void moveY(const float y) {
            m_y += y;
        }

        void move(float x, float y) {
            m_x += x;
            m_y += y;
        }
        void setWidth(const float width) {
            m_width = width;
        }

        void setHeight(const float height) {
            m_height = height;
        }

        [[nodiscard]] float getX() const {
            return m_x;
        }

        [[nodiscard]] float getY() const {
            return m_y;
        }

        [[nodiscard]] float getWidth() const {
            return m_width;
        }

        [[nodiscard]] float getHeight() const {
            return m_height;
        }

        void draw(sf::RenderWindow &window) const{
            border[0].position = sf::Vector2f(m_x - m_width / 2, m_y - m_height / 2);
            border[1].position = sf::Vector2f(m_x + m_width / 2, m_y - m_height / 2);
            border[2].position = sf::Vector2f(m_x + m_width / 2, m_y + m_height / 2);
            border[3].position = sf::Vector2f(m_x - m_width / 2, m_y + m_height / 2);
            border[4].position = sf::Vector2f(m_x - m_width / 2, m_y - m_height / 2);
            for (int i = 0; i < 5; ++i) {
                border[i].color = sf::Color::Green;
            }
            window.draw(border);
        }

    private:
        float m_x;
        float m_y;
        float m_width;
        float m_height;
        mutable sf::VertexArray border{sf::LineStrip, 5};
    };

    inline bool isCollide(const Hitbox &a, const Hitbox &b) {
        const float aLeft = a.m_x - a.m_width / 2;
        const float aTop = a.m_y - a.m_height / 2;
        const float aRight = a.m_x + a.m_width / 2;
        const float aBottom = a.m_y + a.m_height / 2;

        // 计算 b 的边界
        const float bLeft = b.m_x - b.m_width / 2;
        const float bTop = b.m_y - b.m_height / 2;
        const float bRight = b.m_x + b.m_width / 2;
        const float bBottom = b.m_y + b.m_height / 2;

        // 检测碰撞：两轴均无间隙时返回 true
        return (aRight > bLeft) && (aLeft < bRight) &&
               (aBottom > bTop) && (aTop < bBottom);
    }
} // game

#endif //HITBOX_HPP
