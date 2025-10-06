#pragma once
#include <SFML/Window/Event.hpp>
#include <Page.hpp>

namespace sfui {
    /**
     * @brief UI页面的智能指针类型。
     * @tparam PageType 页面类型。
     */
    template<typename PageType>
    using PagePtr = std::unique_ptr<PageType>;


    template<typename PageType>
    inline PagePtr<PageType> makePage() {
        return std::make_unique<PageType>();
    }

    /**
         * @brief 创建一个新的页面实例。
         * @tparam PageType 页面类型。
         * @tparam Args 构造参数类型。
         * @param args 转发给页面构造函数的参数。
         * @return 创建的页面智能指针。
         */
    template<typename PageType, typename... Args>
    inline PagePtr<PageType> makePage(Args &&... args) {
        return std::make_unique<PageType>(std::forward<Args>(args)...);
    }

    /**
     * @brief 页面标题到页面指针的映射表。
     */
    using PageMap = std::unordered_map<Title, PagePtr<Page> >;

    /**
     * @brief 表示窗口大小的类型。
     */
    using WindowSize = sf::Vector2u;

    /**
     * @brief 表示窗口状态（窗口/全屏）。
     */
    enum class WindowState {
        Windowed,  ///< 窗口模式
        Fullscreen ///< 全屏模式
    };

    /**
     * @class Window
     * @brief 窗口类，负责窗口创建、页面管理、事件循环、全屏切换等。
     */
    class Window {
    public:
        /**
        * @brief 构造窗口对象，初始化窗口和屏幕参数。
        * @param width 窗口宽度。
        * @param height 窗口高度。
        * @param windowState 初始窗口状态。
        * @param framerateLimit 帧率上限。
        * @param verticalSyncEnabled 是否启用垂直同步。
        */
        Window(const int &width, const int &height, const WindowState &windowState,
               const int &framerateLimit, const bool &verticalSyncEnabled);

        /**
         * @brief 析构函数。
         */
        ~Window() = default;

        /**
         * @brief 初始化窗口参数。
         * @param framerateLimit 帧率上限。
         * @param verticalSyncEnabled 是否启用垂直同步。
         */
        void setFramerate(const int &framerateLimit, const bool &verticalSyncEnabled);

        /**
         * @brief 向窗口添加页面。
         * @param pageTitle 页面标题。
         * @param page 页面指针。
         */
        void addPage(const Title &pageTitle, PagePtr<Page> page);

        /**
         * @brief 显示首页并进入主循环。
         * @param firstPageTitle 首页标题。
         */
        void startShow(const Title &firstPageTitle);

        /**
         * @brief 切换到指定页面。
         * @param pageTitle 目标页面标题。
         */
        void requestPageSwitch(const Title &pageTitle);

        /**
         * @brief 获取底层SFML窗口对象。
         * @return SFML窗口引用。
         */
        sf::RenderWindow &getSfRenderWindow();

        /**
         * @brief 获取当前窗口大小。
         * @return 窗口大小。
         */
        WindowSize getWindowSize() const;

        /**
         * @brief 获取屏幕分辨率（桌面分辨率）。
         * @return 屏幕分辨率引用。
         */
        const WindowSize &getScreenSize() const;

        const sf::Event &getEvent() const { return m_event; }

    private:
        sf::RenderWindow m_sf_renderWindow; ///< SFML窗口对象
        WindowSize m_windowSize;            ///< 当前窗口大小
        WindowSize m_screenSize;            ///< 屏幕分辨率
        PageMap m_pages;                    ///< 页面映射表
        Title m_nowPageTitle;               ///< 当前页面标题
        sf::Event m_event;                  ///< 当前事件
        WindowState m_windowState;          ///< 当前窗口状态
        int m_framerateLimit = 60;          ///< 帧率上限
        bool m_verticalSyncEnabled = false; ///< 是否启用垂直同步

        /**
         * @brief 更新当前页面视图。
         */
        void updateView();

        /**
         * @brief 处理窗口和页面事件，收到关闭事件时关闭窗口。
         */
        void procesMessage();

        /**
         * @brief 处理实时输入。
         */
        void handleRealTimeInput() const;

        /**
         * @brief 处理SFML事件输入。
         */
        void handleEventInput();

        /**
         * @brief 绘制当前帧到窗口。
         */
        void drawFrame();

        /**
         * @brief 切换窗口/全屏模式。
         */
        void toggleFullscreen();

        /**
         * @brief 切换到全屏模式。
         */
        void toFullscreen();

        /**
         * @brief 切换到窗口模式。
         */
        void toWindowed();
    };
}
