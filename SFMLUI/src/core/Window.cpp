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
        //�л����׽���
        requestPageSwitch(firstPageTitle);

        //�������¸ô��ڣ�ֱ������ر�
        while (m_window.isOpen()) {
            // ��ȡ������Ϣ
            procesMessage();

            // ��ʾһ֡�Ļ���
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


    //        if (event.type == sf::event::resized) {
    //            // ��̬������ͼ
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