#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <button.hpp>

namespace sfui {
    // 事件
    using Action = std::function<void()>;

    // 键盘按键
    using Key = sf::Keyboard::Key;

    // 鼠标按键
    using MouseButton = sf::Mouse::Button;

    // 事件消息与操作绑定
    class EvectBingding {
    public:
        EvectBingding();

        // 绑定瞬间消息与事件
        void bindEvent(Key key, Action action);
        void bindEvent(MouseButton mouseButton, Area *const area, Action action);

        // 检查消息并执行消息对应的事件
        void update(sf::Event event);

    private:

        std::unordered_map<Key, Action> m_keyBindings;  // 键盘按键与事件的映射

        std::unordered_map<MouseButton, std::vector<std::pair<Area*, Action>>> m_mouseBindings;

    };
}