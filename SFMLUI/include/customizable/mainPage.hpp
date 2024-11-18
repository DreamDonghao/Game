#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <iostream>

namespace sfui {
    // ���Խ���
    class TestPage :public ControlPage {
    private:

    public:
        TestPage() {
            setBackgroundColor(sf::Color(0, 0, 0));

        };
        void init() override {

            // ����һ������
            rectangle = sf::RectangleShape(sf::Vector2f(500, 500)); // ���δ�С��200x100
            // ���þ��ε�λ��
            rectangle.setPosition(0, 0);
            // ���þ�����ɫ
            rectangle.setFillColor(sf::Color::Blue); // �����ɫ����ɫ
            activeKeyBinding.bindKey(Key::A, []() {std::cout << "A\n"; });
        };
    private:
        sf::RectangleShape rectangle;
        sf::Clock clock;
        // �����¼�
        void handleEventInput(const sf::Event &windowEvent) override {
                if (windowEvent.key.code == sf::Keyboard::F) {
                    
                }
        }
        // ��Ⱦҳ�����ݵ�����
        void render() override {
            mp_window->getWindow().clear(m_backgroundColor);
            mp_window->getWindow().draw(rectangle);
        };
        
    };

}