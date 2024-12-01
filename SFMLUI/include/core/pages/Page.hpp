#pragma once
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <locale>
#include <ActiveKeyBinding .hpp>
#include <Mouse.hpp>
#include <windows.h>
#include <EventBinding.hpp>
#include <iostream>
namespace sfui {
    // 标题
    using Title = std::wstring;

    // 使用 Windows API
    // 将 std::string 转换为 Title (std::wstring)
    Title TitleName(const std::string &str);
    // 视图大小
    using viewSize = sf::Vector2f;
    // 使窗口类对界面类可见
    class Window;

    // 界面抽象基类
    class Page {
    public:
        // 虚析构函数
        virtual ~Page() = default;

        //更新界面一帧画面
        void updateFrame();

        // 绑定界面与包含它的窗口
        void setWindow(Window *const p_window);

        // 为界面鼠标绑定窗口
        void setMouseWindow(sf::RenderWindow *const p_sfml_RenderWindow);

        // 初始化界面
        void init();

        // 初始化界面元素
        virtual void initializePageElements() = 0;

       // 初始化消息与事件绑定
        virtual void initMessageBinding() = 0;

        // 事件映射
        void activeMap(Key key, Action action);

        // 消息映射
        void eventMap(Key key, Action action);
        void eventMap(sf::Mouse::Button mouseButton, Area* area, Action action);

        // 根据绑定窗口的大小来更新界面视图 
        virtual void updateView() = 0;

        // 实时输入处理
        void executeKeyPressOnce();

        // 事件输入处理
        void executeEventBinding(const sf::Event event);

        // 更新界面内容
        virtual void update() = 0;

        // 事件输入处理
        //virtual void handleEventInput(const sf::Event &windowEvent) = 0;

        //获取界面背景颜色
        sf::Color getBackgroundColor() const;

    protected:
        // 界面绑定的窗口
        Window *mp_window = nullptr;
        // 界面背景颜色
        sf::Color m_backgroundColor;
       
        // 鼠标
        Mouse m_mouse;
        // 按键事件绑定
        ActiveKeyBinding m_activeKeyBinding;

        // 消息事件绑定
        EvectBingding m_eventBinding;

        //设置界面背景颜色
        void setBackgroundColor(const sf::Color &backgroundColor);

        // 渲染界面内容
        virtual void render() = 0;

        // 界面跳转请求（由子类调用）
        void requestPageSwitch(const Title &targetPageTitle);
    };

}