#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    using Position = sf::Vector2i;
    // 实时鼠标操作类
    class Mouse {
    public:
        // 构造函数
        Mouse();

        // 设置绑定的SFML窗口指针
        void setWindow(sf::RenderWindow *const p_sfml_RenderWindow);

        // 获取鼠标指针相对于屏幕的位置
        Position getScreenPosition();

        // 获取鼠标指针相对于窗口的位置
        Position getWindowPosition();

        // 获取鼠标指针相对于视图的位置
        Position getViewPosition();

        // 判断鼠标左键是否按下
        bool isLeftPressed();

        // 判断鼠标右键是否按下
        bool isRightPressed();

        // 判断鼠标中键是否按下
        bool isMiddlePressed();

        // 判断鼠标XButton1是否按下
        bool isXButton1Pressed();

        // 判断鼠标XButton2是否按下
        bool isXButton2Pressed();
    private:
        // 绑定的SFML窗口指针
        sf::RenderWindow *m_sf_RenderWindow_p = nullptr;
    };

}
