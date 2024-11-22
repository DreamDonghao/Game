#include <Mouse.hpp>

namespace sfui {
    Mouse::Mouse() {
    }
    void  Mouse::setWindow(sf::RenderWindow *const p_sfml_RenderWindow) {
        mp_sfml_RenderWindow = p_sfml_RenderWindow;
    }

    Position  Mouse::getScreenPosition() {
        return sf::Mouse::getPosition();
    }

    Position  Mouse::getWindowPosition() {
        return sf::Mouse::getPosition(*mp_sfml_RenderWindow);
    }

    Position  Mouse::getViewPosition() {
        sf::Vector2i mousePosWindow = sf::Mouse::getPosition(*mp_sfml_RenderWindow);
        sf::Vector2f mousePosView = mp_sfml_RenderWindow->mapPixelToCoords(mousePosWindow);
        return Position(static_cast<int>(mousePosView.x), static_cast<int>(mousePosView.y));
    }
}