//
// Created by donghao on 25-6-8.
//

#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP
#include <textbox.hpp>
#include <area.hpp>
#include <iostream>
#include <print>

namespace sfui {
    class InputBox {
    public:
        InputBox(Mouse &mouse, int x, int y, int width, int height)
            : m_x(x), m_y(y), m_width(width), m_height(height), m_textbox(
                  m_x, m_y, 20, sf::Color::Black,
                  R"(C:\Users\donghao\AppData\Local\Programs\cursor\resources\app\out\media\jetbrains-mono-regular.ttf)",
                  "hello)"), m_inputArea(x, y, x + width, y + height), m_mouse(mouse) {
        }


        void run(const sf::Event &event) {
            if (m_mouse.isLeftPressed()) {
                std::println("isLeftPressed");
                std::println("{}   {}", m_mouse.getWindowPosition().x, m_mouse.getWindowPosition().y);
                if (m_inputArea.isInArea(m_mouse.getWindowPosition().x, m_mouse.getWindowPosition().y)) {
                    isActive = true;
                    std::println("isActive");
                } else {
                    isActive = false;
                }
            }
            if (isActive) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode == 8 && cursorPosition > 0) {
                        m_text.pop_back();
                        cursorPosition--;
                    } else if (event.text.unicode < 128) {
                        m_text += static_cast<char>(event.text.unicode);
                        cursorPosition += 1;
                        std::println("{}", 1);

                    }
                } else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Delete && cursorPosition < m_text.length()) {
                        m_text.erase(m_text.begin() + cursorPosition, m_text.begin() + cursorPosition + 1);
                    } else if (event.key.code == sf::Keyboard::Left && cursorPosition > 0) {
                        cursorPosition -= 1;
                    } else if (event.key.code == sf::Keyboard::Right && cursorPosition <= m_text.length()) {
                        cursorPosition += 1;
                    }
                }
                m_textbox.setTestString(m_text);
            }
        }

        const sfui::Area &getArea() const { return m_inputArea; }

        const sf::Text &getSpring() const {
            std::cout << "2" << m_textbox.getText()<<std::endl;
            return m_textbox.getSprite();
        }

    private:
        int m_x;
        int m_y;
        int m_width;
        int m_height;
        bool isActive = false;
        std::string m_text;
        TextBox m_textbox;
        Area m_inputArea;
        std::size_t cursorPosition = 0;
        std::string cursorStyle = "|";
        Mouse &m_mouse;
    };
}


#endif //INPUTBOX_HPP
