#pragma once
#include <ComplexPage.hpp>
#include <elemental.hpp>
#include <biology.hpp>
#include <world_elemental.hpp>
#include <player.hpp>

namespace game {

    class GamePage :public sfui::ComplexPage {
    private:
       
    public:
        GamePage()

        {
        }

        // ��ʼ������Ԫ��
        void initializePageElements() override {

        }
        // ��ʼ����Ϣ-�¼�ӳ��
        void initMessageBinding() override {
            eventMap(sfui::Key::Escape, [&]() {
                requestPageSwitch(sfui::TitleName("pauseGamePage"));
            });
        }

        // ִ�н����߼�
        void update() override {

        }

        // ��Ⱦҳ�����ݵ�����
        void render() override {
            
        }
    };
}