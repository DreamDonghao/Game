#include <TimeAnimatedSprite.hpp>

namespace sfui {

    TimeAnimatedSprite::TimeAnimatedSprite() {}

    bool TimeAnimatedSprite::init(const float &continuationtTime,
        const int &width, const int &height, const float &x, const float &y) {
        m_continuationTime = sf::seconds(continuationtTime);
        m_width = width;
        m_height = height;
        m_x = x;
        m_y = y;
        return true;
    }
    void TimeAnimatedSprite::addTextureItems(const FilePath &filepath) {
        m_textureItems.emplace_back().init(filepath, m_width, m_height, m_x, m_y);
    }
    void TimeAnimatedSprite::set(const float &continuationtTime,
        const int &width, const int &height, const float &x, const float &y) {
        m_continuationTime = sf::seconds(continuationtTime);
        m_width = width;
        m_height = height;
        m_x = x;
        m_y = y;;
        for (auto &textureItem : m_textureItems) {
            textureItem.setPosition(m_x, m_y);
            textureItem.setShowSize(m_width, m_height);
        }
    }
    const sf::Sprite &TimeAnimatedSprite::getSprite() {
        if (m_clock.getElapsedTime() >= m_continuationTime) {
            m_clock.restart();
            ++m_nowTextureItemsIndex;
            if (m_nowTextureItemsIndex == m_textureItems.size()) {
                m_nowTextureItemsIndex = 0;
            }
        }
        return m_textureItems[m_nowTextureItemsIndex].getSprite();
    }
}