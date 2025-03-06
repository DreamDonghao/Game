#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>

namespace sfui {
    // ����״̬
    using Key = sf::Keyboard::Key;
    // ��Ϊ
    using Action = std::function<void()>;

    // ����״̬����Ϊ��ӳ��
    class ActiveKeyBinding {
    public:
        // ���캯��
        ActiveKeyBinding();

        // ����ӳ��
        void bindKey(Key key, Action action);

        // ��鰴��״̬��ִ�ж�Ӧ����Ϊ
        void update();

    private:
        //�洢ӳ��
        std::unordered_map<Key, Action> keyBindings;
    };
}