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

        void initActiveKeyBinding() override {//��ʼ��ʵʱ��Ϣ-�¼�ӳ��-------------------------------
           
        }//----------------------------------------------------------------------------------------

        void initEventBinding() override {
            m_eventBinding.bindEvent(Key::A, []() {std::printf("A"); });
        }

        void handleEventInput(const sf::Event &windowEvent) override {//�����¼���Ϣ----------------
            m_eventBinding.update(windowEvent);
        }//----------------------------------------------------------------------------------------

        void update() override {
           
        }

        void render() override { // ��Ⱦҳ�����ݵ�����-----------------------------------------------
           
           
            
        }//----------------------------------------------------------------------------------------
    };
}