#pragma once

#include <world_elemental.hpp>

namespace game {
    // 生物
    class Biology : public WorldElemental {
    public:
        [[nodiscard]] double getHealth() const { return m_health; }

        void setHealth(const double &health) { m_health = health; }

        void increaseHealth(const double &health) { m_health += health; }

        void decreaseHealth(const double &health) { m_health -= health; }


        double m_health;
        double speed_x;
        double direction;
    };

}
