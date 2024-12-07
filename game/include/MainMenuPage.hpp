#pragma once
#include <ComplexPage.hpp>

namespace game {

    class MainMenuPage :public sfui::ComplexPage {
        sfui::Button beginGameButton;
        sfui::Button setupButton;
        sfui::Button exitButton;
    public:
        MainMenuPage() = default;

        // 初始化界面元素
        void initializePageElements() override {
            setViewCenter((float)getWindowSize().x / 2, (float)getWindowSize().y / 2);
            beginGameButton.init(800, 160, 960, 320, "images/unspecified.png");
        }

        // 初始化消息-事件映射
        void initMessageBinding() override {
            
        }

        // 执行界面逻辑
        void update() override {
            setViewCenter((float)getWindowSize().x / 2, (float)getWindowSize().y / 2);
        }

        // 渲染页面内容到窗口
        void render() override {
            sfui::InteractivePage::draw(beginGameButton);
            std::println("{}  {}", getX(), getY());
        }
    };
}