#include <Page.hpp>
#include <Window.hpp>

namespace sfui {
    // UI 控件页面
    // 界面视图大小为窗口大小
    // (0,0)为左上角
    class ControlPage :public Page {
    public:

    protected:
        // 根据绑定窗口的大小来更新界面视图
        void updateView() override {
            m_view.setSize(
                float(mp_window->getWindowSize().x),
                float(mp_window->getWindowSize().y)
            );
            m_view.setCenter(
                float(mp_window->getWindowSize().x)/2, 
                float(mp_window->getWindowSize().y)/2
            );
        }
        // 页面跳转请求
        void requestPageSwitch(const Title &targetPageTitle) override {
            mp_window->requestPageSwitch(targetPageTitle);
        }
    };
}