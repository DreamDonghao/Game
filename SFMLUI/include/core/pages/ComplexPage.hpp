#pragma once
#include <InteractivePage.hpp>
#include <ControlPage.hpp>

namespace sfui {
    // ��Ͻ���(λ�ö�̬���½��棬UI�ؼ�����)
    class ComplexPage :public InteractivePage, public ControlPage {
    public:
        // ������ͼ
        void updateView() override{
            ControlPage::updateView();
            InteractivePage::updateView();
        }

        // �Դ���Ϊ���ݻ���
        template<typename DrawObject>
        void drawForWindow(const DrawObject &drawObject ) {
            ControlPage::draw(drawObject);
        }

        // ����ͼΪ���ݻ�ͼ
        template<typename DrawObject>
        void drawForView(const DrawObject &drawObject) {
            InteractivePage::draw(drawObject);
        }

    };

}