#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <ComplexPage.hpp>
#include <FrameAnimatedSprite.hpp>
#include <TimeAnimatedSprite.hpp>
#include <print>
namespace sfui {
    // ���Խ���
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

        // ��ʼ������Ԫ��
        void initializePageElements() override {
            image.init("images/unspecified.png", 10000, 10000, -5000, -5000);
            image2.init("images/unspecified.png", 100, 100, x, y);
            setViewCenter(x, y);
            WindowButton.init(0, 0, 300, 300, "images/unspecified.png");
            ViewButton.init(0, 0, 300, 300, "images/unspecified.png");
        }

        // ��ʼ����Ϣ-�¼�ӳ��
        void initMessageBinding() override {
            eventMap(Key::A, []() {std::println("A"); });
            eventMap(sf::Mouse::Button::Left, WindowButton.getButtonArea(), []() {std::println("button"); });
            activeMap(Key::B, [&]() {std::println("B"); });
            activeMap(Key::W, [&]() { --y; });
            activeMap(Key::A, [&]() { --x; });
            activeMap(Key::S, [&]() { ++y; });
            activeMap(Key::D, [&]() { ++x; });
        }

        // ִ�н����߼�
        void update() override {
            //std::println("{} {}", x, y);
            image2.setPosition(x, y);
            setViewCenter(x, y);
        }

        // ��Ⱦҳ�����ݵ�����
        void render() override {
           drawForView(image);
           drawForView(image2);
           drawForWindow(WindowButton);
          
        }
    };
}