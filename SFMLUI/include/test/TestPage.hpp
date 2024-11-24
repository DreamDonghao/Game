#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <random>
#include <iostream>
#include <TextureItem.hpp>
#include <cstdint>
#include <FrameAnimatedSprite.hpp>
#include <TimeAnimatedSprite.hpp>
#include <EventBinding.hpp>
namespace sfui {
    // 测试界面
    class TestPage :public ControlPage {
    private:
       TimeAnimatedSprite as;
        TextureItem t;
        sf::CircleShape circle;
        int i = 0;
        std::vector<TextureItem> ass;
        int x, y;
        int w, h;
    public:
        TestPage() ://---------------
            circle(1) {
            setBackgroundColor(sf::Color(0, 0, 0));
        };

        
        void initializePageElements() override {//初始化界面元素-------------------------------------
           
            as.init(0.01, 1000, 1000, 0,0);
            x = 0;
            y = 0;
            w = 1000;
            h = 1000;
            for (int i = 0; i <= 89; ++i) {
                std::string path("images/gif/frame_");
                as.addTextureItems(path + std::to_string(i) + ".png");
            }
            ass.emplace_back().init("images/unspecified.png", 500, 500, -500, 0);
            ass.emplace_back().init("images/Terraria-logo.png", 500, 500, -500, 0);

            t.init("images/unspecified.png", 500, 500, 100, 100);
            circle.setFillColor(sf::Color::Red);

        }//----------------------------------------------------------------------------------------

        void initActiveKeyBinding()override {//初始化实时消息-事件映射-------------------------------
            m_activeKeyBinding.bindKey(Key::A, [&]() {});
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