#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <ComplexPage.hpp>
#include <FrameAnimatedSprite.hpp>
#include <TimeAnimatedSprite.hpp>
#include <print>
namespace sfui {
    // 测试界面
    class TestPage :public ComplexPage {
        TextureItem image;
        TextureItem image2;
        Button WindowButton;
        Button ViewButton;
        float x = 0;
        float y = 0;
    public:
        TestPage() {

        };

        // 初始化界面元素
        void initializePageElements() override {
            image.init("images/unspecified.png", 10000, 10000, -5000, -5000);
            image2.init("images/unspecified.png", 100, 100, x, y);
            setViewCenter(x, y);
            WindowButton.init(0, 0, 300, 300, "images/unspecified.png");
            ViewButton.init(0, 0, 300, 300, "images/unspecified.png");
        }

        // 初始化消息-事件映射
        void initMessageBinding() override {
            eventMap(Key::A, []() {std::println("A"); });
            eventMap(sf::Mouse::Button::Left, WindowButton.getButtonArea(), []() {std::println("button"); });
            activeMap(Key::B, [&]() {std::println("B"); });
            activeMap(Key::W, [&]() { --y; });
            activeMap(Key::A, [&]() { --x; });
            activeMap(Key::S, [&]() { ++y; });
            activeMap(Key::D, [&]() { ++x; });
        }

        // 执行界面逻辑
        void update() override {
            //std::println("{} {}", x, y);
            image2.setPosition(x, y);
            setViewCenter(x, y);
        }

        // 渲染页面内容到窗口
        void render() override {
           drawForView(image);
           drawForView(image2);
           drawForWindow(WindowButton);
          
        }
    };
}