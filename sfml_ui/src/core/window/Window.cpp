#include <Window.hpp>
#include <print>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <Page.hpp>

namespace sfui {

    Window::Window(const int &width, const int &heigth, const WindowState &winsowState)
        :m_winsowState(winsowState), m_event() {
        sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
        m_screenSize.x = desktopMode.width;
        m_screenSize.y = desktopMode.height;
        m_windowSize = WindowSize(width, heigth);
        if (winsowState == WindowState::Windowed) {
            m_sf_renderWindow.create(sf::VideoMode(width, heigth), "");
        } else {
            m_sf_renderWindow.create(sf::VideoMode::getDesktopMode(),
                "", sf::Style::Fullscreen);
        }
    }

    bool Window::init(const int &framerateLimit, const bool &verticalSyncEnabled) {
        m_framerateLimit = framerateLimit;
        m_verticalSyncEnabled = verticalSyncEnabled;
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
        return false;
    }

    void Window::addPage(const Title &pageTitle, PagePtr<Page> page) {
        m_pages[pageTitle] = move(page);
        m_pages[pageTitle]->setWindow(this);
        m_pages[pageTitle]->setMouseWindow(&m_sf_renderWindow);
    }

    void Window::startShow(const Title &firstPageTitle) {
        //切换到首界面
        requestPageSwitch(firstPageTitle);
        m_sf_renderWindow.setTitle(m_nowPageTitle);
        //持续更新该窗口，直到点击关闭
        while (m_sf_renderWindow.isOpen()) {

            // 获取窗口消息
            procesMessage();

            // 更新界面内容
            m_pages[m_nowPageTitle]->update();

            // 显示一帧的画面
            drawFrame();
        }
    }
    //处理窗口和窗口当前界面的消息
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
        }
    }
    void Window::handleEventInput() {
        if (m_event.type == sf::Event::Closed) {
            m_sf_renderWindow.close();
        } else if (m_event.type == sf::Event::KeyPressed) {
            if (m_event.key.code == sf::Keyboard::F11) {
                toggleFullscreen();
            }
        }
    }
    void Window::handleRealTimeInput() {

    }

    void Window::drawFrame() {
        updateView();
        // 更新页面，并把页面的图形加载到窗口
        m_pages[m_nowPageTitle]->updateFrame();
        // 显示当前窗口的画面
        m_sf_renderWindow.display();
        m_sf_renderWindow.clear(m_pages[m_nowPageTitle]->getBackgroundColor());

    }

    void Window::requestPageSwitch(const Title &pageTitle) {
        // 检测要切换页面是否存在，若不存在，抛出一个异常
        try {
            if (m_pages.find(pageTitle) == m_pages.end()) {
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


    sf::RenderWindow &Window::getSfRenderWindow() {
        return m_sf_renderWindow;
    }

    const WindowSize Window::getWindowSize() {
        //return m_windowSize;
        return m_sf_renderWindow.getSize();
    }
    const WindowSize &Window::getScreenSize() const {
        return m_screenSize;
    }
    void Window::updateView() {
        m_pages[m_nowPageTitle]->updateView();
        //m_sf_renderWindow.setView(m_pages[m_nowPageTitle]->getView());
    }

    // 切换窗口模式
    void Window::toggleFullscreen() {
        if (m_winsowState == WindowState::Windowed) {
            toFullscreen();
        } else {
            toWindowed();
        }
        // 在窗口切换时，会将窗口标题清除，即使全屏模式并看不到窗口标题，但是返回桌面在任
        // 务栏仍可以看到窗口标题，因此在切换窗口后应将窗口标题重新设置
        m_sf_renderWindow.setTitle(m_nowPageTitle);
    }

    // 切换为全屏模式
    void Window::toFullscreen() {
        m_winsowState = WindowState::Fullscreen;
        m_windowSize = m_sf_renderWindow.getSize();
        m_sf_renderWindow.create(sf::VideoMode::getDesktopMode(),
            "", sf::Style::Fullscreen);
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
    }

    //切换为窗口模式
    void Window::toWindowed() {
        m_winsowState = WindowState::Windowed;
        m_sf_renderWindow.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), "");
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
    }
}