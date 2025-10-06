#pragma once
#include <SFML/Window.hpp>
#include <ActiveKeyBinding.hpp>
#include <Mouse.hpp>
#include <textbox.hpp>
#include <EventBinding.hpp>
#include <inputbox.hpp>

namespace sfui {
    template<typename T>
    concept Drawable = requires(T obj, sf::RenderWindow &w)
    {
        { obj.draw(w) } -> std::same_as<void>;
    };

    /**
     * @brief 标题类型，使用宽字符串
     */
    using Title = std::wstring;

    /**
     * @brief 将std::string转换为Title（std::wstring）
     * @param str 输入的字符串
     * @return 转换后的宽字符串
     */
    Title strToWstr(const std::string &str);

    using viewSize = sf::Vector2f; ///< 视图大小类型
    class Window;                  ///< 前置声明窗口类

    /**
     * @brief 界面抽象基类，定义界面生命周期、事件绑定、渲染等接口
     */
    class Page {
    public:
        using WindowSize = sf::Vector2u;

        explicit Page(Window *mp_window);

        /**
         * @brief 虚析构函数
         */
        virtual ~Page() = default;

        /**
         * @brief 更新界面一帧（更新视图并渲染）
         */
        void updateFrame();

        /**
         * @brief 初始化界面（元素和消息绑定）
         */
        virtual void init() = 0;

        /**
         * @brief 绑定按键与行为（实时输入）
         * @param key 按键
         * @param action 行为
         */
        void activeMap(Key key, const Action &action);

        /**
         * @brief 绑定按键与行为（事件输入）
         * @param key 按键
         * @param action 行为
         */
        void eventMap(Key key, const Action &action);

        /**
         * @brief 绑定鼠标按键与行为（事件输入，重载）
         * @param mouseButton 鼠标按键（自定义类型）
         * @param action 行为
         */
        void eventMap(MouseButton mouseButton, const Action &action);

        /**
         * @brief 绑定SFML鼠标按键与区域及行为（事件输入，重载）
         * @param mouseButton SFML鼠标按键
         * @param area 触发区域指针
         * @param action 行为
         */
        void eventMap(sf::Mouse::Button mouseButton, const Area *area, const Action &action);

        /**
         * @brief 实时输入处理（处理按键行为）
         */
        void executeKeyPressOnce();

        /**
         * @brief 事件输入处理（处理事件行为）
         * @param event SFML事件
         */
        void executeEventBinding(const sf::Event &event);

        /**
         * @brief 更新界面内容（纯虚函数，需子类实现）
         */
        virtual void update() = 0;

        virtual void updateByMessage() = 0;

        /**
         * @brief 获取界面背景颜色
         * @return 背景颜色
         */
        [[nodiscard]] sf::Color getBackgroundColor() const;

        /**
         * @brief 获取窗口视图
         * @return 窗口视图
         */
        sf::View getWindowView() const {
            return m_view;
        }

        /**
         * @brief 获取世界视图
         * @return 世界视图
         */
        sf::View getWorldView() const {
            return m_view;
        }


        sf::RenderWindow &getSfRenderWindow() const;

        void beginDrawForView();

        void beginDrawForWindow() const;

        template<Drawable... DrawObjects>
        void drawForView(DrawObjects &... drawObjects) {
            beginDrawForView();
            auto &window = getSfRenderWindow();
            ((drawObjects.draw(window)), ...);
        }

        template<Drawable... DrawObjects>
        void drawForWindow(DrawObjects &... drawObjects) {
            beginDrawForWindow();
            auto &window = getSfRenderWindow();
            ((drawObjects.draw(window)), ...);
            beginDrawForView();
        }

        void updateView();

        void setWorldViewCenter(const float &x, const float &y) {
            m_worldViewCenter.x = x;
            m_worldViewCenter.y = y;
        }

        void setWorldViewCenter(const sf::Vector2f worldViewCenter) {
            m_worldViewCenter = worldViewCenter;
        }

    protected:
        Window *mp_window = nullptr;         ///< 界面绑定的窗口
        sf::Color m_backgroundColor;         ///< 界面背景颜色
        Mouse m_mouse;                       ///< 鼠标对象
        ActiveKeyBinding m_activeKeyBinding; ///< 按键事件绑定
        EvectBingding m_eventBinding;        // 消息事件绑定

        /**
         * @brief 设置界面背景颜色
         * @param backgroundColor 新的背景颜色
         */
        void setBackgroundColor(const sf::Color &backgroundColor);

        /**
         * @brief 渲染界面内容（纯虚函数，需子类实现）
         */
        virtual void render() = 0;

        /**
         * @brief 发起界面跳转请求（由子类调用）
         * @param targetPageTitle 目标页面标题
         */
        void requestPageSwitch(const Title &targetPageTitle) const;


        double m_ratio = 1; ///< 当前缩放比例
        sf::View m_view;
        sf::Vector2f m_worldViewCenter{0.0f, 0.0f};
        // 窗口大小
        WindowSize m_windowSize;
    };
}
