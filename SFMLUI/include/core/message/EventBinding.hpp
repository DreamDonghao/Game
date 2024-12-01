#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <button.hpp>

namespace sfui {
    // �¼�
    using Action = std::function<void()>;

    using Key = sf::Keyboard::Key;

    using MouseButton = sf::Mouse::Button;

    class EvectBingding {
    public:
        EvectBingding() {}

        // ��˲����Ϣ���¼�
        void bindEvent(Key key, Action action) {
            m_keyBindings[key] = action;
        }
        void bindEvent(MouseButton mouseButton,Area *const area, Action action) {
            m_mouseBindings[mouseButton].push_back(std::make_pair(area, action));
        }
        // �����Ϣ��ִ����Ϣ��Ӧ���¼�
        void update(sf::Event event) {
            // ��������¼�
            if (event.type == sf::Event::KeyPressed) {
               
                if (m_keyBindings.find(event.key.code)!=m_keyBindings.end()) {
                    m_keyBindings[event.key.code]();
                }
               
            }

            // ����ť����¼�
            if (event.type == sf::Event::MouseButtonPressed) {
                for (const auto &[buttonArea, action] : m_mouseBindings[event.mouseButton.button]) {
                    if (buttonArea->isInArea(event.mouseButton.x, event.mouseButton.y)) {
                        action();
                    }
                }
            }
        }

    private:

        std::unordered_map<Key, Action> m_keyBindings;  // ���̰������¼���ӳ��


        std::unordered_map<sf::Mouse::Button, std::vector<std::pair<Area*, Action>>> m_mouseBindings;

    };
}