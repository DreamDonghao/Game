#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <Window.hpp>
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <iostream>



namespace sfui {
    // ���Խ���
    class TestPage :public InteractivePage {
    public:
        TestPage() {
            setBackgroundColor(sf::Color(0, 0, 0));
        };
    private:
       
        
        
        void initializePageElements() override {//��ʼ������Ԫ��-------------------------------------
           
            

           
        }//----------------------------------------------------------------------------------------

        void initActiveKeyBinding()override {//��ʼ��ʵʱ��Ϣ-�¼�ӳ��-------------------------------
            
        }//----------------------------------------------------------------------------------------

        void handleEventInput(const sf::Event &windowEvent) override {//�����¼���Ϣ----------------
            if (windowEvent.key.code == sf::Keyboard::F) {

            }
        }//----------------------------------------------------------------------------------------
       
        void render() override { // ��Ⱦҳ�����ݵ�����-----------------------------------------------
           
        }//----------------------------------------------------------------------------------------
    };

}