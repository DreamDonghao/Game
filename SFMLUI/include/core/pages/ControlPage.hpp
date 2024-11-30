#pragma once
#include <Page.hpp>
#include <Window.hpp>
namespace sfui {
    // UI �ؼ�ҳ��
    // ������ͼ��СΪ���ڴ�С
    // (0,0)Ϊ���Ͻ�
    class ControlPage :virtual public Page {
    public:
       
    protected:
        sf::View m_view;
       
        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ
        void updateView() override {
            m_view.setSize(
                float(mp_window->getWindowSize().x),
                float(mp_window->getWindowSize().y)
            );
            m_view.setCenter(
                float(mp_window->getWindowSize().x) / 2,
                float(mp_window->getWindowSize().y) / 2
            );
        }

        void draw(const Button &button) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(button.getSprite());
        }

        void draw(const TextureItem &textureItem) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textureItem.getSprite());
        }

    };
}