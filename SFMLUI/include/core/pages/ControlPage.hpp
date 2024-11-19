#include <Page.hpp>
#include <Window.hpp>

namespace sfui {
    // UI �ؼ�ҳ��
    // ������ͼ��СΪ���ڴ�С
    // (0,0)Ϊ���Ͻ�
    class ControlPage :public Page {
    public:

    protected:
        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ
        void updateView() override {
            m_view.setSize(
                float(mp_window->getWindowSize().x),
                float(mp_window->getWindowSize().y)
            );
            m_view.setCenter(
                float(mp_window->getWindowSize().x)/2, 
                float(mp_window->getWindowSize().y)/2
            );
        }
        // ҳ����ת����
        void requestPageSwitch(const Title &targetPageTitle) override {
            mp_window->requestPageSwitch(targetPageTitle);
        }
    };
}