#pragma once
#include <ComplexPage.hpp>
#include <elemental.hpp>
#include <biology.hpp>
#include <world_elemental.hpp>
#include <player.hpp>

namespace game {

    class PauseGamePage :public sfui::ComplexPage {
    private:

    public:
        PauseGamePage()

        {
        }

        // ��ʼ������Ԫ��
        void initializePageElements() override {

        }
        // ��ʼ����Ϣ-�¼�ӳ��
        void initMessageBinding() override {
            eventMap(sfui::Key::Escape, [&]() {
                requestPageSwitch(sfui::TitleName("gamePage"));
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