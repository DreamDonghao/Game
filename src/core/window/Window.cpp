#include <Window.hpp>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <Page.hpp>
#include <thread>

namespace sfui {
    Window::Window(const int &width, const int &height, const WindowState &windowState,
                   const int &framerateLimit, const bool &verticalSyncEnabled)
        : m_event(), m_windowState(windowState), m_framerateLimit(framerateLimit),
          m_verticalSyncEnabled(verticalSyncEnabled) {
        // 获取屏幕大小
        const sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
        m_screenSize.x = desktopMode.width;
        m_screenSize.y = desktopMode.height;

        m_windowSize = WindowSize(width, height);
        if (windowState == WindowState::Windowed) {
            m_sf_renderWindow.create(sf::VideoMode(width, height), "");
        } else {
            m_sf_renderWindow.create(sf::VideoMode::getDesktopMode(), "", sf::Style::Fullscreen);
        }
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
    }


    void Window::setFramerate(const int &framerateLimit, const bool &verticalSyncEnabled) {
        m_framerateLimit = framerateLimit;
        m_verticalSyncEnabled = verticalSyncEnabled;
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
    }


    void Window::addPage(const Title &pageTitle, PagePtr<Page> page) {
        m_pages[pageTitle] = std::move(page);
    }


    void Window::startShow(const Title &firstPageTitle) {
        //切换到首界面
        requestPageSwitch(firstPageTitle);
        m_sf_renderWindow.setTitle(m_nowPageTitle);
        //持续更新该窗口，直到点击关闭
        while (m_sf_renderWindow.isOpen()) {
            // 获取并处理窗口消息
            procesMessage();

            // 显示一帧的画面
            drawFrame();
        }
    }


    void Window::procesMessage() {
        // 处理窗口实时消息
        handleRealTimeInput();
        // 处理页面实时消息
        m_pages[m_nowPageTitle]->executeKeyPressOnce();

        m_pages[m_nowPageTitle]->update();

        while (m_sf_renderWindow.pollEvent(m_event)) {
            // 处理窗口事件消息
            handleEventInput();
            // 处理页面事件消息
            m_pages[m_nowPageTitle]->executeEventBinding(m_event);
            // 更新界面内容
            m_pages[m_nowPageTitle]->updateByMessage();
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


    void Window::handleRealTimeInput() const {
    }


    void Window::drawFrame() {
        updateView();
        m_sf_renderWindow.clear(m_pages[m_nowPageTitle]->getBackgroundColor());
        // 更新页面，并把页面的图形加载到窗口
        m_pages[m_nowPageTitle]->updateFrame();
        // 显示当前窗口的画面
        m_sf_renderWindow.display();
    }

    void Window::requestPageSwitch(const Title &pageTitle) {
        // 检测要切换页面是否存在，若不存在，抛出一个异常
        try {
            if (!m_pages.contains(pageTitle)) {
                throw std::runtime_error("Page don't exist!!!");
            }
        } catch (const std::runtime_error &err) {
            std::wcerr << "Exception: " << pageTitle << err.what() << std::endl;
            return;
        }

        m_nowPageTitle = pageTitle;
        m_sf_renderWindow.setTitle(m_nowPageTitle);
        // 初始化界面
        m_pages[m_nowPageTitle]->init();
    }


    sf::RenderWindow &Window::getSfRenderWindow() {
        return m_sf_renderWindow;
    }


    WindowSize Window::getWindowSize() const {
        //return m_windowSize;
        return m_sf_renderWindow.getSize();
    }


    const WindowSize &Window::getScreenSize() const {
        return m_screenSize;
    }


    void Window::updateView() {
        m_pages[m_nowPageTitle]->updateView();
    }


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


    void Window::toFullscreen() {
        m_windowState = WindowState::Fullscreen;
        //m_windowSize = m_sf_renderWindow.getSize();
        m_sf_renderWindow.create(
            sf::VideoMode::getDesktopMode(),
            "", sf::Style::Fullscreen
        );
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
    }


    void Window::toWindowed() {
        m_windowState = WindowState::Windowed;
        m_sf_renderWindow.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), "");
        m_sf_renderWindow.setVerticalSyncEnabled(m_verticalSyncEnabled);
        m_sf_renderWindow.setFramerateLimit(m_framerateLimit);
    }
}
