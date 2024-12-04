#pragma once
#include <ComplexPage.hpp>
#include <FrameAnimatedSprite.hpp>
#include <TimeAnimatedSprite.hpp>
#include <print>
#include <Interactive.hpp>
#include <SFML/Network.hpp>
namespace sfui {
    // 测试界面
    class TestPage :public ComplexPage {
        TextureItem image;
        TextureItem image2;
        Button WindowButton;
        Button ViewButton;
        Interactive ib;
        float x = 0;
        float y = 0;
    public:
        TestPage() = default;

        // 初始化界面元素
        void initializePageElements() override {
            image.init("images/unspecified.png", 10000, 10000, -5000, -5000);
            image2.init("images/unspecified.png", 100, 100, x, y);
            setViewCenter(x, y);
            WindowButton.init(0, 0, 300, 300, "images/unspecified.png");
            ViewButton.init(0, 0, 300, 300, "images/unspecified.png");
            ib.init(0, 0, 500, 500, "images/unspecified.png");
        }

        // 初始化消息-事件映射
        void initMessageBinding() override {
            
            eventMap(sf::Mouse::Button::Left, WindowButton.getArea(), []() {std::println("button"); });
            activeMap(Key::B, [&]() {std::println("B"); });
            activeMap(Key::W, [&]() { --y; });
            activeMap(Key::A, [&]() { --x; });
            activeMap(Key::S, [&]() { ++y; });
            activeMap(Key::D, [&]() { ++x; });
            eventMap(sf::Mouse::Button::Left, ib.getArea(), []() {std::println("interActive"); });
            eventMap(Key::P, [&]() {requestPageSwitch(TitleName("2")); });
            eventMap(Key::O, [&]() {requestPageSwitch(TitleName("1")); });
        }

        // 执行界面逻辑
        void update() override {
            //std::println("{} {}", x, y);
            image2.setPosition(x, y);
            setViewCenter(x, y);
            ib.updateArea(x, y,getWindowSize().x,getWindowSize().y);
        }

        // 渲染页面内容到窗口
        void render() override {
           drawForView(image);
           drawForView(image2);
           drawForWindow(WindowButton);
           drawForView(ib);
        }
    };
}