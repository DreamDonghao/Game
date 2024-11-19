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
        // ��ȡʵʱ���ָ���������Ļ��λ��
        Position getScreenPosition() {
            return sf::Mouse::getPosition();
        }
        // ��ȡʵʱ���ָ������ڴ��ڵ�λ��
        Position getWindowPosition() {
            return sf::Mouse::getPosition(*mp_sfml_RenderWindow);
        }
        // ��ȡʵʱ���ָ���������ͼ��λ��
        Position getViewPosition() {
            sf::Vector2i mousePosWindow = sf::Mouse::getPosition(*mp_sfml_RenderWindow);
            sf::Vector2f mousePosView = mp_sfml_RenderWindow->mapPixelToCoords(mousePosWindow);
            return Position(static_cast<int>(mousePosView.x), static_cast<int>(mousePosView.y));
        }

    private:
        sf::RenderWindow *mp_sfml_RenderWindow = nullptr;
    };


}