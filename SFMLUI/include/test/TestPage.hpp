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

        void initActiveKeyBinding() override {//初始化实时消息-事件映射-------------------------------
           
        }//----------------------------------------------------------------------------------------

        void initEventBinding() override {
            m_eventBinding.bindEvent(Key::A, []() {std::printf("A"); });
        }

        void handleEventInput(const sf::Event &windowEvent) override {//处理事件消息----------------
            m_eventBinding.update(windowEvent);
        }//----------------------------------------------------------------------------------------

        void update() override {
           
        }

        void render() override { // 渲染页面内容到窗口-----------------------------------------------
           
           
            
        }//----------------------------------------------------------------------------------------
    };
}