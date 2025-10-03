//
// Created by donghao on 25-6-8.
//

#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <filesystem>
#include <SFML/Graphics.hpp>

namespace sfui {
    /**
     * @brief 文本框控件，支持自定义字体、颜色、内容、位置等
     */
    class TextBox {
    public:
        /**
         * @brief 构造函数，初始化文本框的内容、字体、颜色、大小和位置
         * @param x 文本框左上角x坐标
         * @param y 文本框左上角y坐标
         * @param textSize 字体大小
         * @param testColor 字体颜色
         * @param fontPath 字体文件路径
         * @param textString 文本内容
         */
        TextBox(const float x, const float y, const unsigned int textSize,
                const sf::Color testColor, const std::filesystem::path &fontPath,
                sf::String textString)
            : m_x(x), m_y(y), m_textString(std::move(textString)),
              m_textColor(testColor), m_textSize(textSize) {
            m_font.loadFromFile(fontPath.string());
            m_text.setFont(m_font);
            m_text.setString(textString);
            m_text.setCharacterSize(m_textSize);
            m_text.setFillColor(m_textColor);
            m_text.setPosition(m_x, m_y);
        }

        /**
         * @brief 初始化字体和文本属性（可用于重新加载字体）
         * @param fontPath 字体文件路径
         */
        void init(const std::filesystem::path &fontPath) {
            m_font.loadFromFile(fontPath.string());
            m_text.setFont(m_font);
            m_text.setString(m_textString);
            m_text.setCharacterSize(m_textSize);
            m_text.setFillColor(m_textColor);
            m_text.setPosition(m_x, m_y);
        }

        /**
         * @brief 设置字体
         * @param fontPath 字体文件路径
         */
        void setFont(const std::filesystem::path &fontPath) {
            m_font.loadFromFile(fontPath.string());
            m_text.setFont(m_font);
        }

        /**
         * @brief 设置字体大小
         * @param testSize 字体大小
         */
        void setTestSize(const unsigned int testSize) {
            m_textSize = testSize;
            m_text.setCharacterSize(m_textSize);
        }

        /**
         * @brief 设置文本内容
         * @param textString 新的文本内容
         */
        void setTestString(const sf::String &textString) {
            m_textString = std::move(textString);
            m_text.setString(textString);
        }

        /**
         * @brief 设置文本颜色
         * @param testColor 新的颜色
         */
        void setTestColor(const sf::Color testColor) {
            m_textColor = testColor;
            m_text.setFillColor(m_textColor);
        }

        /**
         * @brief 设置文本框位置
         * @param x 新的x坐标
         * @param y 新的y坐标
         */
        void setPosition(const float x, const float y) {
            m_x = x;
            m_y = y;
            m_text.setPosition(m_y, m_y);
        }

        std::string getText() const { return m_text.getString(); }

        /**
         * @brief 获取SFML文本对象（用于绘制）
         * @return SFML的Text对象引用
         */
        const sf::Text &getSprite() const {
            return m_text;
        }


        void draw(sf::RenderWindow &window) const {
            window.draw(m_text);
        }

    private:
        sf::Text m_text;             ///< SFML文本对象
        sf::Font m_font;             ///< 字体对象
        float m_x = 0;               ///< 文本框x坐标
        float m_y = 0;               ///< 文本框y坐标
        std::string m_textString;    ///< 文本内容
        sf::Color m_textColor;       ///< 文本颜色
        unsigned int m_textSize = 0; ///< 字体大小
    };
}


#endif //TEXTBOX_H
