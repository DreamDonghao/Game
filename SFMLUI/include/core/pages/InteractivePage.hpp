#pragma once
#include <Page.hpp>

namespace sfui {
    // ��̬��ʵʱ���µĽ���ҳ��
    // ������ͼ��СΪ���ڴ�С
    // (0,0)Ϊ��Ļ����,�������ô������ĵ�����
    class InteractivePage :virtual public Page {
    public:


    protected:
        sf::View m_view;

        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ
        void updateView() override {
            m_view.setSize(float(mp_window->getWindowSize().x),
                float(mp_window->getWindowSize().y));
            m_view.setCenter(m_x, m_y);
        }

        void setViewCenter(const float &x, const float &y) {
            m_x = x;
            m_y = y;
        }

        void draw(const Button &button) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(button.getSprite());
        }

        void draw(const TextureItem &textureItem) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textureItem.getSprite());
        }
    private:
        float m_x = 0.0;
        float m_y = 0.0;
    };
}