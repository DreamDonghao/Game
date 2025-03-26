#pragma once

#include <ComplexPage.hpp>
#include <elemental.hpp>
#include <biology.hpp>
#include <world_elemental.hpp>
#include <player.hpp>

namespace game {
    // 游戏暂停界面
    class PauseGamePage : public sfui::ComplexPage {
    private:

    public:

        PauseGamePage(){

        }

        // 初始化界面元素
        void initializePageElements() override {

        }

        // 初始化消息-事件映射
        void initMessageBinding() override {
            // 点击 ESC 键时退出暂停界面,并且回到游戏界面
            eventMap(sfui::Key::Escape, [&]() {
                requestPageSwitch(sfui::TitleName("gamePage"));
            });

        }

        // 执行界面逻辑
        void update() override {

        }

        // 渲染页面内容到窗口
        void render() override {
            drawForWindow(returnMainPageButton);
        }
    };
}
