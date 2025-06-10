#pragma once
#include <Page.hpp>
#include <Interactive.hpp>
#include <Window.hpp>
namespace sfui {
    /**
     * @brief 动态或实时更新的交互页面，视图中心可自定义
     *
     * 提供交互对象绘制、缩放、视图更新、中心坐标设置等接口。
     */
    class InteractivePage :virtual public Page {
    public:
        InteractivePage(sf::RenderWindow *p_sfml_RenderWindow):Page(p_sfml_RenderWindow){}
    protected:
        sf::View m_view; ///< 交互页面的视图

        /**
         * @brief 按比例缩放视图
         * @param ratio 缩放比例
         */
        virtual void zoom(const double &ratio) {
            m_view.zoom(ratio);
        }

        /**
         * @brief 根据绑定窗口的实时状态来更新界面视图
         */
        void updateView() override {
            m_windowSize = mp_window->getWindowSize();
            m_view.setSize(
                static_cast<float>(m_windowSize.x),
                static_cast<float>(m_windowSize.y)
            );
            m_view.setCenter(m_x, m_y);
        }

        /**
         * @brief 设置视图中心坐标（世界坐标系）
         * @param x 中心x坐标
         * @param y 中心y坐标
         */
        void setViewCenter(const float &x, const float &y) {
            m_x = x;
            m_y = y;
        }

        /**
         * @brief 绘制按钮
         * @param button 按钮对象
         * @overload
         */
        void draw(const Button &button) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(button.getSprite());
        }

        /**
         * @brief 绘制交互区域
         * @param interActive 交互对象
         * @overload
         */
        void draw(const Interactive &interActive) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(interActive.getSprite());
        }

        /**
         * @brief 绘制纹理项
         * @param textureItem 纹理项对象
         * @overload
         */
        void draw(const TextureItem &textureItem) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(textureItem.getSprite());
        }

        /**
         * @brief 绘制顶点数组
         * @param vertexArray SFML顶点数组
         * @overload
         */
        void draw(const sf::VertexArray &vertexArray) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(vertexArray);
        }

        /**
         * @brief 绘制文本
         * @param text SFML文本对象
         * @overload
         */
        void draw(const sf::Text &text) const {
            mp_window->getSfRenderWindow().setView(m_view);
            mp_window->getSfRenderWindow().draw(text);
        }

        /**
         * @brief 获取界面中心对应世界坐标系的X坐标
         * @return X坐标
         */
        float getX() const {
            return m_x;
        }

        /**
         * @brief 获取界面中心对应世界坐标系的Y坐标
         * @return Y坐标
         */
        float getY() const {
            return m_y;
        }

        /**
         * @brief 获取与界面绑定窗口的大小
         * @return 窗口大小
         */
        WindowSize getWindowSize() const {
            return m_windowSize;
        }
    private:
        float m_x = 0.0; ///< 视图中心x坐标
        float m_y = 0.0; ///< 视图中心y坐标
        // 窗口大小
        WindowSize m_windowSize;
    };
}
