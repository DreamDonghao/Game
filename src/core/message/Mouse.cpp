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
    Position  Mouse::getScreenPosition() const {
        return sf::Mouse::getPosition();
    }
    Position  Mouse::getWindowPos() const {
        return sf::Mouse::getPosition(*m_sf_RenderWindow_p);
    }
    sf::Vector2f  Mouse::getViewPosition() const {
        const sf::Vector2i mousePosWindow = sf::Mouse::getPosition(*m_sf_RenderWindow_p);
        const sf::Vector2f mousePosView = m_sf_RenderWindow_p->mapPixelToCoords(mousePosWindow);
        return mousePosView;
    }
    bool Mouse::isLeftPressed()const {
        return sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
    bool Mouse::isRightPressed()const{
        return sf::Mouse::isButtonPressed(sf::Mouse::Right);
    }
    bool Mouse::isMiddlePressed()const {
        return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
    }
    bool Mouse::isXButton1Pressed()const {
        return sf::Mouse::isButtonPressed(sf::Mouse::XButton1);
    }
    bool Mouse::isXButton2Pressed()const {
        return sf::Mouse::isButtonPressed(sf::Mouse::XButton2);
    }
}
