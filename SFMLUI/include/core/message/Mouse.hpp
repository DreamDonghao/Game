#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    using Position = sf::Vector2i;
    class Mouse {
    public:
        Mouse();
        void setWindow(sf::RenderWindow *const p_sfml_RenderWindow);
        // ��ȡʵʱ���ָ���������Ļ��λ��
        Position getScreenPosition();
        // ��ȡʵʱ���ָ������ڴ��ڵ�λ��
        Position getWindowPosition();
        // ��ȡʵʱ���ָ���������ͼ��λ��
        Position getViewPosition();
    private:
        sf::RenderWindow *mp_sfml_RenderWindow = nullptr;
    };


}