#pragma once
#include <Page.hpp>
#include <Interactive.hpp>
#include <Window.hpp>
namespace sfui {
    // 动态或实时更新的交互页面
    // 界面视图大小为窗口大小
    // (0,0)为屏幕中心,可以设置窗口中心的坐标
    class InteractivePage :virtual public Page {
    public:

    protected:
        sf::View m_view;

        // 根据绑定窗口的实时状态来更新界面视图
        void updateView() override {
            m_windowSize = mp_window->getWindowSize();
            m_view.setSize(
                float(m_windowSize.x),
                float(m_windowSize.y)
            );
            m_view.setCenter(m_x, m_y);
        }

        // 设置视图中心对用于世界坐标系中的坐标
        void setViewCenter(const float &x, const float &y) {
            m_x = x;
            m_y = y;
        }

        // 绘制按钮
        void draw(const Button &button) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(button.getSprite());
        }

        //绘制交互区域
        void draw(const Interactive &interActive) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(interActive.getSprite());
        }

        //绘制纹理
        void draw(const TextureItem &textureItem) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textureItem.getSprite());
        }

        void draw(const sf::VertexArray &vertexArray) {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(vertexArray);
        }

        // 获取界面中心对应世界坐标系的坐标 X
        float getX() const {
            return m_x;
        }

        // 获取界面中心对应世界坐标系的坐标 Y
        float getY() const {
            return m_y;
        }

        // 获取与界面绑定窗口的大小
        WindowSize getWindowSize() const {
            return m_windowSize;
        }
    private:
        float m_x = 0.0;
        float m_y = 0.0;
        WindowSize m_windowSize;
    };
}