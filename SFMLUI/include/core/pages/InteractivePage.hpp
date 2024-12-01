#pragma once
#include <Page.hpp>
#include <Interactive.hpp>
namespace sfui {
    // 动态或实时更新的交互页面
    // 界面视图大小为窗口大小
    // (0,0)为屏幕中心,可以设置窗口中心的坐标
    class InteractivePage :virtual public Page {
    public:

    protected:
        sf::View m_view;

        // 根据绑定窗口的大小来更新界面视图
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