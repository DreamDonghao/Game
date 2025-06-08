#pragma once
#include <ComplexPage.hpp>
#include <button.hpp>
namespace sfui {
    /**
     * @brief 页面模板类，便于新建页面时继承和实现
     *
     * 继承自ComplexPage，包含常用控件成员。
     */
    class PageName :public PageClass {
    private:
        Button beginGameButton; ///< 开始游戏按钮
        Button setupButton;     ///< 设置按钮
        Button exitButton;      ///< 退出按钮
    public:
        /**
         * @brief 默认构造函数
         */
        PageName() = default;

        /**
         * @brief 初始化界面元素
         * @note 需在子类中实现具体逻辑
         */
        void initializePageElements() override {
           
        }

        /**
         * @brief 初始化消息-事件映射
         * @note 需在子类中实现具体逻辑
         */
        void initMessageBinding() override {
            
        }

        /**
         * @brief 执行界面逻辑
         * @note 需在子类中实现具体逻辑
         */
        void update() override {
           
        }

        /**
         * @brief 渲染页面内容到窗口
         * @note 需在子类中实现具体逻辑
         */
        void render() override {
          
        }
    };
}
