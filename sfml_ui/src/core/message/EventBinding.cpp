#include <EventBinding.hpp>

namespace sfui {

    EvectBingding::EvectBingding() = default;

    // ��˲����Ϣ���¼�
    void EvectBingding::bindEvent(Key key, Action action) {
        m_keyBindings[key] = action;
    }
    void EvectBingding::bindEvent(MouseButton mouseButton, Area *const area, Action action) {
        m_mouseBindings[mouseButton].push_back(std::make_pair(area, action));
    }
    // �����Ϣ��ִ����Ϣ��Ӧ���¼�
    void EvectBingding::update(sf::Event event) {
        // ��������¼�
        if (event.type == sf::Event::KeyPressed) {

            if (m_keyBindings.find(event.key.code) != m_keyBindings.end()) {
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

}