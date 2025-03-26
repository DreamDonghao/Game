#include <EventBinding.hpp>
#include <utility>
#include <print>
namespace sfui {
    EvectBingding::EvectBingding() = default;
    // 绑定瞬间消息与事件
    void EvectBingding::bindEvent(Key key, Action action) {
        m_keyBindings[key] = std::move(action);
    }
    void EvectBingding::bindEvent(MouseButton mouseButton, const Area *const area, const Action& action) {
        m_mouseButtonBindings[mouseButton].emplace_back(area, action);
    }
    // 检查消息并执行消息对应的事件
    void EvectBingding::update(sf::Event event) {
        // 处理键盘事件
        if (event.type == sf::Event::KeyPressed) {
            if (m_keyBindings.find(event.key.code) != m_keyBindings.end()) {
                m_keyBindings[event.key.code]();
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (m_mouseBinding.find(event.mouseButton.button) != m_mouseBinding.end()) {
                
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
