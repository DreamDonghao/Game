#pragma once

#include <ComplexPage.hpp>
#include <elemental.hpp>
#include <biology.hpp>
#include <world_elemental.hpp>
#include <player.hpp>

namespace game {

    class GamePage : public sfui::ComplexPage {
    private:

    public:
        GamePage() {
        }

        // 初始化界面元素
        void initializePageElements() override {

        }

        // 初始化消息-事件映射
        void initMessageBinding() override {
            eventMap(sfui::Key::Escape, [&]() {
                requestPageSwitch(sfui::TitleName("pauseGamePage"));
            });
        }

        // 执行界面逻辑
        void update() override {

        }

        // 渲染页面内容到窗口
        void render() override {

        }
    };
}
