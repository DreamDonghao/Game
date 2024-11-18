#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>

namespace sfui {

    using Key = sf::Keyboard::Key;
    using Action = std::function<void()>;
    // ˲����Ϣ���¼���
    class ActiveKeyBinding {
    public:
        ActiveKeyBinding() {};
        // ��˲����Ϣ���¼�
        void bindKey(Key key, Action action) {
            keyBindings[key] = action;
        }

        // �����Ϣ��ִ����Ϣ��Ӧ���¼�
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