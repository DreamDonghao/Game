#pragma once
#include <ComplexPage.hpp>
#include <button.hpp>
namespace sfui {
    
    class PageName :public PageClass {
    private:
        Button beginGameButton;
        Button setupButton;
        Button exitButton;
    public:
        PageName() = default;

        // ��ʼ������Ԫ��
        void initializePageElements() override {
           
        }

        // ��ʼ����Ϣ-�¼�ӳ��
        void initMessageBinding() override {
            
        }

        // ִ�н����߼�
        void update() override {
           
        }

        // ��Ⱦҳ�����ݵ�����
        void render() override {
          
        }
    };
}