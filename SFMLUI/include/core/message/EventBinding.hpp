#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <button.hpp>

namespace sfui {
    // 事件
    using Action = std::function<void()>;

    using Key = sf::Keyboard::Key;

    using MouseButton = sf::Mouse::Button;

    class EvectBingding {
    public:
        EvectBingding() {}

        // 绑定瞬间消息与事件
        void bindEvent(Key key, Action action) {
            m_keyBindings[key] = action;
        }
        void bindEvent(MouseButton mouseButton,Area *const area, Action action) {
            m_mouseBindings[mouseButton].push_back(std::make_pair(area, action));
        }
        // 检查消息并执行消息对应的事件
        void update(sf::Event event) {
            // 处理键盘事件
            if (event.type == sf::Event::KeyPressed) {
               
                if (m_keyBindings.find(event.key.code)!=m_keyBindings.end()) {
                    m_keyBindings[event.key.code]();
                }
               
            }

            // 处理按钮点击事件
            if (event.type == sf::Event::MouseButtonPressed) {
                for (const auto &[buttonArea, action] : m_mouseBindings[event.mouseButton.button]) {
                    if (buttonArea->isInArea(event.mouseButton.x, event.mouseButton.y)) {
                        action();
                    }
                }
            }
        }

    private:

        std::unordered_map<Key, Action> m_keyBindings;  // 键盘按键与事件的映射


        std::unordered_map<sf::Mouse::Button, std::vector<std::pair<Area*, Action>>> m_mouseBindings;

    };
}