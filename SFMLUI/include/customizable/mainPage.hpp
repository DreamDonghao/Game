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

            // 创建一个矩形
            rectangle = sf::RectangleShape(sf::Vector2f(500, 500)); // 矩形大小：200x100
            // 设置矩形的位置
            rectangle.setPosition(0, 0);
            // 设置矩形颜色
            rectangle.setFillColor(sf::Color::Blue); // 填充颜色：蓝色
        };
    private:
        sf::RectangleShape rectangle;
        sf::Clock clock;
        // 处理事件
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
        // 渲染页面内容到窗口
        void render() override {
            mp_window->getWindow().clear(m_backgroundColor);
            mp_window->getWindow().draw(rectangle);
        };
        
    };

}