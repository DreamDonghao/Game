#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>

namespace sfui {
    /**
     * @brief 按键类型，等价于SFML的键盘按键
     */
    using Key = sf::Keyboard::Key;
    // 行为类型，表示一个无参数的可调用对象
    using Action = std::function<void()>;

    /**
     * @brief 按键状态与行为的映射类
     *
     * 用于将键盘按键与对应的行为（回调函数）进行绑定，实现按键响应。
     */
    class ActiveKeyBinding {
    public:
        /**
         * @brief 构造函数，初始化按键绑定表
         */
        ActiveKeyBinding();

        /**
         * @brief 绑定按键与行为
         * @param key 需要绑定的按键
         * @param action 按下该按键时执行的行为
         */
        void bindKey(Key key, Action action);

        /**
         * @brief 检查所有已绑定按键的状态，若被按下则执行对应行为
         */
        void update();

    private:
        std::unordered_map<Key, Action> keyBindings; ///< 存储按键与行为的映射表
    };
}
