#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    using Position = sf::Vector2i;
    class Mouse {
    public:
        Mouse() {
        }
        void setWindow(sf::RenderWindow *const p_sfml_RenderWindow) {
            mp_sfml_RenderWindow = p_sfml_RenderWindow;
        }
        // 获取实时鼠标指针相对于屏幕的位置
        Position getScreenPosition() {
            return sf::Mouse::getPosition();
        }
        // 获取实时鼠标指针相对于窗口的位置
        Position getWindowPosition() {
            return sf::Mouse::getPosition(*mp_sfml_RenderWindow);
        }
        // 获取实时鼠标指针相对于视图的位置
        Position getViewPosition() {
            sf::Vector2i mousePosWindow = sf::Mouse::getPosition(*mp_sfml_RenderWindow);
            sf::Vector2f mousePosView = mp_sfml_RenderWindow->mapPixelToCoords(mousePosWindow);
            return Position(static_cast<int>(mousePosView.x), static_cast<int>(mousePosView.y));
        }

    private:
        sf::RenderWindow *mp_sfml_RenderWindow = nullptr;
    };


}