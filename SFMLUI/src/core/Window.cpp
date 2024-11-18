#include <Window.hpp>
#include <iostream>
#include <Windows.h>

namespace sfui {

    Window::Window(const int &width, const int &heigth, const WindowState &winsowState)
    :m_winsowState(winsowState){
        sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
        m_maxWindowSize.x = desktopMode.width;
        m_maxWindowSize.y = desktopMode.height;
        m_windowSize = WindowSize(width, heigth);
        if (winsowState == WindowState::Windowed) {
            m_window.create(sf::VideoMode(width, heigth), "");
        } else {
            m_window.create(sf::VideoMode::getDesktopMode(),
                "", sf::Style::Fullscreen);
        }
    }

    void Window::addPage(const Title &pageTitle, PagePtr<Page> page) {
        m_pages[pageTitle] = move(page);
        m_pages[pageTitle]->setWindow(this);
    }

    void Window::startShow(const Title &firstPageTitle) {
        //�л����׽���
        requestPageSwitch(firstPageTitle);
        m_window.setTitle(m_nowPageTitle);
        //�������¸ô��ڣ�ֱ������ر�
        while (m_window.isOpen()) {
            // ��ȡ������Ϣ
            procesMessage();

            // ��ʾһ֡�Ļ���
            drawFrame();
        }
    }
    //�����ںʹ��ڵ�ǰ�������Ϣ
    void Window::procesMessage() {
        // ������ʵʱ��Ϣ
        handleRealTimeInput();
        // ����ҳ��ʵʱ��Ϣ
        m_pages[m_nowPageTitle]->executeKeyPressOnce();
        while (m_window.pollEvent(m_event)) {
            // �������¼���Ϣ
            handleEventInput();
            // ����ҳ���¼���Ϣ
            m_pages[m_nowPageTitle]->handleEventInput(m_event);
        }
    }
    void Window::handleEventInput() {
        if (m_event.type == sf::Event::Closed) {
            m_window.close();
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
        // ����ҳ�棬����ҳ���ͼ�μ��ص�����
        m_pages[m_nowPageTitle]->updateFrame();
        // ��ʾ��ǰ���ڵĻ���
        m_window.display();
    }

    void Window::requestPageSwitch(const Title &pageTitle) {
        // ���Ҫ�л�ҳ���Ƿ���ڣ��������ڣ��׳�һ���쳣
        try {
            if (m_pages.find(pageTitle) == m_pages.end()) {
                throw std::runtime_error("Page don't exist!!!");
            }
        } catch (const std::runtime_error &err) {
            std::wcerr << "Exception: " << pageTitle << err.what() << std::endl;
        }

        m_nowPageTitle = pageTitle;
        m_window.setTitle(m_nowPageTitle);
        // ��ʼ������
        m_pages[m_nowPageTitle]->init();
        // ���ݽ�����ͼ��������
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

    void Window::toggleFullscreen() {
        if (m_winsowState == WindowState::Windowed) {
            toFullscreen();
        } else {
            toWindowed();
        }
    }

    void Window::toFullscreen() {
        m_winsowState = WindowState::Fullscreen;
        m_windowSize = m_window.getSize();
        //m_window.close();
        m_window.create(sf::VideoMode::getDesktopMode(),
            "", sf::Style::Fullscreen);
    }
    void Window::toWindowed() {
        m_winsowState = WindowState::Windowed;
        //m_window.close();
        m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), "");
    }
}