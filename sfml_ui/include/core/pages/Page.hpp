#pragma once
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <locale>
#include <ActiveKeyBinding .hpp>
#include <Mouse.hpp>
#include <textbox.hpp>
#include <EventBinding.hpp>
namespace sfui {
    // 标题类型，使用宽字符串
    using Title = std::wstring;

    // 使用 Windows API
    // 将 std::string 转换为 Title (std::wstring)
    Title TitleName(const std::string &str);
    // 视图大小类型
    using viewSize = sf::Vector2f;
    // 前置声明窗口类
    class Window;

    // 界面抽象基类，定义了界面生命周期、事件绑定、渲染等接口
    class Page {
    public:
        // 虚析构函数
        virtual ~Page() = default;

        // 更新界面一帧画面（更新视图并渲染）
        void updateFrame();

        // 绑定界面与包含它的窗口
        void setWindow(Window *p_window);

        // 为界面鼠标绑定窗口
        void setMouseWindow(sf::RenderWindow *p_sfml_RenderWindow);

        // 初始化界面（元素和消息绑定）
        void init();

        // 初始化界面元素（纯虚函数，需子类实现）
        virtual void initializePageElements() = 0;

        // 初始化消息与事件绑定（纯虚函数，需子类实现）
        virtual void initMessageBinding() = 0;

        // 事件映射
        void activeMap(Key key, const Action &action);

        // 消息映射
        void eventMap(Key key, const Action &action);
        void eventMap(MouseButton mousebutton, const Action &action);
        void eventMap(sf::Mouse::Button mouseButton, const Area* area, const Action &action);

        // 根据绑定窗口的大小来更新界面视图（纯虚函数，需子类实现）
        virtual void updateView() = 0;

        // 实时输入处理（处理按键行为）
        void executeKeyPressOnce();

        // 事件输入处理（处理事件行为）
        void executeEventBinding(const sf::Event& event);

        // 更新界面内容（纯虚函数，需子类实现）
        virtual void update() = 0;

        // 获取界面背景颜色
        [[nodiscard]] sf::Color getBackgroundColor() const;

    protected:
        // 界面绑定的窗口
        Window *mp_window = nullptr;
        // 界面背景颜色
        sf::Color m_backgroundColor;
       
        // 鼠标对象
        Mouse m_mouse;
        // 按键事件绑定
        ActiveKeyBinding m_activeKeyBinding;
        // 消息事件绑定
        EvectBingding m_eventBinding;

        // 设置界面背景颜色
        void setBackgroundColor(const sf::Color &backgroundColor);

        // 渲染界面内容（纯虚函数，需子类实现）
        virtual void render() = 0;

        // 界面跳转请求（由子类调用）
        void requestPageSwitch(const Title &targetPageTitle);
    };

}
