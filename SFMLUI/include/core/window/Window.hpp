#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <Page.hpp>
#include <unordered_map>
#include <locale>
#include <codecvt>

namespace sfui {
    // 界面指针
    template <typename PageType>
    using PagePtr = std::unique_ptr<PageType>;
    // 创建界面
    template <typename PageType, typename... Args>
    inline PagePtr<PageType> makePage(Args&&... args) {
        return std::make_unique<PageType>(std::forward<Args>(args)...);
    }
    // 标题界面对应表
    using PageMap = std::unordered_map<Title, PagePtr<Page>>;
    // 窗口大小
    using WindowSize = sf::Vector2u;
    // 表示窗口状态
    enum class WindowState {
        Windowed,  // 窗口模式
        Fullscreen // 全屏模式
    };

    //窗口类
    class Window {
    public:

        Window(const int &width, const int &heigth, const WindowState &winsowState);

        //向该窗口添加页面
        //参数：界面标题 构造界面指针
        void addPage(const Title &pageTitle, PagePtr<Page> page);

        // 开始显示首页面
        void startShow(const Title &firstPageTitle);
        
        // 切换为指定标题界面
        void requestPageSwitch(const Title &pageTitle);

        //获取sfml的窗口
        sf::RenderWindow &getSfRenderWindow();

        // 获取窗口大小
        const WindowSize getWindowSize();

        // 获取屏幕分辨率
        const WindowSize &getScreenSize() const;

    private:
        sf::RenderWindow m_sfml_renderWindow;
        WindowSize m_windowSize;
        WindowSize m_screenSize;
        PageMap m_pages;
        Title m_nowPageTitle;
        sf::Event m_event;
        WindowState m_winsowState;
    private:
        // 更新当前界面的视图
        void updateView();
        // 更新消息，并在收到关闭窗口时将窗口关闭
        void procesMessage();
        // 处理实时输入
        void handleRealTimeInput();
        // 处理事件输入
        void  handleEventInput();
        // 加载并显示界面画面到窗口
        void drawFrame();
    private:
        //控制窗口自身的方法
        void toggleFullscreen();
        // 切换为全屏模式
        void toFullscreen();
        //切换为窗口模式
        void toWindowed();
    };

}