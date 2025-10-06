/**
 * @file Page.cpp
 * @brief 实现Page类及相关函数，负责界面生命周期、事件绑定、渲染等。
 */
#include <Page.hpp>
#include <Window.hpp>
#include <windows.h>
#include <SFML/System.hpp>

namespace sfui {
    Title strToWstr(const std::string &str) {
        const int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), static_cast<int>(str.size()), nullptr, 0);
        std::wstring wstr(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), static_cast<int>(str.size()), &wstr[0], size_needed);
        return wstr;
    }

    Page::Page(Window *mp_window): mp_window(mp_window), m_mouse(&mp_window->getSfRenderWindow()) {
    }

    void Page::updateFrame() {
        // 根据绑定窗口的大小来更新界面视图
        updateView();
        // 渲染页面内容到窗口
        render();
    }

    void Page::activeMap(const Key key, const Action &action) {
        m_activeKeyBinding.bindKey(key, action);
    }

    void Page::eventMap(const Key key, const Action &action) {
        m_eventBinding.bindEvent(key, action);
    }

    void Page::eventMap(const MouseButton mouseButton, const Action &action) {
        m_eventBinding.bindEvent(mouseButton, action);
    }

    void Page::eventMap(const sf::Mouse::Button mouseButton, const Area *const area, const Action &action) {
        m_eventBinding.bindEvent(mouseButton, area, action);
    }

    void Page::executeKeyPressOnce() {
        m_activeKeyBinding.update();
    }

    void Page::executeEventBinding(const sf::Event &event) {
        m_eventBinding.update(event,mp_window->getSfRenderWindow(),mp_window->getSfRenderWindow().getView());
    }

    sf::Color Page::getBackgroundColor() const { return m_backgroundColor; }

    void Page::updateView() {
        m_windowSize = mp_window->getWindowSize();
        m_view.setSize(
            static_cast<float>(m_windowSize.x),
            static_cast<float>(m_windowSize.y)
        );
        m_view.setCenter(m_worldViewCenter);
        m_view.setSize(m_view.getSize().x, -m_view.getSize().y);
        mp_window->getSfRenderWindow().setView(m_view);
    }

    sf::RenderWindow &Page::getSfRenderWindow() const {
        return mp_window->getSfRenderWindow();
    }

    void Page::beginDrawForView() {
        updateView();
    }

    void Page::beginDrawForWindow() const {
        mp_window->getSfRenderWindow().setView(mp_window->getSfRenderWindow().getDefaultView());
    }

    void Page::setBackgroundColor(const sf::Color &backgroundColor) {
        m_backgroundColor = backgroundColor;
    }

    void Page::requestPageSwitch(const Title &targetPageTitle) const {
        mp_window->requestPageSwitch(targetPageTitle);
    }
}
