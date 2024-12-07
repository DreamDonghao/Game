#pragma once
#include <ComplexPage.hpp>

namespace game {

    class MainMenuPage :public sfui::ComplexPage {
        sfui::Button beginGameButton;
        sfui::Button setupButton;
        sfui::Button exitButton;
    public:
        MainMenuPage() = default;

        // ��ʼ������Ԫ��
        void initializePageElements() override {
            setViewCenter((float)getWindowSize().x / 2, (float)getWindowSize().y / 2);
            beginGameButton.init(800, 160, 960, 320, "images/unspecified.png");
        }

        // ��ʼ����Ϣ-�¼�ӳ��
        void initMessageBinding() override {
            
        }

        // ִ�н����߼�
        void update() override {
            setViewCenter((float)getWindowSize().x / 2, (float)getWindowSize().y / 2);
        }

        // ��Ⱦҳ�����ݵ�����
        void render() override {
            sfui::InteractivePage::draw(beginGameButton);
            std::println("{}  {}", getX(), getY());
        }
    };
}