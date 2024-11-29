#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <button.hpp>

namespace sfui {
    // �¼�
    using Action = std::function<void()>;

    using Key = sf::Keyboard::Key;


    class EvectBingding {
    public:
        EvectBingding() {}

        // ��˲����Ϣ���¼�
        void bindEvent(Key key, Action action) {
            m_keyBindings[key] = action;
            m_keyBindings[Key::A]();
        }
        void bindEvent(sf::Mouse::Button mouseButton, Button::ButtonArea buttonArea, Action action) {
            m_mouseBindings[mouseButton].push_back(std::make_pair(buttonArea, action));
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
                    if (buttonArea.isInButtonArea(event.mouseButton.x, event.mouseButton.y)) {
                        action();
                    }
                }
            }

        }

        void update(sf::RenderWindow &window, sf::Event &sf_event) {

        }

        void handleClosed();

    private:

        std::unordered_map<Key, Action> m_keyBindings;  // ���̰������¼���ӳ��


        std::unordered_map<sf::Mouse::Button, std::vector<std::pair<Button::ButtonArea, Action>>> m_mouseBindings;

    };
}