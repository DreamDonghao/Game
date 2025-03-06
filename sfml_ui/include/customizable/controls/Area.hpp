#pragma once
#include <print>
namespace sfui {
    // 区域
    class Area {
    public:
        Area() = default;

        // 初始化
        bool init(const float left, const float up, const float rigth, const float lower) {
            m_left = left;
            m_up = up;
            m_right = rigth;
            m_lower = lower;
            return true;
        }

        // 判断一个坐标是否在区域内
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
