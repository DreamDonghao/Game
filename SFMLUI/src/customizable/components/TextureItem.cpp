#include <TextureItem.hpp>

namespace sfui {

    TextureItem::TextureItem() {}


    TextureItem::TextureItem(TextureItem &&other) noexcept
        : m_sf_sprite(std::move(other.m_sf_sprite)),
        m_sf_texture(std::move(other.m_sf_texture)) {

        m_sf_sprite.setTexture(m_sf_texture);
    }


    TextureItem &TextureItem::operator=(TextureItem &&other) noexcept {
        if (this != &other) {
            m_sf_sprite = std::move(other.m_sf_sprite);
            m_sf_texture = std::move(other.m_sf_texture);

            m_sf_sprite.setTexture(m_sf_texture);
        }
        return *this;
    }

    TextureItem::TextureItem(const TextureItem &other)
        :m_sf_sprite(other.m_sf_sprite), m_sf_texture(other.m_sf_texture) {

    }


    bool TextureItem::init(const FilePath &filepath,
        const int &width, const int &height ,
        const float &x, const float &y) {
        if (!m_sf_texture.loadFromFile(filepath)) {
            return false;
        }
        m_sf_sprite.setTexture(m_sf_texture);
        m_sf_sprite.setPosition(x, y);
        m_sf_sprite.setScale(float(width) / m_sf_texture.getSize().x,
            float(height) / m_sf_texture.getSize().y);
        return true;
    }

    //������ʾ���
    void TextureItem::setShowWidth(const int &width) {
        m_sf_sprite.setScale(float(width) / m_sf_texture.getSize().x,
            m_sf_sprite.getScale().y);
    }
    //������ʾ�߶�
    void TextureItem::setShowHeight(const int &height) {
        m_sf_sprite.setScale(m_sf_sprite.getScale().x,
            float(height) / m_sf_texture.getSize().y);
    }
    // ������ʾ��С
    void TextureItem::setShowSize(const int width, const int &height) {
        m_sf_sprite.setScale(float(width) / m_sf_texture.getSize().x,
            float(height) / m_sf_texture.getSize().y);
    }

    // ���� X ����
    void TextureItem::setX(const float &x) {
        m_sf_sprite.setPosition(x, m_sf_sprite.getPosition().y);
    }

    // ���� Y ����
    void TextureItem::setY(const float &y) {
        m_sf_sprite.setPosition(m_sf_sprite.getPosition().x, y);
    }

    //����λ��
    void TextureItem::setPosition(const float &x, const float &y) {
        m_sf_sprite.setPosition(x, y);
    }
    //��ȡ��ʾ���
    const float TextureItem::getShowWidth() const {
        return m_sf_sprite.getGlobalBounds().width;
    }
    //��ȡ��ʾ�߶�
    const float TextureItem::getShowHidth() const {
        return m_sf_sprite.getGlobalBounds().height;
    }
    //��ȡ������
    const int TextureItem::getTextureWidth() const {
        return m_sf_texture.getSize().x;
    }
    //��ȡ����߶�
    const int TextureItem::getTextureHeight() const {
        return m_sf_texture.getSize().y;
    }
    //��ȡX����
    const float TextureItem::getX() const {
        return m_sf_sprite.getPosition().x;
    }
    //��ȡY����
    const float TextureItem::getY() const {
        return m_sf_sprite.getPosition().y;
    }
    //��ȡ��������
    const sf::Sprite &TextureItem::getSprite() const {
        return m_sf_sprite;
    }
}