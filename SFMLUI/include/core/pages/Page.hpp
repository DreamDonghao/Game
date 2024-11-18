#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <locale>
#include <codecvt>
#include <ActiveKeyBinding .hpp>
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
        //获取界面在窗口中的视图
        sf::View &getView() { return m_view; };
        // 初始化界面
        virtual void init() = 0;
        // 根据绑定窗口的大小来更新界面视图 
        virtual void updateView() = 0;  
        // 实时输入处理
        void executeKeyPressOnce() {
            activeKeyBinding.update();
        }
        // 事件输入处理
        virtual void handleEventInput(const sf::Event &windowEvent) = 0;
    protected:
        //界面绑定的窗口
        Window *mp_window = nullptr;
        //界面背景颜色
        sf::Color m_backgroundColor;
        //界面视图
        sf::View m_view;

        ActiveKeyBinding activeKeyBinding;
        
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