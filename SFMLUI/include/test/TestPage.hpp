#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <random>
#include <iostream>
#include <TextureItem.hpp>
#include <cstdint>
namespace sfui {
    // 测试界面
    class TestPage :public ControlPage {
    private:
        TextureItem t;
        sf::CircleShape circle;
    public:
        TestPage() ://---------------
            circle(1),
            t("images/Abc.jpg", 10, 10)
        {
            setBackgroundColor(sf::Color(0, 0, 0));
        };
    

       
        
        
        void initializePageElements() override {//初始化界面元素-------------------------------------
         
            circle.setFillColor(sf::Color::Red);

        }//----------------------------------------------------------------------------------------

        void initActiveKeyBinding()override {//初始化实时消息-事件映射-------------------------------
               m_activeKeyBinding.bindKey(Key::A, [&]() {});
        }//----------------------------------------------------------------------------------------

        void handleEventInput(const sf::Event &windowEvent) override {//处理事件消息----------------
            if(windowEvent.type == sf::Event::EventType::KeyPressed)
            if (windowEvent.key.code == sf::Keyboard::A) {
                /*std::print(std::cout, "相对于屏幕坐标({},{})\n", m_mouse.getScreenPosition().x, m_mouse.getScreenPosition().y);
                std::print(std::cout, "相对于窗口坐标({},{})\n", m_mouse.getWindowPosition().x, m_mouse.getWindowPosition().y);
                std::print(std::cout, "相对于视图坐标({},{})\n\n", m_mouse.getViewPosition().x, m_mouse.getViewPosition().y);*/
            }
        }//----------------------------------------------------------------------------------------
       
        void render() override { // 渲染页面内容到窗口-----------------------------------------------
            mp_window->getWindow().draw(circle);
            mp_window->getWindow().draw(t.getSprite());
        }//----------------------------------------------------------------------------------------
    };

}