#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <unordered_map>
#include <locale>
#include <codecvt>
#include <ActiveKeyBinding .hpp>
#include <Mouse.hpp>

namespace sfui {
    // 标题
    using Title = std::wstring;
    // 将string转换为Title
    inline Title TitleName(const std::string &str) {
        static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.from_bytes(str);
    }
    // 视图大小
    using viewSize = sf::Vector2f;
    // 使窗口类对界面类可见
    class Window;

    // 界面抽象基类
    class Page {
    public:
        // 子类的析构函数为默认析构函数
        virtual ~Page() = default;

        //更新界面一帧画面
        void updateFrame() {
            // 根据绑定窗口的大小来更新界面视图
            updateView();
            // 渲染页面内容到窗口
            render();
        }

        // 绑定界面与包含它的窗口
        void setWindow(Window *const p_window) {
            mp_window = p_window;
        }

        void setMouseWindow(sf::RenderWindow *const p_sfml_RenderWindow) {
            m_mouse.setWindow(p_sfml_RenderWindow);
        }

        //获取界面在窗口中的视图
        sf::View &getView() { return m_view; };

        // 初始化界面
        void init() {
            // 初始化界面元素
            initializePageElements();
            // 初始化实时消息-事件映射
            initActiveKeyBinding();
        }

        // 初始化界面元素
        virtual void initializePageElements() = 0;

        // 初始化实时消息-事件映射
        virtual void initActiveKeyBinding() = 0;

        // 根据绑定窗口的大小来更新界面视图 
        virtual void updateView() = 0;  

        // 实时输入处理
        void executeKeyPressOnce() {
            m_activeKeyBinding.update();
        }

        // 更新内容
        virtual void update() = 0;

        // 事件输入处理
        virtual void handleEventInput(const sf::Event &windowEvent) = 0;

        sf::Color getBackgroundColor() const { return m_backgroundColor; }
    protected:
        //界面绑定的窗口
        Window *mp_window = nullptr;
        //界面背景颜色
        sf::Color m_backgroundColor;
        //界面视图
        sf::View m_view;

        Mouse m_mouse;

        ActiveKeyBinding m_activeKeyBinding;
        
        //设置界面背景颜色
        void setBackgroundColor(const sf::Color &backgroundColor) {
            m_backgroundColor = backgroundColor;
        }
        // 渲染界面内容
        virtual void render() = 0;
        // 界面跳转请求（由子类调用）
        virtual void requestPageSwitch(const Title &targetPageTitle) = 0;
    };

}