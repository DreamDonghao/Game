#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>

namespace sfui {

    using Key = sf::Keyboard::Key;
    using Action = std::function<void()>;
    // 瞬间消息与事件绑定
    class ActiveKeyBinding {
    public:
        ActiveKeyBinding() {};
        // 绑定瞬间消息与事件
        void bindKey(Key key, Action action) {
            keyBindings[key] = action;
        }

        // 检查消息并执行消息对应的事件
        void update() {
            for (const auto &[key, action] : keyBindings) {
                if (sf::Keyboard::isKeyPressed(key)) {
                    action(); 
                }
            }
        }

    private:
        std::unordered_map<Key, Action> keyBindings;
    };
}