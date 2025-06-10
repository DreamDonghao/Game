#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <button.hpp>
#include <utility>

namespace sfui {
    /**
     * @brief 行为类型，表示一个无参数的可调用对象
     */
    using Action = std::function<void()>;
    // 键盘按键类型
    using Key = sf::Keyboard::Key;
    // 鼠标按键类型
    using MouseButton = sf::Mouse::Button;

    /**
     * @brief 按键和鼠标事件与行为的映射类
     *
     * 支持键盘、鼠标按钮、鼠标按钮+区域的事件绑定。
     */
    class EvectBingding {
    public:
        /**
         * @brief 构造函数，初始化事件绑定表
         */
        EvectBingding();

        /**
         * @brief 绑定键盘事件与行为
         * @param key 需要绑定的按键
         * @param action 按下该按键时执行的行为
         */
        void bindEvent(Key key, Action action);

        /**
         * @brief 绑定鼠标按钮事件与行为
         * @param mouseButton 鼠标按钮
         * @param action 按下该按钮时执行的行为
         */
        void bindEvent(MouseButton mouseButton, Action action) {
            m_mouseBinding[mouseButton] = std::move(action);
        }

        /**
         * @brief 绑定鼠标按钮+区域事件与行为
         * @param mouseButton 鼠标按钮
         * @param area 区域指针
         * @param action 在区域内点击该按钮时执行的行为
         */
        void bindEvent(MouseButton mouseButton, const Area *area, const Action& action);

        /**
         * @brief 检查事件并执行对应的行为
         * @param event SFML事件
         */
        void update(sf::Event event);

    private:
        std::unordered_map<Key, Action> m_keyBindings;  ///< 键盘事件映射表
        std::unordered_map<MouseButton, Action> m_mouseBinding; ///< 鼠标按钮事件映射表
        std::unordered_map<MouseButton, std::vector<std::pair<const Area*, Action>>> m_mouseButtonBindings; ///< 鼠标按钮+区域事件映射表
    };
}
