#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
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
    // ��ʾ����״̬
    enum class WindowState {
        Windowed,  // ����ģʽ
        Fullscreen // ȫ��ģʽ
    };

    //������
    class Window {
    public:

        Window(const int &width, const int &heigth, const WindowState &winsowState);

        //��ô������ҳ��
        //������������� �������ָ��
        void addPage(const Title &pageTitle, PagePtr<Page> page);

        // ��ʼ��ʾ��ҳ��
        void startShow(const Title &firstPageTitle);
        
        // �л�Ϊָ���������
        void requestPageSwitch(const Title &pageTitle);

        //��ȡsfml�Ĵ���
        sf::RenderWindow &getSfRenderWindow();

        // ��ȡ���ڴ�С
        const WindowSize getWindowSize();

        // ��ȡ��Ļ�ֱ���
        const WindowSize &getScreenSize() const;

    private:
        sf::RenderWindow m_sfml_renderWindow;
        WindowSize m_windowSize;
        WindowSize m_screenSize;
        PageMap m_pages;
        Title m_nowPageTitle;
        sf::Event m_event;
        WindowState m_winsowState;
    private:
        // ���µ�ǰ�������ͼ
        void updateView();
        // ������Ϣ�������յ��رմ���ʱ�����ڹر�
        void procesMessage();
        // ����ʵʱ����
        void handleRealTimeInput();
        // �����¼�����
        void  handleEventInput();
        // ���ز���ʾ���滭�浽����
        void drawFrame();
    private:
        //���ƴ�������ķ���
        void toggleFullscreen();
        // �л�Ϊȫ��ģʽ
        void toFullscreen();
        //�л�Ϊ����ģʽ
        void toWindowed();
    };

}