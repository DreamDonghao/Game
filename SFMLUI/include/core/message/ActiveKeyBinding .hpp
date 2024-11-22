#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>

namespace sfui {
    // 按键消息
    using Key = sf::Keyboard::Key;
    // 事件
    using Action = std::function<void()>;

    // 瞬间消息与事件绑定
    class ActiveKeyBinding {
    public:
        ActiveKeyBinding();
        // 绑定瞬间消息与事件
        void bindKey(Key key, Action action);
        // 检查消息并执行消息对应的事件
        void update();

    private:
        std::unordered_map<Key, Action> keyBindings;
    };
}