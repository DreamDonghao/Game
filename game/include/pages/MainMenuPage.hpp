#pragma once

#include <ComplexPage.hpp>
#include <windows.h>
// #include <elemental.hpp>
// #include <biology.hpp>
// #include <world_elemental.hpp>
// #include <player.hpp>


namespace game {
    class MainMenuPage : public sfui::ComplexPage {
    private:
        sfui::TextureItem mainPage;
        sfui::Button beginButton;
        sfui::Button setButton;
        sfui::Button quitButton;
        sfui::TextBox textBox;
        std::string str;
        sfui::InputBox inputbox;
    public:
        MainMenuPage(sf::RenderWindow *p_sfml_RenderWindow):Page(p_sfml_RenderWindow),ComplexPage(p_sfml_RenderWindow),
             textBox(0,0,100,sf::Color::Black,R"(C:\Users\donghao\AppData\Local\Programs\cursor\resources\app\out\media\jetbrains-mono-regular.ttf)","hello"),
        inputbox(m_mouse,0,0,1000,1000){
        }

        // 初始化界面元素
        void initializePageElements() override {
            m_ratio = 0.5;
            std::println("{}", m_ratio);
            mainPage.init("images\\main_page.png", 2560 * m_ratio, 1660 * m_ratio);
            beginButton.init(
                700 * m_ratio, 600 * m_ratio,
                800 * m_ratio, 200 * m_ratio,
                "images\\button_begin_game.png"
            );
            setButton.init(
                700 * m_ratio, 900 * m_ratio,
                800 * m_ratio, 200 * m_ratio,
                "images\\button_set.png"
            );
            quitButton.init(
                700 * m_ratio, 1200 * m_ratio,
                800 * m_ratio, 200 * m_ratio,
                "images\\button_quit.png");
        }

        // 初始化消息-事件映射
        void initMessageBinding() override {
            eventMap(sfui::MouseButton::Left, beginButton.getArea(), [&]() {
                requestPageSwitch(sfui::TitleName("gamePage"));
            });

            eventMap(sfui::MouseButton::Left, quitButton.getArea(), [&]() -> void {
                std::print("quit");

                mp_window->getSfRenderWindow().close();
            });

            // eventMap(sfui::Key::A,[&]() {
            //     str+='A';
            //     std::println("A");
            // });
            // eventMap(sfui::Key::B,[&]() {
            //     str+='B';
            //     std::println("B");
            // });

            // eventMap(sfui::MouseButton::Left,&inputbox.getArea(),[&]() {
            //     inputbox.run(mp_window->getEvent());
            // });

        }

        // 执行界面逻辑
        void update() override {
            textBox.setTestString(str);
            inputbox.run(mp_window->getEvent());
        }

        // 渲染页面内容到窗口
        void render() override {
            drawForWindow(mainPage);
            drawForWindow(beginButton);
            drawForWindow(setButton);
            drawForWindow(quitButton);
            drawForWindow(textBox);
            drawForWindow(inputbox);
        }
    };
}
