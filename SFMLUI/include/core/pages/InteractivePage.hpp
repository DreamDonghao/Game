#include <Page.hpp>

namespace sfui {
    // ��̬��ʵʱ���µĽ���ҳ��
    // ������ͼ��СΪ���ڴ�С
    // (0,0)Ϊ��Ļ����
    class InteractivePage :public Page {
    public:

    protected:
        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ
        void updateView() override {
            m_view.setSize(float(mp_window->getWindowSize().x), 
                float(mp_window->getWindowSize().y));
            m_view.setCenter(0, 0);
        }
        // ҳ����ת����
        void requestPageSwitch(const Title &targetPageTitle) override {
            mp_window->requestPageSwitch(targetPageTitle);
        }
    };
}