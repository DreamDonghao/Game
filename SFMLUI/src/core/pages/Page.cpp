#include <Page.hpp>
#include <Window.hpp>
namespace sfui {
    Title TitleName(const std::string &str) {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), nullptr, 0);
        std::wstring wstr(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstr[0], size_needed);
        return wstr;
    }


    void Page::updateFrame() {
        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ
        updateView();
        // ��Ⱦҳ�����ݵ�����
        render();
    }

    void Page::setWindow(Window *const p_window) {
        mp_window = p_window;
    }

    void Page::setMouseWindow(sf::RenderWindow *const p_sfml_RenderWindow) {
        m_mouse.setWindow(p_sfml_RenderWindow);
    }


    void Page::init() {
        // ��ʼ������Ԫ��
        initializePageElements();
       
        initMessageBinding();
    }

    void Page::activeMap(Key key, Action action) {
        m_activeKeyBinding.bindKey(key, action);
    }

    void Page::eventMap(Key key, Action action) {
        m_eventBinding.bindEvent(key, action);
    }
    void Page::eventMap(sf::Mouse::Button mouseButton,Area *const area, Action action) {
        m_eventBinding.bindEvent(mouseButton, area, action);
    }

    void Page::executeKeyPressOnce() {
        m_activeKeyBinding.update();
        
    }
    void Page::executeEventBinding(const sf::Event event) {
        m_eventBinding.update(event);
    }

    sf::Color Page::getBackgroundColor() const { return m_backgroundColor; }

    void Page::setBackgroundColor(const sf::Color &backgroundColor) {
        m_backgroundColor = backgroundColor;
    }

    void Page::requestPageSwitch(const Title &targetPageTitle) {
        mp_window->requestPageSwitch(targetPageTitle);
    }
}