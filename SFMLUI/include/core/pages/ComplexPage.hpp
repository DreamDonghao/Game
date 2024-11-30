#pragma once
#include <InteractivePage.hpp>
#include <ControlPage.hpp>

namespace sfui {
    // 混合界面(位置动态更新界面，UI控件界面)
    class ComplexPage :public InteractivePage, public ControlPage {
    public:
        // 更新视图
        void updateView() override{
            ControlPage::updateView();
            InteractivePage::updateView();
        }

        // 以窗口为依据绘制
        template<typename DrawObject>
        void drawForWindow(const DrawObject &drawObject ) {
            ControlPage::draw(drawObject);
        }

        // 以视图为依据绘图
        template<typename DrawObject>
        void drawForView(const DrawObject &drawObject) {
            InteractivePage::draw(drawObject);
        }

    };

}