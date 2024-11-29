#pragma once 
#include <SFML/Graphics.hpp>
namespace sfui {
    using FilePath = std::string;
    class TextureItem {
    public:
        TextureItem();

        TextureItem(TextureItem &&other) noexcept;

        TextureItem &operator=(TextureItem &&other) noexcept;

        TextureItem(const TextureItem &other);

        // 初始化
        bool init(const FilePath &filepath = "images/unspecified.png",
            const int &width = 0, const int &height = 0,
            const float &x = 0, const float &y = 0
        );

        //设置显示宽度
        void setShowWidth(const int &width);

        //设置显示高度
        void setShowHeight(const int &height);

        // 设置显示大小
        void setShowSize(const int width, const int &height);

        // 设置 X 坐标
        void setX(const float &x);

        // 设置 Y 坐标
        void setY(const float &y);

        //设置位置
        void setPosition(const float &x, const float &y);

        //获取显示宽度
        const float getShowWidth() const;

        //获取显示高度
        const float getShowHidth() const;

        //获取纹理宽度
        const int getTextureWidth() const;

        //获取纹理高度
        const int getTextureHeight() const;

        //获取X坐标
        const float getX() const;

        //获取Y坐标
        const float getY() const;

        //获取加载内容
        const sf::Sprite &getSprite() const;

    private:
        sf::Texture m_sf_texture;
        sf::Sprite m_sf_sprite;
    };
}