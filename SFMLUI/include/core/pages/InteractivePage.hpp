#pragma once
#include <Page.hpp>
#include <Interactive.hpp>
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
            m_windowSize = mp_window->getWindowSize();
            m_view.setSize(
                float(m_windowSize.x),
                float(m_windowSize.y)
            );
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

        void draw(const Interactive &interActive) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(interActive.getSprite());
        }

        void draw(const TextureItem &textureItem) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textureItem.getSprite());
        }
        float getX() const {
            return m_x;
        }
        float getY() const {
            return m_y;
        }
        WindowSize getWindowSize() const {
            return m_windowSize;
        }
    private:
        float m_x = 0.0;
        float m_y = 0.0;
        WindowSize m_windowSize;
    };
}