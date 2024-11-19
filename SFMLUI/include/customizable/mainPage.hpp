#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <iostream>



namespace sfui {
    // 测试界面
    class TestPage :public InteractivePage {
    public:
        TestPage() {
            setBackgroundColor(sf::Color(0, 0, 0));
        };
    private:
       
        
        
        void initializePageElements() override {//初始化界面元素-------------------------------------
           
            

           
        }//----------------------------------------------------------------------------------------

        void initActiveKeyBinding()override {//初始化实时消息-事件映射-------------------------------
            
        }//----------------------------------------------------------------------------------------

        void handleEventInput(const sf::Event &windowEvent) override {//处理事件消息----------------
            if (windowEvent.key.code == sf::Keyboard::F) {

            }
        }//----------------------------------------------------------------------------------------
       
        void render() override { // 渲染页面内容到窗口-----------------------------------------------
           
        }//----------------------------------------------------------------------------------------
    };

}