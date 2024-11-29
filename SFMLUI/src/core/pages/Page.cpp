#include <Page.hpp>

namespace sfui {
    Title TitleName(const std::string &str) {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), nullptr, 0);
        std::wstring wstr(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstr[0], size_needed);
        return wstr;
    }


    void Page::updateFrame() {
        // 根据绑定窗口的大小来更新界面视图
        updateView();
        // 渲染页面内容到窗口
        render();
    }

    void Page::setWindow(Window *const p_window) {
        mp_window = p_window;
    }

    void Page::setMouseWindow(sf::RenderWindow *const p_sfml_RenderWindow) {
        m_mouse.setWindow(p_sfml_RenderWindow);
    }

    sf::View &Page::getView() {
        return m_view;
    };

    void Page::init() {
        // 初始化界面元素
        initializePageElements();
        // 初始化实时消息-事件映射
        initActiveKeyBinding();
    }

    void Page::executeKeyPressOnce() {
        m_activeKeyBinding.update();
    }

    sf::Color Page::getBackgroundColor() const { return m_backgroundColor; }

    void Page::setBackgroundColor(const sf::Color &backgroundColor) {
        m_backgroundColor = backgroundColor;
    }
}