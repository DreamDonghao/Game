#pragma once
#include <SFML/Window/Event.hpp>

#include <Page.hpp>

namespace sfui {
    // 界面指针
    template<typename PageType>
    using PagePtr = std::unique_ptr<PageType>;

    // 创建界面
    template<typename PageType, typename... Args>
    inline PagePtr<PageType> makePage(Args &&... args) {
        return std::make_unique<PageType>(std::forward<Args>(args)...);
    }

    // 标题界面对应表
    using PageMap = std::unordered_map<Title, PagePtr<Page> >;

    // 窗口大小
    using WindowSize = sf::Vector2u;

    // 表示窗口状态
    enum class WindowState {
        Windowed, // 窗口模式
        Fullscreen // 全屏模式
    };

    /**
     * @brief 窗口类，负责窗口创建、页面管理、事件循环、全屏切换等
     */
    class Window {
    public:
        /**
         * @brief 构造函数
         * @param width 窗口宽度
         * @param heigth 窗口高度
         * @param winsowState 窗口状态
         */
        Window(const int &width, const int &heigth, const WindowState &winsowState);

        /**
         * @brief 析构函数
         */
        ~Window() = default;

        /**
         * @brief 初始化窗口参数
         * @param framerateLimit 帧率上限
         * @param verticalSyncEnabled 是否开启垂直同步
         * @return 是否初始化成功
         */
        bool init(const int &framerateLimit, const bool &verticalSyncEnabled);

        /**
         * @brief 向该窗口添加页面
         * @param pageTitle 页面标题
         * @param page 页面指针
         */
        void addPage(const Title &pageTitle, PagePtr<Page> page);

        /**
         * @brief 开始显示首页面，进入主循环
         * @param firstPageTitle 首页标题
         */
        void startShow(const Title &firstPageTitle);

        /**
         * @brief 切换为指定标题界面
         * @param pageTitle 目标页面标题
         */
        void requestPageSwitch(const Title &pageTitle);

        /**
         * @brief 获取SFML窗口对象
         * @return SFML窗口引用
         */
        sf::RenderWindow &getSfRenderWindow();

        /**
         * @brief 获取窗口大小
         * @return 窗口大小
         */
        const WindowSize getWindowSize() const;

        /**
         * @brief 获取屏幕分辨率
         * @return 屏幕分辨率
         */
        const WindowSize &getScreenSize() const;

    private:
        sf::RenderWindow m_sf_renderWindow; ///< SFML窗口对象
        WindowSize m_windowSize; ///< 当前窗口大小
        WindowSize m_screenSize; ///< 屏幕分辨率
        PageMap m_pages; ///< 页面映射表
        Title m_nowPageTitle; ///< 当前页面标题
        sf::Event m_event; ///< 当前事件
        WindowState m_winsowState; ///< 当前窗口状态
        int m_framerateLimit = 60; ///< 刷新率
        bool m_verticalSyncEnabled = false; ///< 垂直同步是否开启

        /**
         * @brief 更新当前界面的视图
         */
        void updateView();

        /**
         * @brief 更新消息，并在收到关闭窗口时将窗口关闭
         */
        void procesMessage();

        /**
         * @brief 处理实时输入
         */
        void handleRealTimeInput();

        /**
         * @brief 处理事件输入
         */
        void handleEventInput();

        /**
         * @brief 加载并显示界面画面到窗口
         */
        void drawFrame();

        /**
         * @brief 控制窗口自身的方法，切换窗口/全屏
         */
        void toggleFullscreen();

        /**
         * @brief 切换为全屏模式
         */
        void toFullscreen();

        /**
         * @brief 切换为窗口模式
         */
        void toWindowed();
    };
}
