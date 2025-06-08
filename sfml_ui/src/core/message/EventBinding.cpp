/**
 * @file EventBinding.cpp
 * @brief 实现EvectBingding类，负责事件与行为的绑定与触发。
 */
#include <EventBinding.hpp>
#include <utility>
#include <print>
namespace sfui {
    /**
     * @brief 构造函数，初始化事件绑定表
     */
    EvectBingding::EvectBingding() = default;
    /**
     * @brief 绑定瞬间消息与事件
     * @param key 需要绑定的按键
     * @param action 按下该按键时执行的行为
     */
    void EvectBingding::bindEvent(Key key, Action action) {
        m_keyBindings[key] = std::move(action);
    }
    /**
     * @brief 绑定鼠标按钮+区域事件与行为
     * @param mouseButton 鼠标按钮
     * @param area 区域指针
     * @param action 在区域内点击该按钮时执行的行为
     */
    void EvectBingding::bindEvent(MouseButton mouseButton, const Area *const area, const Action& action) {
        m_mouseButtonBindings[mouseButton].emplace_back(area, action);
    }
    /**
     * @brief 检查消息并执行消息对应的事件
     * @param event SFML事件
     */
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
