/**
 * @file EventBinding.cpp
 * @brief 实现EvectBingding类，负责事件与行为的绑定与触发。
 */
#include <EventBinding.hpp>
#include <utility>

namespace sfui {
    EvectBingding::EvectBingding() = default;

    void EvectBingding::bindEvent(Key key, Action action) {
        m_keyBindings[key] = std::move(action);
    }

    void EvectBingding::bindEvent(MouseButton mouseButton, const Area *const area, const Action &action) {
        m_mouseButtonBindings[mouseButton].emplace_back(area, action);
    }

    void EvectBingding::update(const sf::Event &event) {
        // 处理键盘事件
        if (event.type == sf::Event::KeyPressed) {
            if (m_keyBindings.contains(event.key.code)) {
                m_keyBindings[event.key.code]();
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (m_mouseBinding.contains(event.mouseButton.button)) {
                m_mouseBinding[event.mouseButton.button]();
            }
        }
        // 处理按钮点击事件
        if (event.type == sf::Event::MouseButtonPressed) {
            for (const auto &[buttonArea, action]
                 : m_mouseButtonBindings[event.mouseButton.button]) {
                if (buttonArea->isInArea(event.mouseButton.x, event.mouseButton.y)) {
                    action();
                }
            }
        }
    }
}
