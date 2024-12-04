#pragma once
#include <TextureItem.hpp>
#include <Area.hpp>
namespace sfui {
    // 按钮
    class Button {
    public:
        // 按钮的区域


        Button():m_area() {}

        ~Button() {}

        // 初始化
        bool init(const float &x, const float &y, const int &width, const int &heigth, FilePath filepath) {
            m_x = x;
            m_y = y;
            m_width = width;
            m_height = heigth;
            m_textureItem.init(filepath, m_width, m_height, m_x, m_y);
            m_area.init(m_x,m_y,
                m_x + m_width,m_x + m_height);
            return true;
        }

        //获取按钮区域
        Area *const getArea() {
            return &m_area;
        }
        const sf::Sprite &getSprite()const {
            return m_textureItem.getSprite();
        }

    protected:
        float m_x = 0.0;
        float m_y = 0.0;
        int m_width = 0;
        int m_height = 0;
        Area m_area;
        

        TextureItem m_textureItem;
    };

}