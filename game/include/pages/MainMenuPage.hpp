#pragma once

#include <ComplexPage.hpp>
#include <elemental.hpp>
#include <biology.hpp>
#include <world_elemental.hpp>
#include <player.hpp>


namespace game {

    class MainMenuPage : public sfui::ComplexPage {
    private:
        sfui::TextureItem mainPage;
        sfui::Button beginButton;
        sfui::Button setButton;
        sfui::Button quitButton;
    public:
        MainMenuPage() {
        }

        // 初始化界面元素
        void initializePageElements() override {

            mainPage.init("images\\main_page.png", 2560, 1660);
            beginButton.init(700, 600, 800, 200, "images\\button_begin_game.png");
            setButton.init(700, 900, 800, 200, "images\\button_set.png");
            quitButton.init(700, 1200, 800, 200, "images\\button_quit.png");
        }

        // 初始化消息-事件映射
        void initMessageBinding() override {

            eventMap(sfui::MouseButton::Left, beginButton.getArea(), [&]() {
                requestPageSwitch(sfui::TitleName("gamePage"));
            });

            eventMap(sfui::MouseButton::Left, quitButton.getArea(), [&]() -> void {
                std::print("quit");

                mp_window->getSfRenderWindow().close();
            });
        }

        // 执行界面逻辑
        void update() override {

        }

        // 渲染页面内容到窗口
        void render() override {
            drawForWindow(mainPage);
            drawForWindow(beginButton);
            drawForWindow(setButton);
            drawForWindow(quitButton);

        }
    };
}
