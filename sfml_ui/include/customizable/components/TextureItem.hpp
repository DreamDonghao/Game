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

        // ��ʼ��
        bool init(const FilePath &filepath = "images/unspecified.png",
            const int &width = 0, const int &height = 0,
            const float &x = 0, const float &y = 0
        );

        //������ʾ���
        void setShowWidth(const int &width);

        //������ʾ�߶�
        void setShowHeight(const int &height);

        // ������ʾ��С
        void setShowSize(const int width, const int &height);

        // ���� X ����
        void setX(const float &x);

        // ���� Y ����
        void setY(const float &y);

        //����λ��
        void setPosition(const float &x, const float &y);

        //��ȡ��ʾ���
        const float getShowWidth() const;

        //��ȡ��ʾ�߶�
        const float getShowHidth() const;

        //��ȡ������
        const int getTextureWidth() const;

        //��ȡ����߶�
        const int getTextureHeight() const;

        //��ȡX����
        const float getX() const;

        //��ȡY����
        const float getY() const;

        //��ȡ��������
        const sf::Sprite &getSprite() const;

    private:
        sf::Texture m_sf_texture;
        sf::Sprite m_sf_sprite;
    };
}