//
// Created by donghao on 25-6-8.
//

#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <filesystem>
#include <SFML/Graphics.hpp>

namespace sfui {
    class TextBox {
    public:
        TextBox(const double x, const double y, unsigned int testSize,
                const sf::Color testColor, const std::filesystem::path &fontPath,
                std::string textString)
            : m_x(x), m_y(y), m_textString(std::move(textString)),
              m_textColor(testColor), m_textSize(std::move(testSize)) {
            m_font.loadFromFile(fontPath.string());
            m_text.setFont(m_font);
            m_text.setString(m_textString);
            m_text.setCharacterSize(m_textSize);
            m_text.setFillColor(m_textColor);
            m_text.setPosition(m_x, m_y);
        }

        void init(const std::filesystem::path &fontPath) {
            m_font.loadFromFile(fontPath.string());
            m_text.setFont(m_font);
            m_text.setString(m_textString);
            m_text.setCharacterSize(m_textSize);
            m_text.setFillColor(m_textColor);
            m_text.setPosition(m_x, m_y);
        }

        void setTestString(std::string testString) {
            m_textString = std::move(testString);
        }

        const sf::Text &getSprite() const {
            return m_text;
        }

    private:
        sf::Text m_text;
        sf::Font m_font;
        double m_x = 0;
        double m_y = 0;
        std::string m_textString;
        sf::Color m_textColor;
        unsigned int m_textSize = 0;
    };
}


#endif //TEXTBOX_H
