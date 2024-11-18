#include <Page.hpp>
#include <Window.hpp>
namespace sfui {
    // UI �ؼ�ҳ��
    // ������ͼ����ݴ��ڴ�С������
    // (0,0)Ϊ���Ͻ�
    class ControlPage :public Page {
    public:

    protected:
        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ
        void updateView() override {
            float aspectRatio = 
                float(mp_window->getMaxWindowSize().x )/ mp_window->getMaxWindowSize().y;
            m_view.setSize(3000*aspectRatio, 3000*aspectRatio);
            m_view.setCenter(1500 * aspectRatio, 1500*aspectRatio);
        }
    };
}