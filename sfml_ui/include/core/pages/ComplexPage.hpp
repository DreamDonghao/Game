#pragma once
#include <InteractivePage.hpp>
#include <ControlPage.hpp>

namespace sfui {
    // 混合界面类，结合了交互页面和控件页面的功能
    class ComplexPage :public InteractivePage, public ControlPage {
    public:
        // 析构函数
        virtual ~ComplexPage() override =default;

        // 同时缩放控件和交互内容
        // @param ratio 缩放比例
        void zooms(const double& ratio){
            ControlPage::zoom(ratio);
            InteractivePage::zoom(ratio);
        }

        // 更新视图，分别更新控件和交互内容的视图
        void updateView() override{
            ControlPage::updateView();
            InteractivePage::updateView();
        }

        // 获取窗口视图
        sf::View getWindowView() const {
            return InteractivePage::m_view;
        }

        // 获取世界视图
        sf::View getWorldView() const {
            return ControlPage::m_view;
        }

        // 以窗口为依据绘制对象
        template<typename DrawObject>
        void drawForWindow(const DrawObject &drawObject ) {
            ControlPage::draw(drawObject);
        }

        // 以视图为依据绘制对象
        template<typename DrawObject>
        void drawForView(const DrawObject &drawObject) {
            InteractivePage::draw(drawObject);
        }
    protected:
        // 当前缩放比例
        double m_ratio = 1;

    };

}
