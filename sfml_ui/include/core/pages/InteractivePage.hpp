#pragma once
#include <Page.hpp>
#include <Interactive.hpp>
#include <Window.hpp>
namespace sfui {
    // ��̬��ʵʱ���µĽ���ҳ��
    // ������ͼ��СΪ���ڴ�С
    // (0,0)Ϊ��Ļ����,�������ô������ĵ�����
    class InteractivePage :virtual public Page {
    public:

    protected:
        sf::View m_view;

        // ���ݰ󶨴��ڵ�ʵʱ״̬�����½�����ͼ
        void updateView() override {
            m_windowSize = mp_window->getWindowSize();
            m_view.setSize(
                float(m_windowSize.x),
                float(m_windowSize.y)
            );
            m_view.setCenter(m_x, m_y);
        }

        // ������ͼ���Ķ�������������ϵ�е�����
        void setViewCenter(const float &x, const float &y) {
            m_x = x;
            m_y = y;
        }

        // ���ư�ť
        void draw(const Button &button) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(button.getSprite());
        }

        //���ƽ�������
        void draw(const Interactive &interActive) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(interActive.getSprite());
        }

        //��������
        void draw(const TextureItem &textureItem) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textureItem.getSprite());
        }

        void draw(const sf::VertexArray &vertexArray) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(vertexArray);
        }

        // ��ȡ�������Ķ�Ӧ��������ϵ������ X
        float getX() const {
            return m_x;
        }

        // ��ȡ�������Ķ�Ӧ��������ϵ������ Y
        float getY() const {
            return m_y;
        }

        // ��ȡ�����󶨴��ڵĴ�С
        WindowSize getWindowSize() const {
            return m_windowSize;
        }
    private:
        float m_x = 0.0;
        float m_y = 0.0;
        WindowSize m_windowSize;
    };
}