/**
 * @file Mouse.cpp
 * @brief 实现Mouse类，封装鼠标相关操作。
 */
#include <Mouse.hpp>

namespace sfui {
    Mouse::Mouse(sf::RenderWindow *const p_sfml_RenderWindow):m_sf_RenderWindow_p(p_sfml_RenderWindow) {
    }
    void  Mouse::setWindow(sf::RenderWindow *const p_sfml_RenderWindow) {
        m_sf_RenderWindow_p = p_sfml_RenderWindow;
    }
    Position  Mouse::getScreenPosition() {
        return sf::Mouse::getPosition();
    }
    Position  Mouse::getWindowPosition() {
        return sf::Mouse::getPosition(*m_sf_RenderWindow_p);
    }
    Position  Mouse::getViewPosition() const {
        sf::Vector2i mousePosWindow = sf::Mouse::getPosition(*m_sf_RenderWindow_p);
        sf::Vector2f mousePosView = m_sf_RenderWindow_p->mapPixelToCoords(mousePosWindow);
        return Position(static_cast<int>(mousePosView.x), static_cast<int>(mousePosView.y));
    }
    bool Mouse::isLeftPressed() {
        return sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
    bool Mouse::isRightPressed() {
        return sf::Mouse::isButtonPressed(sf::Mouse::Right);
    }
    bool Mouse::isMiddlePressed() {
        return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
    }
    bool Mouse::isXButton1Pressed() {
        return sf::Mouse::isButtonPressed(sf::Mouse::XButton1);
    }
    bool Mouse::isXButton2Pressed() {
        return sf::Mouse::isButtonPressed(sf::Mouse::XButton2);
    }
}
