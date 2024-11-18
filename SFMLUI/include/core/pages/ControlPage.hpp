#include <Page.hpp>
#include <Window.hpp>
namespace sfui {
    // UI 控件页面
    // 界面视图会根据窗口大小来调整
    // (0,0)为左上角
    class ControlPage :public Page {
    public:

    protected:
        // 根据绑定窗口的大小来更新界面视图
        void updateView() override {
            float aspectRatio = 
                float(mp_window->getMaxWindowSize().x )/ mp_window->getMaxWindowSize().y;
            m_view.setSize(3000*aspectRatio, 3000*aspectRatio);
            m_view.setCenter(1500 * aspectRatio, 1500*aspectRatio);
        }
    };
}