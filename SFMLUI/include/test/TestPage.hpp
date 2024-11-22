#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <random>
#include <iostream>
#include <TextureItem.hpp>
#include <cstdint>
#include <AnimatedSprite.hpp>
namespace sfui {
    // 测试界面
    class TestPage :public ControlPage {
    private:
        AnimatedSprite as;
        TextureItem t;
        sf::CircleShape circle;
        int i = 0;
        std::vector<TextureItem> ass;
    public:
        TestPage() ://---------------
            circle(1) {
            setBackgroundColor(sf::Color(0, 0, 0));
        };

        void initializePageElements() override {//初始化界面元素-------------------------------------

            ass.emplace_back().init("images/unspecified.png", 500, 500, -500, 0);
            ass.emplace_back().init("images/Terraria-logo.png", 500, 500, -500, 0);

            as.init(10, 500, 500, 0,0);

            as.addTextureItems("images/unspecified.png");
            as.addTextureItems("images/1000_1000.png");
            as.addTextureItems("images/500_250.png");
            //as.addTextureItems("images/Terraria-logo.jpg");
            t.init("images/unspecified.png", 500, 500, 100, 100);
            circle.setFillColor(sf::Color::Red);

        }//----------------------------------------------------------------------------------------

        void initActiveKeyBinding()override {//初始化实时消息-事件映射-------------------------------
            m_activeKeyBinding.bindKey(Key::A, [&]() {});
        }//----------------------------------------------------------------------------------------

        void handleEventInput(const sf::Event &windowEvent) override {//处理事件消息----------------
            if (windowEvent.type == sf::Event::EventType::KeyPressed) {
                if (windowEvent.key.code == sf::Keyboard::A) {
                    /*std::print(std::cout, "相对于屏幕坐标({},{})\n", m_mouse.getScreenPosition().x, m_mouse.getScreenPosition().y);
                    std::print(std::cout, "相对于窗口坐标({},{})\n", m_mouse.getWindowPosition().x, m_mouse.getWindowPosition().y);
                    std::print(std::cout, "相对于视图坐标({},{})\n\n", m_mouse.getViewPosition().x, m_mouse.getViewPosition().y);*/
                }
            }
        }//----------------------------------------------------------------------------------------

        void render() override { // 渲染页面内容到窗口-----------------------------------------------
            //mp_window->getWindow().draw(circle);
            
            mp_window->getWindow().draw(as.getSprite());
            Sleep(100);            
            //mp_window->getWindow().draw(ass[(++i) %= 2].getSprite());

        }//----------------------------------------------------------------------------------------
    };

}