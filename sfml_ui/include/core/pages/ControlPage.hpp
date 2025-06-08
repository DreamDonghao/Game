#pragma once
#include <Page.hpp>
#include <Window.hpp>
namespace sfui {
    // UI 控件页面，视图大小等于窗口大小，(0,0)为左上角
    class ControlPage :virtual public Page {
    public:
        
    protected:
        // 控件页面的视图
        sf::View m_view;

        // 按比例缩放视图
        // @param ratio 缩放比例
        virtual void zoom(const double &ratio) {
            m_view.zoom(ratio);
        }

        // 根据绑定窗口的大小来更新界面视图
        void updateView() override {
            m_view.setSize(
                static_cast<float>(mp_window->getWindowSize().x),
                static_cast<float>(mp_window->getWindowSize().y)
            );
            m_view.setCenter(
                static_cast<float>(mp_window->getWindowSize().x) / 2,
                static_cast<float>(mp_window->getWindowSize().y) / 2
            );
        }

        // 绘制按钮
        void draw(const Button &button) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(button.getSprite());
        }

        // 绘制纹理项
        void draw(const TextureItem &textureItem) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textureItem.getSprite());
        }

        // 绘制文本框
        void draw(const sfui::TextBox &textBox) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textBox.getSprite());
        }

    };
}
