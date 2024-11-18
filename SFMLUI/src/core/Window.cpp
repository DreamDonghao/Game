#include <Window.hpp>
#include <iostream>
#include <Windows.h>

namespace sfui {

    Window::Window(const int &width, const int &heigth) {
        sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
        m_maxWindowSize.x = desktopMode.width;
        m_maxWindowSize.y = desktopMode.height;
        m_window.create(sf::VideoMode(width, heigth), "" );
    }

    void Window::addPage(const Title &pageTitle, PagePtr<Page> page) {
        m_pages[pageTitle] = move(page);
        m_pages[pageTitle]->setWindow(this);
    }

    void Window::startShow(const Title &firstPageTitle) {
        //切换到首界面
        requestPageSwitch(firstPageTitle);

        //持续更新该窗口，直到点击关闭
        while (m_window.isOpen()) {
            // 获取窗口消息
            procesMessage();

            // 显示一帧的画面
            drawFrame();
        }
    }
    void Window::procesMessage() {
        handleRealTimeInput();
        while (m_window.pollEvent(m_event)) {
            handleEventInput();
            m_pages[m_nowPageTitle]->handleEventInput(m_event);
        }
    }
    void Window::handleEventInput() {
        if (m_event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
    void Window::handleRealTimeInput() {
        m_pages[m_nowPageTitle]->handleRealTimeInput();
    }
    void Window::drawFrame() {
        updateView();
        // 更新页面，并把页面的图形加载到窗口
        m_pages[m_nowPageTitle]->updateFrame();
        // 显示当前窗口的画面
        m_window.display();
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
        m_window.setTitle(m_nowPageTitle);
        // 初始化界面
        m_pages[m_nowPageTitle]->init();
        // 根据界面视图调整窗口
        m_window.setView(m_pages[m_nowPageTitle]->getView());
    }


    sf::RenderWindow &Window::getWindow() {
        return m_window;
    }

    const WindowSize Window::getWindowSize() {
        return m_window.getSize();
    }
    const WindowSize &Window::getMaxWindowSize() const {
        return m_maxWindowSize;
    }
    void Window::updateView() {
        m_pages[m_nowPageTitle]->updateView();
        m_window.setView(m_pages[m_nowPageTitle]->getView());
    }


    //        if (event.type == sf::event::resized) {
    //            // 动态调整视图
    //            sf::view view(sf::floatrect(0, 0, event.size.width, event.size.height));
    //            m_window.setview(view);
    //        }
    //    }    
    //    std::cout << (std::to_string(size.x) + "   " + std::to_string(size.y)) << std::endl;
    //    
    //    m_window.clear(m_backbackgroundcolor);
    //    m_window.draw(sizetext);
    //    
    //    m_window.display();
    ////}
}