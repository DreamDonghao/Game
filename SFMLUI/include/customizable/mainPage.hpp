#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <iostream>

namespace sfui {

    class MainPage :public InteractivePage {
    private:

    public:
        MainPage() {
            setBackgroundColor(sf::Color(0, 0, 0));

        };
        void init() override {

            // ����һ������
            rectangle = sf::RectangleShape(sf::Vector2f(500, 500)); // ���δ�С��200x100
            // ���þ��ε�λ��
            rectangle.setPosition(0, 0);
            // ���þ�����ɫ
            rectangle.setFillColor(sf::Color::Blue); // �����ɫ����ɫ
        };
    private:
        sf::RectangleShape rectangle;
        sf::Clock clock;
        // �����¼�
        void handleRealTimeInput() override {
            float deltaTime = clock.restart().asSeconds();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                requestPageSwitch(L"2");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                requestPageSwitch(L"1");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                mp_window->getWindow().setSize(mp_window->getMaxWindowSize());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                rectangle.move(100 * deltaTime, 0);
            }
        }
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