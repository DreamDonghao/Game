#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <button.hpp>

namespace sfui {
    // 行为
    using Action = std::function<void()>;

    // 键盘按键
    using Key = sf::Keyboard::Key;

    // 鼠标按键
    using MouseButton = sf::Mouse::Button;

    // 按键事件与行为映射
    class EvectBingding {
    public:
        // 构造函数
        EvectBingding();

        // 建立映射：键盘：行为
        void bindEvent(Key key, Action action);

        // 
        void bindEvent(MouseButton mouseButton, Action action) {
            m_mouseButtonBindings[mouseButton] = action;
        }

        //建立映射：鼠标&交互区域：行为
        void bindEvent(MouseButton mouseButton, Area *const area, Action action);

        // 检查消息并执行消息对应的行为
        void update(sf::Event event);

    private:
        // 存储键盘按键与行动的映射
        std::unordered_map<Key, Action> m_keyBindings;  

        std::unordered_map<MouseButton, Action> m_mouseButtonBindings;

        // 存储鼠标%交互区域与行为的映射
        std::unordered_map<MouseButton, std::vector<std::pair<Area*, Action>>> m_mouseBindings;

    };
}