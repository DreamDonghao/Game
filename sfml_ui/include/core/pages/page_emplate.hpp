﻿#pragma once
#include <ComplexPage.hpp>
#include <button.hpp>
namespace sfui {
    
    class PageName :public PageClass {
    private:
        Button beginGameButton;
        Button setupButton;
        Button exitButton;
    public:
        PageName() = default;

        // 初始化界面元素
        void initializePageElements() override {
           
        }

        // 初始化消息-事件映射
        void initMessageBinding() override {
            
        }

        // 执行界面逻辑
        void update() override {
           
        }

        // 渲染页面内容到窗口
        void render() override {
          
        }
    };
}
