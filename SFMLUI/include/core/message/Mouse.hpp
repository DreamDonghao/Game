#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    using Position = sf::Vector2i;
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
    private:
        sf::RenderWindow *mp_sfml_RenderWindow = nullptr;
    };


}