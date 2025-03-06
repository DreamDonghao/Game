#pragma once
#include <ComplexPage.hpp>
#include <elemental.hpp>
#include <biology.hpp>
#include <world_elemental.hpp>
#include <player.hpp>
const double PI = 3.14159265358979323846;
namespace game {

    class MainMenuPage :public sfui::ComplexPage {
    private:
        sfui::TextureItem mainPage;
        sfui::Button beginGame;
    public:
        MainMenuPage()

        {
        }

        // 初始化界面元素
        void initializePageElements() override {

            mainPage.init("images\\main_page.png", 2560, 1660);
            beginGame.init(700, 600, 800, 200, "");
        }
        // 初始化消息-事件映射
        void initMessageBinding() override {
            eventMap(sfui::MouseButton::Left, beginGame.getArea(), [&]() {
                requestPageSwitch(sfui::TitleName("gamePage"));
            });
        }

        // 执行界面逻辑
        void update() override {
           
        }

        // 渲染页面内容到窗口
        void render() override {
            drawForWindow(mainPage);
           
        }
    };
}
