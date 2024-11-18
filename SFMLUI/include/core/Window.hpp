#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <Page.hpp>
#include <unordered_map>
#include <locale>
#include <codecvt>
namespace sfui {
    // ����ָ��
    template <typename PageType>
    using PagePtr = std::unique_ptr<PageType>;
    // ��������
    template <typename PageType, typename... Args>
    inline PagePtr<PageType> makePage(Args&&... args) {
        return std::make_unique<PageType>(std::forward<Args>(args)...);
    }
    // ��������Ӧ��
    using PageMap = std::unordered_map<Title, PagePtr<Page>>;
    // ���ڴ�С
    using WindowSize = sf::Vector2u;

    //������
    class Window {
    public:

        Window(const int &width, const int &heigth);
        //��ô�������ҳ��
        //������������� �������ָ��
        void addPage(const Title &pageTitle, PagePtr<Page> page);
        // ��ʼ��ʾ��ҳ��
        void startShow(const Title &firstPageTitle);
        
        // �л�Ϊָ���������
        void requestPageSwitch(const Title &pageTitle);

        sf::RenderWindow &getWindow();
        // ��ȡ���ڴ�С
        const WindowSize getWindowSize();

        const WindowSize &getMaxWindowSize() const;
    private:
        sf::RenderWindow m_window;
        WindowSize m_windowSize;
        WindowSize m_maxWindowSize;
        PageMap m_pages;
        Title m_nowPageTitle;
        sf::Event m_event;
        // ���µ�ǰ�������ͼ
        void updateView();
        // ������Ϣ�������յ��رմ���ʱ�����ڹر�
        void procesMessage();
        // ʵʱ���봦��
        void handleRealTimeInput();
        // �¼����봦��
        void  handleEventInput();
        // ���ز���ʾ���滭�浽����
        void drawFrame();
    };

}