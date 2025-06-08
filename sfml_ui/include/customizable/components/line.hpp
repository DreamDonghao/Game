#include <SFML/Graphics.hpp>

namespace sfui {
    /**
     * @brief 线段对象，支持初始化起止点和颜色
     */
    class Line {
    public:
        /**
         * @brief 默认构造函数
         */
        Line() = default;
        /**
         * @brief 初始化线段的起止点和颜色
         * @param x 起点x
         * @param y 起点y
         * @param xx 终点x
         * @param yy 终点y
         * @param color 线段颜色
         * @return 是否初始化成功
         */
        bool init(const double &&x, const double &&y,
            const double &&xx, const double &yy, const sf::Color &&color) {
            m_x = x;
            m_y = y;
            m_xx = xx;
            m_yy = yy;
            m_color = color;
        }
    private:
        double m_x; ///< 起点x
        double m_y; ///< 起点y
        double m_xx; ///< 终点x
        double m_yy; ///< 终点y
        sf::Color m_color; ///< 线段颜色
    };

}
