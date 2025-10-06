#pragma once
#include <cassert>

namespace sfui {
    /**
     * @brief 区域类，表示一个矩形区域，支持判定点是否在区域内
     */
    class Area {
    public:
        Area(const float minX, const float maxX, const float minY, const float maxY)
            : m_minX(minX), m_maxX(maxX), m_minY(minY), m_maxY(maxY) {
        }

        void set(const float minX, const float maxX, const float minY, const float maxY) {
            assert(minX <= maxX && "Area: minX must be <= maxX");
            assert(minY <= maxY && "Area: minY must be <= maxY");
            m_minX = minX;
            m_maxX = maxX;
            m_minY = minY;
            m_maxY = maxY;
        }

        [[nodiscard]] bool isInArea(const float &x, const float &y) const {
            if (m_minX <= x && x <= m_maxX && m_minY <= y && y <= m_maxY) {
                return true;
            }
            return false;
        }

    private:
        float m_minX = 0;
        float m_maxX = 0;
        float m_minY = 0;
        float m_maxY = 0;
    };
}
