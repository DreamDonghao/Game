#pragma once

namespace sfui {

    class Area {
    public:
        bool init(const float left, const float up, const float rigth, const float lower) {
            m_left = left;
            m_up = up;
            m_right = rigth;
            m_lower = lower;
            return true;
        }

        bool isInArea(const int &x, const int &y) const {
            if (m_left <= x && x <= m_right && m_up <= y && y <= m_lower) {
                return true;
            } else {
                return false;
            }
        }

    private:
        float m_left;
        float m_up;
        float m_right;
        float m_lower;
    };
}
