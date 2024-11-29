#pragma once
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <locale>
#include <ActiveKeyBinding .hpp>
#include <Mouse.hpp>
#include <windows.h>

namespace sfui {
    // ����
    using Title = std::wstring;

    // ʹ�� Windows API
    // �� std::string ת��Ϊ Title (std::wstring)
    Title TitleName(const std::string &str);
    // ��ͼ��С
    using viewSize = sf::Vector2f;
    // ʹ������Խ�����ɼ�
    class Window;

    // ����������
    class Page {
    public:
        //���½���һ֡����
        void updateFrame();

        // �󶨽�����������Ĵ���
        void setWindow(Window *const p_window);

        // Ϊ�������󶨴���
        void setMouseWindow(sf::RenderWindow *const p_sfml_RenderWindow);

        //��ȡ�����ڴ����е���ͼ
        sf::View &getView();

        // ��ʼ������
        void init();

        // ��ʼ������Ԫ��
        virtual void initializePageElements() = 0;

        // ��ʼ��ʵʱ��Ϣ-�¼�ӳ��
        virtual void initActiveKeyBinding() = 0;

        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ 
        virtual void updateView() = 0;

        // ʵʱ���봦��
        void executeKeyPressOnce();

        // ���½�������
        virtual void update() = 0;

        // �¼����봦��
        virtual void handleEventInput(const sf::Event &windowEvent) = 0;

        //��ȡ���汳����ɫ
        sf::Color getBackgroundColor() const;

    protected:
        // ����󶨵Ĵ���
        Window *mp_window = nullptr;
        // ���汳����ɫ
        sf::Color m_backgroundColor;
        // ������ͼ
        sf::View m_view;
        // ���
        Mouse m_mouse;
        // �����¼���
        ActiveKeyBinding m_activeKeyBinding;

        //���ý��汳����ɫ
        void setBackgroundColor(const sf::Color &backgroundColor);

        // ��Ⱦ��������
        virtual void render() = 0;

        // ������ת������������ã�
        virtual void requestPageSwitch(const Title &targetPageTitle) = 0;
    };

}