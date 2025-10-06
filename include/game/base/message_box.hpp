//
// Created by donghao on 25-10-6.
//
#ifndef MESSAGE_BOX_HPP
#define MESSAGE_BOX_HPP
#include <string>

#include "textbox.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace game {
    class MessageBox {
    public:
        explicit MessageBox(const float x, const float y, std::string message = "")
            : m_textbox(x, y, 100, sf::Color::Red, "assets/ttf/zh-cn.ttf", message),
              m_message(std::move(message)) {
        }

        ~MessageBox() = default;

        void setMessage(const std::string& message) {
            m_message = message;
            m_textbox.setTestString(m_message);
        }

        void draw(sf::RenderWindow &window) const {

            m_textbox.draw(window);
        }

    private:
        sfui::TextBox m_textbox;

        std::string m_message;
        sf::Vector2f m_position;
    };
} // game

#endif //MESSAGE_BOX_HPP
