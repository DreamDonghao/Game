#pragma once
#include <print>
namespace sfui {
    /**
     * @brief 区域类，表示一个矩形区域，支持判定点是否在区域内
     */
    class Area {
    public:
        /**
         * @brief 默认构造函数
         */
        Area() = default;

        /**
         * @brief 初始化区域
         * @param left 左边界
         * @param up 上边界
         * @param right 右边界
         * @param lower 下边界
         * @return 是否初始化成功
         */
        bool init(const float left, const float up, const float right, const float lower) {
            m_left = left;
            m_up = up;
            m_right = right;
            m_lower = lower;
            return true;
        }

        /**
         * @brief 判断一个坐标是否在区域内
         * @param x X坐标
         * @param y Y坐标
         * @return 是否在区域内
         */
        bool isInArea(const int &x, const int &y) const {
            if (m_left <= x && x <= m_right && m_up <= y && y <= m_lower) {
                return true;
            } else {
                return false;
            }
        }

    private:
        float m_left;  ///< 左边界
        float m_up;    ///< 上边界
        float m_right; ///< 右边界
        float m_lower; ///< 下边界
    };
}
