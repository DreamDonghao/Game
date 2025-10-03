//
// Created by donghao on 25-8-12.
//
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <SFML/Graphics.hpp>

namespace sfui {
    class Rectangle {
    public:
        Rectangle (const float x, const float y, const float width, const float height, const sf::Color fillColor, const sf::Color outlineColor)
            :m_width(width),m_height(height),m_x(x),m_y(y),m_fillColor(fillColor),m_outlineColor(outlineColor) {
            m_sf_rectangle.setSize({m_width,m_height});
            m_sf_rectangle.setPosition(m_x-m_width/2,m_y-m_height/2);
        }

        void setPosition(const float x, const float y) {
            m_x = x;
            m_y = y;
            m_sf_rectangle.setSize({m_width,m_height});
            m_sf_rectangle.setPosition(m_x-m_width/2,m_y-m_height/2);
        }

        void setSize(const float width, const float height) {
            m_width = width;
            m_height = height;
            m_sf_rectangle.setSize({m_width,m_height});
            m_sf_rectangle.setPosition(m_x-m_width/2,m_y-m_height/2);
        }


        void draw(sf::RenderWindow &window)const {
            m_sf_rectangle.setFillColor(m_fillColor);
            m_sf_rectangle.setOutlineColor(m_outlineColor);
            m_sf_rectangle.setOutlineThickness(3);
            window.draw(m_sf_rectangle);
        }
        mutable sf::RectangleShape m_sf_rectangle;
    private:
        float m_width;
        float m_height;
        float m_x;
        float m_y;
        sf::Color m_fillColor{};
        sf::Color m_outlineColor{};
    };
} // sfui

#endif //RECTANGLE_HPP
