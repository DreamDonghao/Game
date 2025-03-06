#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>

namespace sfui {
    // 按键状态
    using Key = sf::Keyboard::Key;
    // 行为
    using Action = std::function<void()>;

    // 按键状态与行为的映射
    class ActiveKeyBinding {
    public:
        // 构造函数
        ActiveKeyBinding();

        // 建立映射
        void bindKey(Key key, Action action);

        // 检查按键状态并执行对应的行为
        void update();

    private:
        //存储映射
        std::unordered_map<Key, Action> keyBindings;
    };
}