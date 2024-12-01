#pragma once

namespace sfui {

    class Area {
    public:
        bool init(const int left, const int up, const int rigth, const int lower) {
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
        int m_left;
        int m_up;
        int m_right;
        int m_lower;
    };
}
