//
// Created by donghao on 25-6-28.
//
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace sfui {
    class Circle {
    public:
        Circle():Circle(0,0,3,sf::Color::Red){}

        Circle(const float x, const float y, const float radius, const sf::Color fillColor)
            : m_x(x), m_y(y), m_radius(radius), m_fillColor(fillColor) {
            m_sf_circle.setPosition(x - radius, y - radius);
            m_sf_circle.setRadius(radius);
            m_sf_circle.setFillColor(fillColor);
        }

        void setPosition(const float x, const float y) {
            m_x = x;
            m_y = y;
            m_sf_circle.setPosition(m_x - m_radius , m_y - m_radius );
        }

        void setX(const float x) {
            m_x = x;
            m_sf_circle.setPosition(m_x - m_radius , m_y - m_radius );
        }

        void setY(const float y) {
            m_y = y;
            m_sf_circle.setPosition(m_x - m_radius , m_y - m_radius );
        }

        void moveX(const float x) {
            m_x += x;
            m_sf_circle.setPosition(m_x - m_radius , m_y - m_radius );
        }

        void moveY(const float y) {
            m_y += y;
            m_sf_circle.setPosition(m_x - m_radius , m_y - m_radius );
        }

        void setRadius(const float radius) {
            m_radius = radius;
            m_sf_circle.setRadius(radius);
            setPosition(m_x, m_y);
        }

        float getRadius() const { return m_radius; }
        float getX() const { return m_x; }
        float getY() const { return m_y; }


        void draw(sf::RenderWindow &renderWindow) const {
            renderWindow.draw(m_sf_circle);
        }

    private:
        sf::CircleShape m_sf_circle;
        float m_x;
        float m_y;
        float m_radius;
        float m_outlineWidth{};
        sf::Color m_fillColor;
        sf::Color m_outlineColor;
        float pointCount{};
    };
}

#endif //CIRCLE_HPP
