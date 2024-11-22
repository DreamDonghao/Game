#pragma once 
#include <SFML/Graphics.hpp>
namespace sfui {
    using FilePath = std::string;
    class TextureItem {
    public:
        TextureItem() {}

        
        TextureItem(TextureItem &&other) noexcept
            : m_sf_sprite(std::move(other.m_sf_sprite)),
            m_sf_texture(std::move(other.m_sf_texture)) {
            
            m_sf_sprite.setTexture(m_sf_texture);
        }

        
        TextureItem &operator=(TextureItem &&other) noexcept {
            if (this != &other) {
                m_sf_sprite = std::move(other.m_sf_sprite);
                m_sf_texture = std::move(other.m_sf_texture);
                
                m_sf_sprite.setTexture(m_sf_texture);
            }
            return *this;
        }


        bool init(const FilePath &filepath = "images/unspecified.png",
            const int &width = 0, const int &height = 0,
            const int &x = 0, const int &y = 0) {
            if (!m_sf_texture.loadFromFile(filepath)) {
                return false;
            }
            m_sf_sprite.setTexture(m_sf_texture);
            m_sf_sprite.setPosition(x, y);
            m_sf_sprite.setScale(double(width) / m_sf_texture.getSize().x,
                double(height) / m_sf_texture.getSize().y);
            return true;
        }

        //设置显示宽度
        void setShowWidth(const int &width) {
            m_sf_sprite.setScale(double(width) / m_sf_texture.getSize().x,
                m_sf_sprite.getScale().y);
        }
        //设置显示高度
        void setShowHeight(const int &height) {
            m_sf_sprite.setScale(m_sf_sprite.getScale().x,
                double(height) / m_sf_texture.getSize().y);
        }
        // 设置显示大小
        void setShowSize(const int width, const int &height) {
            m_sf_sprite.setScale(double(width) / m_sf_texture.getSize().x,
                double(height) / m_sf_texture.getSize().y);
        }

        // 设置 X 坐标
        void setX(const int &x) {
            m_sf_sprite.setPosition(x, m_sf_sprite.getPosition().y);
        }

        // 设置 Y 坐标
        void setY(const int &y) {
            m_sf_sprite.setPosition(m_sf_sprite.getPosition().x, y);
        }

        //设置位置
        void setPosition(const int &x, const int &y) {
            m_sf_sprite.setPosition(x, y);
        }
        //获取显示宽度
        const int getShowWidth() const {
            return m_sf_sprite.getGlobalBounds().width;
        }
        //获取显示高度
        const int getShowHidth() const {
            return m_sf_sprite.getGlobalBounds().height;
        }
        //获取纹理宽度
        const float getTextureWidth() const {
            return m_sf_texture.getSize().x;
        }
        //获取纹理高度
        const float getTextureHeight() const {
            return m_sf_texture.getSize().y;
        }
        //获取X坐标
        const int getX() const {
            return m_sf_sprite.getPosition().x;
        }
        //获取Y坐标
        const int getY() const {
            return m_sf_sprite.getPosition().y;
        }
        //获取加载内容
        const sf::Sprite &getSprite() const  {
            return m_sf_sprite;
        }
        ~TextureItem() = default;

    private: 
        sf::Sprite m_sf_sprite;
        sf::Texture m_sf_texture;
    };


}