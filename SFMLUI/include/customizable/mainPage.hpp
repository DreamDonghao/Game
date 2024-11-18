#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <iostream>

namespace sfui {
    // 测试界面
    class TestPage :public ControlPage {
    private:

    public:
        TestPage() {
            setBackgroundColor(sf::Color(0, 0, 0));

        };
        void init() override {

            // 创建一个矩形
            rectangle = sf::RectangleShape(sf::Vector2f(500, 500)); // 矩形大小：200x100
            // 设置矩形的位置
            rectangle.setPosition(0, 0);
            // 设置矩形颜色
            rectangle.setFillColor(sf::Color::Blue); // 填充颜色：蓝色
            activeKeyBinding.bindKey(Key::A, []() {std::cout << "A\n"; });
        };
    private:
        sf::RectangleShape rectangle;
        sf::Clock clock;
        // 处理事件
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