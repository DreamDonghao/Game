#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <unordered_map>
#include <locale>
#include <codecvt>
#include <ActiveKeyBinding .hpp>
#include <Mouse.hpp>

namespace sfui {
    // ����
    using Title = std::wstring;
    // ��stringת��ΪTitle
    inline Title TitleName(const std::string &str) {
        static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.from_bytes(str);
    }
    // ��ͼ��С
    using viewSize = sf::Vector2f;
    // ʹ������Խ�����ɼ�
    class Window;

    // ����������
    class Page {
    public:
        // �������������ΪĬ����������
        virtual ~Page() = default;

        //���½���һ֡����
        void updateFrame() {
            // ���ݰ󶨴��ڵĴ�С�����½�����ͼ
            updateView();
            // ��Ⱦҳ�����ݵ�����
            render();
        }

        // �󶨽�����������Ĵ���
        void setWindow(Window *const p_window) {
            mp_window = p_window;
        }

        void setMouseWindow(sf::RenderWindow *const p_sfml_RenderWindow) {
            m_mouse.setWindow(p_sfml_RenderWindow);
        }

        //��ȡ�����ڴ����е���ͼ
        sf::View &getView() { return m_view; };

        // ��ʼ������
        void init() {
            // ��ʼ������Ԫ��
            initializePageElements();
            // ��ʼ��ʵʱ��Ϣ-�¼�ӳ��
            initActiveKeyBinding();
        }

        // ��ʼ������Ԫ��
        virtual void initializePageElements() = 0;

        // ��ʼ��ʵʱ��Ϣ-�¼�ӳ��
        virtual void initActiveKeyBinding() = 0;

        // ���ݰ󶨴��ڵĴ�С�����½�����ͼ 
        virtual void updateView() = 0;  

        // ʵʱ���봦��
        void executeKeyPressOnce() {
            m_activeKeyBinding.update();
        }

        // ��������
        virtual void update() = 0;

        // �¼����봦��
        virtual void handleEventInput(const sf::Event &windowEvent) = 0;

        sf::Color getBackgroundColor() const { return m_backgroundColor; }
    protected:
        //����󶨵Ĵ���
        Window *mp_window = nullptr;
        //���汳����ɫ
        sf::Color m_backgroundColor;
        //������ͼ
        sf::View m_view;

        Mouse m_mouse;

        ActiveKeyBinding m_activeKeyBinding;
        
        //���ý��汳����ɫ
        void setBackgroundColor(const sf::Color &backgroundColor) {
            m_backgroundColor = backgroundColor;
        }
        // ��Ⱦ��������
        virtual void render() = 0;
        // ������ת������������ã�
        virtual void requestPageSwitch(const Title &targetPageTitle) = 0;
    };

}