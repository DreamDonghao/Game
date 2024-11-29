#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <FrameAnimatedSprite.hpp>
#include <TimeAnimatedSprite.hpp>
namespace sfui {
    // 测试界面
    class TestPage :public ControlPage {
    
    public:
        TestPage()//---------------
        {
           
        };

        
        void initializePageElements() override {//初始化界面元素-------------------------------------
           
           

        }//----------------------------------------------------------------------------------------

        void initActiveKeyBinding()override {//初始化实时消息-事件映射-------------------------------
           
        }//----------------------------------------------------------------------------------------

        void handleEventInput(const sf::Event &windowEvent) override {//处理事件消息----------------
            if (windowEvent.type == sf::Event::EventType::KeyPressed) {
                if (windowEvent.key.code == sf::Keyboard::A) {
                   
                }
            }
        }//----------------------------------------------------------------------------------------

        void update() override {
           
        }

        void render() override { // 渲染页面内容到窗口-----------------------------------------------
           
           
            
            
          
        }//----------------------------------------------------------------------------------------
    };
}