#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    using Position = sf::Vector2i;
    /**
     * @brief 实时鼠标操作类
     *
     * 封装了鼠标在屏幕、窗口、视图中的位置获取及按键状态。
     */
    class Mouse {
    public:
        /**
         * @brief 构造函数
         */
        Mouse();

        /**
         * @brief 设置绑定的SFML窗口指针
         * @param p_sfml_RenderWindow 指向SFML窗口的指针
         */
        void setWindow(sf::RenderWindow *const p_sfml_RenderWindow);

        /**
         * @brief 获取鼠标指针相对于屏幕的位置
         * @return 鼠标屏幕坐标
         */
        Position getScreenPosition();

        /**
         * @brief 获取鼠标指针相对于窗口的位置
         * @return 鼠标窗口坐标
         */
        Position getWindowPosition();

        /**
         * @brief 获取鼠标指针相对于视图的位置
         * @return 鼠标视图坐标
         */
        Position getViewPosition();

        /**
         * @brief 判断鼠标左键是否按下
         * @return 是否按下
         */
        bool isLeftPressed();

        /**
         * @brief 判断鼠标右键是否按下
         * @return 是否按下
         */
        bool isRightPressed();

        /**
         * @brief 判断鼠标中键是否按下
         * @return 是否按下
         */
        bool isMiddlePressed();

        /**
         * @brief 判断鼠标XButton1是否按下
         * @return 是否按下
         */
        bool isXButton1Pressed();

        /**
         * @brief 判断鼠标XButton2是否按下
         * @return 是否按下
         */
        bool isXButton2Pressed();
    private:
        sf::RenderWindow *m_sf_RenderWindow_p = nullptr; ///< 绑定的SFML窗口指针
    };
}
