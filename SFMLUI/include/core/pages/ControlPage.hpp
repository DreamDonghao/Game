#pragma once
#include <Page.hpp>
#include <Window.hpp>
namespace sfui {
    // UI 控件页面
    // 界面视图大小为窗口大小
    // (0,0)为左上角
    class ControlPage :virtual public Page {
    public:
       
    protected:
        sf::View m_view;
       
        // 根据绑定窗口的大小来更新界面视图
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