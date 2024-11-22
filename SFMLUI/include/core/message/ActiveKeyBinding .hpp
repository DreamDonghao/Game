#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>

namespace sfui {
    // ������Ϣ
    using Key = sf::Keyboard::Key;
    // �¼�
    using Action = std::function<void()>;

    // ˲����Ϣ���¼���
    class ActiveKeyBinding {
    public:
        ActiveKeyBinding();
        // ��˲����Ϣ���¼�
        void bindKey(Key key, Action action);
        // �����Ϣ��ִ����Ϣ��Ӧ���¼�
        void update();

    private:
        std::unordered_map<Key, Action> keyBindings;
    };
}