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

        //������ʾ���
        void setShowWidth(const int &width) {
            m_sf_sprite.setScale(double(width) / m_sf_texture.getSize().x,
                m_sf_sprite.getScale().y);
        }
        //������ʾ�߶�
        void setShowHeight(const int &height) {
            m_sf_sprite.setScale(m_sf_sprite.getScale().x,
                double(height) / m_sf_texture.getSize().y);
        }
        // ������ʾ��С
        void setShowSize(const int width, const int &height) {
            m_sf_sprite.setScale(double(width) / m_sf_texture.getSize().x,
                double(height) / m_sf_texture.getSize().y);
        }

        // ���� X ����
        void setX(const int &x) {
            m_sf_sprite.setPosition(x, m_sf_sprite.getPosition().y);
        }

        // ���� Y ����
        void setY(const int &y) {
            m_sf_sprite.setPosition(m_sf_sprite.getPosition().x, y);
        }

        //����λ��
        void setPosition(const int &x, const int &y) {
            m_sf_sprite.setPosition(x, y);
        }
        //��ȡ��ʾ���
        const int getShowWidth() const {
            return m_sf_sprite.getGlobalBounds().width;
        }
        //��ȡ��ʾ�߶�
        const int getShowHidth() const {
            return m_sf_sprite.getGlobalBounds().height;
        }
        //��ȡ������
        const float getTextureWidth() const {
            return m_sf_texture.getSize().x;
        }
        //��ȡ����߶�
        const float getTextureHeight() const {
            return m_sf_texture.getSize().y;
        }
        //��ȡX����
        const int getX() const {
            return m_sf_sprite.getPosition().x;
        }
        //��ȡY����
        const int getY() const {
            return m_sf_sprite.getPosition().y;
        }
        //��ȡ��������
        const sf::Sprite &getSprite() const  {
            return m_sf_sprite;
        }
        ~TextureItem() = default;

    private: 
        sf::Sprite m_sf_sprite;
        sf::Texture m_sf_texture;
    };


}