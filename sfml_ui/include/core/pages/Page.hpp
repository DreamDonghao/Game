#pragma once
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <locale>
#include <ActiveKeyBinding .hpp>
#include <Mouse.hpp>
#include <windows.h>
#include <EventBinding.hpp>
#include <iostream>
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
        // ����������
        virtual ~Page() = default;

        //���½���һ֡����
        void updateFrame();

        // �󶨽�����������Ĵ���
        void setWindow(Window *const p_window);

        // Ϊ�������󶨴���
        void setMouseWindow(sf::RenderWindow *const p_sfml_RenderWindow);

        // ��ʼ������
        void init();

        // ��ʼ������Ԫ��
        virtual void initializePageElements() = 0;

       // ��ʼ����Ϣ���¼���
        virtual void initMessageBinding() = 0;

        // �¼�ӳ��
        void activeMap(Key key, Action action);

        // ��Ϣӳ��
        void eventMap(Key key, Action action);
        void eventMap(sf::Mouse::Button mouseButton, Area* area, Action action);

        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ 
        virtual void updateView() = 0;

        // ʵʱ���봦��
        void executeKeyPressOnce();

        // �¼����봦��
        void executeEventBinding(const sf::Event event);

        // ���½�������
        virtual void update() = 0;

        // �¼����봦��
        //virtual void handleEventInput(const sf::Event &windowEvent) = 0;

        //��ȡ���汳����ɫ
        sf::Color getBackgroundColor() const;

    protected:
        // ����󶨵Ĵ���
        Window *mp_window = nullptr;
        // ���汳����ɫ
        sf::Color m_backgroundColor;
       
        // ���
        Mouse m_mouse;
        // �����¼���
        ActiveKeyBinding m_activeKeyBinding;

        // ��Ϣ�¼���
        EvectBingding m_eventBinding;

        //���ý��汳����ɫ
        void setBackgroundColor(const sf::Color &backgroundColor);

        // ��Ⱦ��������
        virtual void render() = 0;

        // ������ת������������ã�
        void requestPageSwitch(const Title &targetPageTitle);
    };

}