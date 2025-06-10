#pragma once
#include <Page.hpp>
#include <Window.hpp>
namespace sfui {
    /**
     * @brief UI 控件页面，视图大小等于窗口大小，(0,0)为左上角
     *
     * 提供控件绘制、缩放、视图更新等接口。
     */
    class ControlPage :virtual public Page {
    public:
        ControlPage(sf::RenderWindow *p_sfml_RenderWindow):Page(p_sfml_RenderWindow){};
    protected:
        sf::View m_view; ///< 控件页面的视图

        /**
         * @brief 按比例缩放视图
         * @param ratio 缩放比例
         */
        virtual void zoom(const double &ratio) {
            m_view.zoom(ratio);
        }

        /**
         * @brief 根据绑定窗口的大小来更新界面视图
         */
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

        /**
         * @brief 绘制按钮
         * @param button 按钮对象
         */
        void draw(const Button &button) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(button.getSprite());
        }

        /**
         * @brief 绘制纹理项
         * @param textureItem 纹理项对象
         */
        void draw(const TextureItem &textureItem) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textureItem.getSprite());
        }

        /**
         * @brief 绘制文本框
         * @param textBox 文本框对象
         */
        void draw(const sfui::TextBox &textBox) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textBox.getSprite());
        }

        void draw(const sfui::InputBox &inputBox)const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(inputBox.getSpring());
        }

    };
}
