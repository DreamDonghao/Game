#pragma once

#include <TextureItem.hpp>
#include <Area.hpp>

namespace sfui {
    /**
     * @brief 按钮类，封装贴图和区域
     */
    class Button {
    public:
        /**
         * @brief 默认构造函数
         */
        Button() : m_area(0,0,0,0) {}

        /**
         * @brief 析构函数
         */
        ~Button() = default;

        /**
         * @brief 初始化按钮
         * @param x 按钮左上角x坐标
         * @param y 按钮左上角y坐标
         * @param width 按钮宽度
         * @param heigth 按钮高度
         * @param filepath 按钮图片路径
         * @return 是否初始化成功
         */
        bool init(const float &x, const float &y, const int &width, const int &heigth,
                  const FilePath &filepath) {
            m_x = x;
            m_y = y;
            m_width = width;
            m_height = heigth;
            m_textureItem.init(filepath, m_width, m_height, m_x, m_y);
            m_area.init(
                    m_x, m_y,
                    m_x + static_cast<float>( m_width), m_y +static_cast<float> (m_height)
            );

            return true;
        }

        /**
         * @brief 获取按钮区域
         * @return 区域指针
         */
        Area *getArea() {
            return &m_area;
        }

        /**
         * @brief 获取按钮的Sprite
         * @return SFML Sprite对象引用
         */
        const sf::Sprite &getSprite() const {
            return m_textureItem.getSprite();
        }

    protected:
        float m_x = 0.0; ///< 按钮左上角x坐标
        float m_y = 0.0; ///< 按钮左上角y坐标
        int m_width = 0; ///< 按钮宽度
        int m_height = 0; ///< 按钮高度
        Area m_area; ///< 按钮区域
        TextureItem m_textureItem; ///< 按钮贴图
    };

}
