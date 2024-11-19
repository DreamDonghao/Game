#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <random>
#include <iostream>

namespace sfui {
    // ���Խ���
    class TestPage :public InteractivePage {
    public:
        TestPage() ://---------------
            circle(1)
        
        {
            setBackgroundColor(sf::Color(0, 0, 0));
        };
    private:
       
        sf::CircleShape circle;

       
        
        
        void initializePageElements() override {//��ʼ������Ԫ��-------------------------------------
         
            circle.setFillColor(sf::Color::Red);

        }//----------------------------------------------------------------------------------------

        void initActiveKeyBinding()override {//��ʼ��ʵʱ��Ϣ-�¼�ӳ��-------------------------------
               m_activeKeyBinding.bindKey(Key::A, [&]() {});
        }//----------------------------------------------------------------------------------------

        void handleEventInput(const sf::Event &windowEvent) override {//�����¼���Ϣ----------------
            if(windowEvent.type == sf::Event::EventType::KeyPressed)
            if (windowEvent.key.code == sf::Keyboard::A) {
                /*std::print(std::cout, "�������Ļ����({},{})\n", m_mouse.getScreenPosition().x, m_mouse.getScreenPosition().y);
                std::print(std::cout, "����ڴ�������({},{})\n", m_mouse.getWindowPosition().x, m_mouse.getWindowPosition().y);
                std::print(std::cout, "�������ͼ����({},{})\n\n", m_mouse.getViewPosition().x, m_mouse.getViewPosition().y);*/
            }
        }//----------------------------------------------------------------------------------------
       
        void render() override { // ��Ⱦҳ�����ݵ�����-----------------------------------------------
            mp_window->getWindow().draw(circle);
        }//----------------------------------------------------------------------------------------
    };

}