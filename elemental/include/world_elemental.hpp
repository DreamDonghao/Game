#pragma once
#include <elemental.hpp>
#include <FrameAnimatedSprite.hpp>
namespace game {
    // 在世界中存在的元素
    class WorldElemental :public Elemental{
    public:
        double getX()const { return m_x; }
        double getY()const { return m_y; }
        const sf::Sprite &getSprite() { return m_frameAnimatedSprite.getSprite(); }

    protected:
        
    private:
        double m_x;
        double m_y;
        sfui::FrameAnimatedSprite m_frameAnimatedSprite;
    };

}
