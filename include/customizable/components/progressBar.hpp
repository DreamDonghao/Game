//
// Created by donghao on 25-8-22.
//
#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP
#include <SFML/Window.hpp>

#include "SFML/Graphics/RenderWindow.hpp"
#include <Rectangle.hpp>

namespace sfui {
    class ProgressBar {
    public:
        ProgressBar(const float x, const float y, const float width, const float height,
                    const double maxValue, const double currentValue,
                    const sf::Color backgroundColor, const sf::Color barColor)
            : m_x(x), m_y(y), m_width(width), m_height(height),
              m_maxValue(maxValue), m_currentValue(currentValue),
              m_backgroundColor(backgroundColor), m_barColor(barColor) {
        }

        virtual ~ProgressBar() = default;

        void setX(const float x) {
            m_x = x;
        }

        void setY(const float y) {
            m_y = y;
        }

        void updateCurrentValue(const double currentValue) {
            if (currentValue < m_maxValue) {
                m_currentValue = currentValue;
            } else {
                m_currentValue = m_maxValue;
            }
            if (m_currentValue < 0) {
                m_currentValue = 0;
            }
        }

        [[nodiscard]] double getProgress() const {
            return m_currentValue / m_maxValue;
        }

        [[nodiscard]] double getCurrentValue() const {
            return m_currentValue;
        }

        void setMaxValue(const double maxValue) {
            m_maxValue = maxValue;
        }

        [[nodiscard]] double getMaxValue() const {
            return m_maxValue;
        }

        virtual void draw(sf::RenderWindow &window) {
            const Rectangle back(
                m_x, m_y,
                m_width, m_height,
                m_backgroundColor, m_backgroundColor
            );

            back.draw(window);
            if (m_currentValue > 0) {
                const double progress = getProgress();
                const Rectangle bar(
                    m_x - m_width / 2 + (m_width * static_cast<float>(progress)) / 2, // 左端固定，往右延伸
                    m_y,
                    m_width * static_cast<float>(progress), m_height,
                    m_barColor, m_barColor
                );

                bar.draw(window);
            }
        }

    private:
        float m_x;
        float m_y;
        float m_width;
        float m_height;
        double m_maxValue;
        double m_currentValue;
        sf::Color m_backgroundColor;
        sf::Color m_barColor;
    };
} // sfui

#endif //PROGRESSBAR_HPP
