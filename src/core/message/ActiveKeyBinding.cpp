/**
 * @file ActiveKeyBinding.cpp
 * @brief 实现ActiveKeyBinding类，负责按键与行为的绑定与触发。
 */
#include <ActiveKeyBinding.hpp>
#include <utility>

namespace sfui {

    ActiveKeyBinding::ActiveKeyBinding()= default;

    void ActiveKeyBinding::update() {
        for (const auto &[key, action] : keyBindings) {
            if (sf::Keyboard::isKeyPressed(key)) {
                action();
            }
        }
    }

    void ActiveKeyBinding::bindKey(const Key key, Action action) {
        keyBindings[key] = std::move(action);
    }

}
