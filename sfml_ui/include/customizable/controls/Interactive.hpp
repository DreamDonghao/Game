#pragma once
#include <print>
namespace sfui {

    class Interactive {
    public:
        Interactive() :m_area(), m_textureItem() {}
        bool init(const float &x, const float &y, const int &width, const int &heigth, FilePath filepath) {
            m_x = x;
            m_y = y;
            m_width = width;
            m_height = heigth;
            m_textureItem.init(filepath, m_width, m_height, m_x, m_y);
            return true;
        }
        //获取按钮区域
        Area *const getArea() {
            return &m_area;

        }
        void updateArea(const float x, const float y, const unsigned width, const unsigned height) {
            m_area.init(
                m_x - x + width / 2,
                m_y - y + height / 2,
                m_x - x + m_width + width / 2,
                m_y - y + m_height + height / 2
            );
        }
        const sf::Sprite &getSprite()const {
            return m_textureItem.getSprite();
        }
    private:
        float m_x = 0.0;
        float m_y = 0.0;
        int m_width = 0;
        int m_height = 0;
        Area m_area;
        sf::RenderWindow *m_sf_window_p = nullptr;

        TextureItem m_textureItem;
    };

}