#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <button.hpp>

namespace sfui {
    // ��Ϊ
    using Action = std::function<void()>;

    // ���̰���
    using Key = sf::Keyboard::Key;

    // ��갴��
    using MouseButton = sf::Mouse::Button;

    // �����¼�����Ϊӳ��
    class EvectBingding {
    public:
        // ���캯��
        EvectBingding();

        // ����ӳ�䣺���̣���Ϊ
        void bindEvent(Key key, Action action);

        // 
        void bindEvent(MouseButton mouseButton, Action action) {
            m_mouseButtonBindings[mouseButton] = action;
        }

        //����ӳ�䣺���&����������Ϊ
        void bindEvent(MouseButton mouseButton, Area *const area, Action action);

        // �����Ϣ��ִ����Ϣ��Ӧ����Ϊ
        void update(sf::Event event);

    private:
        // �洢���̰������ж���ӳ��
        std::unordered_map<Key, Action> m_keyBindings;  

        std::unordered_map<MouseButton, Action> m_mouseButtonBindings;

        // �洢���%������������Ϊ��ӳ��
        std::unordered_map<MouseButton, std::vector<std::pair<Area*, Action>>> m_mouseBindings;

    };
}