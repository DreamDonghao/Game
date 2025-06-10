#pragma once
#include <InteractivePage.hpp>
#include <ControlPage.hpp>

namespace sfui {
    /**
     * @brief 混合界面类，结合了交互页面和控件页面的功能
     *
     * 既支持控件布局，也支持动态交互内容。
     */
    class ComplexPage :public InteractivePage, public ControlPage {
    public:
        ComplexPage(sf::RenderWindow *p_sfml_RenderWindow):InteractivePage(p_sfml_RenderWindow),ControlPage(p_sfml_RenderWindow){}
        /**
         * @brief 析构函数
         */
        virtual ~ComplexPage() override =default;

        /**
         * @brief 同时缩放控件和交互内容
         * @param ratio 缩放比例
         */
        void zooms(const double& ratio){
            ControlPage::zoom(ratio);
            InteractivePage::zoom(ratio);
        }

        /**
         * @brief 更新视图，分别更新控件和交互内容的视图
         */
        void updateView() override{
            ControlPage::updateView();
            InteractivePage::updateView();
        }

        /**
         * @brief 获取窗口视图
         * @return 窗口视图
         */
        sf::View getWindowView() const {
            return InteractivePage::m_view;
        }

        /**
         * @brief 获取世界视图
         * @return 世界视图
         */
        sf::View getWorldView() const {
            return ControlPage::m_view;
        }

        /**
         * @brief 以窗口为依据绘制对象
         * @tparam DrawObject 可绘制对象类型
         * @param drawObject 绘制对象
         */
        template<typename DrawObject>
        void drawForWindow(const DrawObject &drawObject ) {
            ControlPage::draw(drawObject);
        }

        /**
         * @brief 以视图为依据绘制对象
         * @tparam DrawObject 可绘制对象类型
         * @param drawObject 绘制对象
         */
        template<typename DrawObject>
        void drawForView(const DrawObject &drawObject) {
            InteractivePage::draw(drawObject);
        }
    protected:
        double m_ratio = 1; ///< 当前缩放比例
    };

}
