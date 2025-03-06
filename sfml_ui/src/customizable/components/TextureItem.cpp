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

    //设置显示宽度
    void TextureItem::setShowWidth(const int &width) {
        m_sf_sprite.setScale(float(width) / m_sf_texture.getSize().x,
            m_sf_sprite.getScale().y);
    }
    //设置显示高度
    void TextureItem::setShowHeight(const int &height) {
        m_sf_sprite.setScale(m_sf_sprite.getScale().x,
            float(height) / m_sf_texture.getSize().y);
    }
    // 设置显示大小
    void TextureItem::setShowSize(const int width, const int &height) {
        m_sf_sprite.setScale(float(width) / m_sf_texture.getSize().x,
            float(height) / m_sf_texture.getSize().y);
    }

    // 设置 X 坐标
    void TextureItem::setX(const float &x) {
        m_sf_sprite.setPosition(x, m_sf_sprite.getPosition().y);
    }

    // 设置 Y 坐标
    void TextureItem::setY(const float &y) {
        m_sf_sprite.setPosition(m_sf_sprite.getPosition().x, y);
    }

    //设置位置
    void TextureItem::setPosition(const float &x, const float &y) {
        m_sf_sprite.setPosition(x, y);
    }
    //获取显示宽度
    const float TextureItem::getShowWidth() const {
        return m_sf_sprite.getGlobalBounds().width;
    }
    //获取显示高度
    const float TextureItem::getShowHidth() const {
        return m_sf_sprite.getGlobalBounds().height;
    }
    //获取纹理宽度
    const int TextureItem::getTextureWidth() const {
        return m_sf_texture.getSize().x;
    }
    //获取纹理高度
    const int TextureItem::getTextureHeight() const {
        return m_sf_texture.getSize().y;
    }
    //获取X坐标
    const float TextureItem::getX() const {
        return m_sf_sprite.getPosition().x;
    }
    //获取Y坐标
    const float TextureItem::getY() const {
        return m_sf_sprite.getPosition().y;
    }
    //获取加载内容
    const sf::Sprite &TextureItem::getSprite() const {
        return m_sf_sprite;
    }
}
