#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <button.hpp>

namespace sfui {
    // �¼�
    using Action = std::function<void()>;

    // ���̰���
    using Key = sf::Keyboard::Key;

    // ��갴��
    using MouseButton = sf::Mouse::Button;

    // �¼���Ϣ�������
    class EvectBingding {
    public:
        EvectBingding();

        // ��˲����Ϣ���¼�
        void bindEvent(Key key, Action action);
        void bindEvent(MouseButton mouseButton, Area *const area, Action action);

        // �����Ϣ��ִ����Ϣ��Ӧ���¼�
        void update(sf::Event event);

    private:

        std::unordered_map<Key, Action> m_keyBindings;  // ���̰������¼���ӳ��

        std::unordered_map<MouseButton, std::vector<std::pair<Area*, Action>>> m_mouseBindings;

    };
}