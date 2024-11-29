#include <Page.hpp>

namespace sfui {
    // 动态或实时更新的交互页面
    // 界面视图大小为窗口大小
    // (0,0)为屏幕中心
    class InteractivePage :public Page {
    public:

    protected:
        // 根据绑定窗口的大小来更新界面视图
        void updateView() override {
            m_view.setSize(float(mp_window->getWindowSize().x), 
                float(mp_window->getWindowSize().y));
            m_view.setCenter(0, 0);
        }
        // 页面跳转请求
        void requestPageSwitch(const Title &targetPageTitle) override {
            mp_window->requestPageSwitch(targetPageTitle);
        }
    };
}