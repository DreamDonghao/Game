#pragma once
#include <ControlPage.hpp>
#include <InteractivePage.hpp>
#include <FrameAnimatedSprite.hpp>
#include <TimeAnimatedSprite.hpp>
namespace sfui {
    // ���Խ���
    class TestPage :public ControlPage {
    
    public:
        TestPage()//---------------
        {
           
        };

        
        void initializePageElements() override {//��ʼ������Ԫ��-------------------------------------
           
           

        }//----------------------------------------------------------------------------------------

        void initActiveKeyBinding()override {//��ʼ��ʵʱ��Ϣ-�¼�ӳ��-------------------------------
           
        }//----------------------------------------------------------------------------------------

        void handleEventInput(const sf::Event &windowEvent) override {//�����¼���Ϣ----------------
            if (windowEvent.type == sf::Event::EventType::KeyPressed) {
                if (windowEvent.key.code == sf::Keyboard::A) {
                   
                }
            }
        }//----------------------------------------------------------------------------------------

        void update() override {
           
        }

        void render() override { // ��Ⱦҳ�����ݵ�����-----------------------------------------------
           
           
            
            
          
        }//----------------------------------------------------------------------------------------
    };
}