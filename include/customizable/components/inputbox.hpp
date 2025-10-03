/**
 * @file inputbox.hpp
 * @brief 定义 sfui::InputBox 类，用于图形化输入框组件，支持中文输入法交互。
 * @author donghao
 * @date 2025-06-08
 */

#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include <textbox.hpp>
#include <area.hpp>
#include <windows.h>
#include "tool.hpp"
#include <Mouse.hpp>
#pragma comment(lib, "imm32.lib")

namespace sfui {

    /**
     * @class InputBox
     * @brief 一个支持中文输入法定位的输入框类，基于 SFML 和 Windows IME API。
     *
     * 支持文字插入、删除、光标控制，中文输入法位置跟随光标自动调整。
     */
    class InputBox {
    public:
        /**
         * @brief 构造 InputBox 输入框对象。
         * @param mouse         鼠标引用对象，用于检测点击位置
         * @param x             输入框左上角 x 坐标
         * @param y             输入框左上角 y 坐标
         * @param width         输入框宽度
         * @param height        输入框高度
         * @param color         字体颜色
         * @param textSize      字体大小
         * @param renderWindow  渲染目标窗口引用
         */
        InputBox(Mouse &mouse, float x, float y, int width, int height,const sf::Color& color,
                 unsigned int textSize, const sf::RenderWindow &renderWindow);

        /**
         * @brief 主事件处理函数，处理点击、中文输入、按键编辑等操作。
         * @param event 传入的 SFML 事件对象
         */
        void run(const sf::Event &event);

        /**
         * @brief 更新光标状态，用于闪烁效果。
         */
        void updateCursor();

        /**
         * @brief 获取输入框区域。
         * @return 输入框的 Area 区域对象（用于碰撞检测）
         */
        const Area &getArea() const;

        /**
         * @brief 获取当前输入的文字。
         * @return 引用返回的 sf::String 输入内容
         */
        sf::String &getText();

        /**
         * @brief 将输入框绘制到指定窗口。
         */
        void draw(sf::RenderWindow &m_renderWindow) const;

    private:
        float m_x;                        ///< 输入框起始横坐标
        float m_y;                        ///< 输入框起始纵坐标
        int m_width;                      ///< 输入框宽度
        int m_height;                     ///< 输入框高度
        bool isActive = false;            ///< 当前输入框是否激活
        sf::String m_text;                ///< 当前输入文字
        TextBox m_textbox;                ///< TextBox 对象用于渲染文字
        Area m_inputArea;                 ///< 用于判断鼠标是否点击输入框内
        int cursorPosition = 0;           ///< 当前光标的位置索引
        std::string cursorStyle = "|";    ///< 光标样式（当前未使用）
        Mouse &m_mouse;                   ///< 鼠标引用
        HWND hwnd;                        ///< 当前窗口句柄
        HIMC hIMC;                        ///< 输入法上下文句柄
        bool m_showCursor = true;         ///< 光标是否可见（用于闪烁效果）
    };
}

#endif // INPUTBOX_HPP
