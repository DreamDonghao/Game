#pragma once

#include <ComplexPage.hpp>
#include <elemental.hpp>
#include <biology.hpp>
#include <world_elemental.hpp>
#include <player.hpp>

namespace game {

    class GamePage : public sfui::ComplexPage {
    private:
        bool isPause;
        sfui::Button returnMainPageButton;
        sfui::Button returnGameButton;
    public:
        GamePage() : isPause(false) {
        }

        // 初始化界面元素
        void initializePageElements() override {
            isPause = false;
            returnGameButton.init(700,500,800,200,"images\\button_return_game.png");
            returnMainPageButton.init(700, 800, 800, 200, "images\\button_return_main_page.png");
        }

        // 初始化消息-事件映射
        void initMessageBinding() override {
            // 点击ESC时切换游戏暂停状态
            eventMap(sfui::Key::Escape, [&]() {
                isPause = !isPause;
            });
            // 当暂停时,点击继续游戏按钮回到游戏
            eventMap(sfui::MouseButton::Left, returnGameButton.getArea(), [&]() {
                if(isPause) {
                    isPause = !isPause;
                }
            });
            // 暂停时,点击回到主界面按钮回到主界面
            eventMap(sfui::MouseButton::Left, returnMainPageButton.getArea(), [&]() {
                if(isPause) {
                    requestPageSwitch(sfui::TitleName("mainPage"));
                }
            });
        }

        // 执行界面逻辑
        void update() override {

        }

        // 渲染页面内容到窗口
        void render() override {


            if (isPause) {
                drawForWindow(returnMainPageButton);
                drawForWindow(returnGameButton);
            }
        }
    };
}
