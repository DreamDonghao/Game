#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    using Position = sf::Vector2i;
    // 实时鼠标
    class Mouse {
    public:
        Mouse();

        void setWindow(sf::RenderWindow *const p_sfml_RenderWindow);

        // 获取实时鼠标指针相对于屏幕的位置
        Position getScreenPosition();

        // 获取实时鼠标指针相对于窗口的位置
        Position getWindowPosition();

        // 获取实时鼠标指针相对于视图的位置
        Position getViewPosition();

        // 获取实时鼠标左键是否点击
        bool isLeftPressed();

        // 获取实时鼠标右键是否点击
        bool isRightPressed();

        // 获取实时鼠标中建是否点击
        bool isMiddlePressed();

        // 获取实时鼠标1键是否点击
        bool isXButton1Pressed();

        // 获取实时鼠标2键是否点击
        bool isXButton2Pressed();
    private:
        sf::RenderWindow *m_sf_RenderWindow_p = nullptr;
    };


}