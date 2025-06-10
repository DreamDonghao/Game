#include <Window.hpp>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <Page.hpp>

namespace sfui {

    /**
     * @brief 构造窗口对象，初始化窗口和屏幕参数。
     * @param width 窗口宽度。
     * @param height 窗口高度。
     * @param windowState 初始窗口状态。
     */
    Window::Window(const int &width, const int &height, const WindowState &windowState)
        :m_event(), m_windowState(windowState) {
        const sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
        m_screenSize.x = desktopMode.width;
        m_screenSize.y = desktopMode.height;
        m_windowSize = WindowSize(width, height);
        if (windowState == WindowState::Windowed) {
            m_sf_renderWindow.create(sf::VideoMode(width, height), "");
        } else {
            m_sf_renderWindow.create(sf::VideoMode::getDesktopMode(),
                "", sf::Style::Fullscreen);
        }
    }

    /**
     * @brief 设置窗口帧率和垂直同步参数。
     * @param framerateLimit 帧率上限。
     * @param verticalSyncEnabled 是否启用垂直同步。
     * @return 始终返回false（可根据实际需求修改）。
     */
    bool Window::init(const int &framerateLimit, const bool &verticalSyncEnabled) {
        m_framerateLimit = framerateLimit;
        m_verticalSyncEnabled = verticalSyncEnabled;
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
        return false;
    }

    /**
     * @brief 添加页面并设置其窗口和鼠标上下文。
     * @param pageTitle 页面标题。
     * @param page 页面指针。
     */
    void Window::addPage(const Title &pageTitle, PagePtr<Page> page) {
        m_pages[pageTitle] = move(page);
        m_pages[pageTitle]->setWindow(this);
        m_pages[pageTitle]->setMouseWindow(&m_sf_renderWindow);
    }

    /**
     * @brief 进入主循环，显示首页并持续刷新。
     * @param firstPageTitle 首页标题。
     */
    void Window::startShow(const Title &firstPageTitle) {
        //切换到首界面
        requestPageSwitch(firstPageTitle);
        m_sf_renderWindow.setTitle(m_nowPageTitle);
        //持续更新该窗口，直到点击关闭
        while (m_sf_renderWindow.isOpen()) {

            // 获取窗口消息
            procesMessage();



            // 显示一帧的画面
            drawFrame();
        }
    }
    /**
     * @brief 处理窗口和页面事件，包括关闭窗口。
     */
    void Window::procesMessage() {
        // 处理窗口实时消息
        handleRealTimeInput();
        // 处理页面实时消息
        m_pages[m_nowPageTitle]->executeKeyPressOnce();

        while (m_sf_renderWindow.pollEvent(m_event)) {
            // 处理窗口事件消息
            handleEventInput();
            // 处理页面事件消息
            m_pages[m_nowPageTitle]->executeEventBinding(m_event);
            // 更新界面内容
            m_pages[m_nowPageTitle]->update();
        }
    }
    /**
     * @brief 处理窗口事件（如关闭、F11切换全屏）。
     */
    void Window::handleEventInput() {
        if (m_event.type == sf::Event::Closed) {
            m_sf_renderWindow.close();
        } else if (m_event.type == sf::Event::KeyPressed) {
            if (m_event.key.code == sf::Keyboard::F11) {
                toggleFullscreen();
            }
        }
    }
    /**
     * @brief 处理实时输入（当前未实现）。
     */
    void Window::handleRealTimeInput() {

    }

    /**
     * @brief 绘制一帧内容到窗口。
     */
    void Window::drawFrame() {
        updateView();
        // 更新页面，并把页面的图形加载到窗口
        m_pages[m_nowPageTitle]->updateFrame();
        // 显示当前窗口的画面
        m_sf_renderWindow.display();
        m_sf_renderWindow.clear(m_pages[m_nowPageTitle]->getBackgroundColor());

    }

    /**
     * @brief 切换到指定页面，若页面不存在则抛出异常。
     * @param pageTitle 目标页面标题。
     */
    void Window::requestPageSwitch(const Title &pageTitle) {
        // 检测要切换页面是否存在，若不存在，抛出一个异常
        try {
            if (!m_pages.contains(pageTitle)) {
                throw std::runtime_error("Page don't exist!!!");
            }
        } catch (const std::runtime_error &err) {
            std::wcerr << "Exception: " << pageTitle << err.what() << std::endl;
        }

        m_nowPageTitle = pageTitle;
        m_sf_renderWindow.setTitle(m_nowPageTitle);
        // 初始化界面
        m_pages[m_nowPageTitle]->init();
    }


    /**
     * @brief 获取底层SFML窗口对象。
     * @return SFML窗口引用。
     */
    sf::RenderWindow &Window::getSfRenderWindow() {
        return m_sf_renderWindow;
    }

    /**
     * @brief 获取当前窗口大小。
     * @return 窗口大小。
     */
    WindowSize Window::getWindowSize() const {
        //return m_windowSize;
        return m_sf_renderWindow.getSize();
    }
    /**
     * @brief 获取屏幕分辨率。
     * @return 屏幕分辨率引用。
     */
    const WindowSize &Window::getScreenSize() const {
        return m_screenSize;
    }
    /**
     * @brief 更新当前页面的视图。
     */
    void Window::updateView() {
        m_pages[m_nowPageTitle]->updateView();
        //m_sf_renderWindow.setView(m_pages[m_nowPageTitle]->getView());
    }

    /**
     * @brief 切换窗口/全屏模式。
     */
    void Window::toggleFullscreen() {
        if (m_windowState == WindowState::Windowed) {
            toFullscreen();
        } else {
            toWindowed();
        }
        // 在窗口切换时，会将窗口标题清除，即使全屏模式并看不到窗口标题，但是返回桌面在任
        // 务栏仍可以看到窗口标题，因此在切换窗口后应将窗口标题重新设置
        m_sf_renderWindow.setTitle(m_nowPageTitle);
    }

    /**
     * @brief 切换到全屏模式。
     */
    void Window::toFullscreen() {
        m_windowState = WindowState::Fullscreen;
        m_windowSize = m_sf_renderWindow.getSize();
        m_sf_renderWindow.create(sf::VideoMode::getDesktopMode(),
            "", sf::Style::Fullscreen);
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
    }

    /**
     * @brief 切换到窗口模式。
     */
    void Window::toWindowed() {
        m_windowState = WindowState::Windowed;
        m_sf_renderWindow.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), "");
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
    }
}
