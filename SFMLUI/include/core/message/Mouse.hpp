#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    using Position = sf::Vector2i;
    // ʵʱ���
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

        // ��ȡʵʱ�������Ƿ���
        bool isLeftPressed();

        // ��ȡʵʱ����Ҽ��Ƿ���
        bool isRightPressed();

        // ��ȡʵʱ����н��Ƿ���
        bool isMiddlePressed();

        // ��ȡʵʱ���1���Ƿ���
        bool isXButton1Pressed();

        // ��ȡʵʱ���2���Ƿ���
        bool isXButton2Pressed();
    private:
        sf::RenderWindow *m_sf_RenderWindow_p = nullptr;
    };


}