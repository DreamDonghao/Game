#pragma once

#include <elemental.hpp>
#include <FrameAnimatedSprite.hpp>
#include <TimeAnimatedSprite.hpp>

namespace game {

    // 在世界中存在的元素
    class WorldElemental : public Elemental {
    public:
        [[nodiscard]] double getX() const { return m_x; }

        [[nodiscard]] double getY() const { return m_y; }

        const sf::Sprite &getSprite() { return m_frameAnimatedSprite.getSprite(); }

        virtual bool init(const float &continuationtTime,
                          const int &width, const int &height, const float &x, const float &y) {
            m_frameAnimatedSprite.init(continuationtTime, width, height, x, y);
            return true;
        }

        void moveToX(const double &x) {
            m_x = x;
            m_frameAnimatedSprite.setXY(static_cast<float>(m_x), static_cast<float>(m_y));
        }

        void moveToY(const double &y) {
            m_y = y;
            m_frameAnimatedSprite.setXY(static_cast<float>(m_x), static_cast<float>(m_y));
        }

    protected:
        double m_x;
        double m_y;
        sfui::TimeAnimatedSprite m_frameAnimatedSprite;
    };

}
