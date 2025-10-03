//
// Created by donghao on 25-6-12.
//

#include <inputbox.hpp>

#include <textbox.hpp>
#include <../../../include/customizable/controls/area.hpp>


#include <windows.h>
#include <imm.h>

#include "tool.hpp"
#pragma comment(lib, "imm32.lib")
namespace sfui{

        InputBox::InputBox(Mouse &mouse, const float x, const float y, const int width, const int height, const sf::Color& color,
                           const unsigned int textSize, const sf::RenderWindow &renderWindow)
            :  m_x(x), m_y(y), m_width(width), m_height(height), m_textbox(
                  m_x, m_y, textSize, color,
                  R"(C:\Windows\Fonts\msyh.ttc)",
                  "hello)"), m_inputArea(x, y, x + width, y + height), m_mouse(mouse) {
            hwnd = renderWindow.getSystemHandle();
            hIMC = ImmGetContext(hwnd);
            ImmAssociateContext(hwnd, hIMC);
        }

        void InputBox::run(const sf::Event &event) {
            if (m_mouse.isLeftPressed()) {
                // 获取鼠标位置，设置 IME 提示框位置
                if (m_inputArea.isInArea(m_mouse.getWindowPos().x, m_mouse.getWindowPos().y)) {
                    isActive = true;
                    POINT pt;
                    GetCursorPos(&pt);         // 屏幕坐标
                    ScreenToClient(hwnd, &pt); // 转为客户端坐标

                    COMPOSITIONFORM cf = {};
                    cf.dwStyle = CFS_POINT;
                    cf.ptCurrentPos = pt;
                    ImmSetCompositionWindow(hIMC, &cf);

                    // 候选词窗口（有些输入法可能忽略）
                    CANDIDATEFORM cand = {};
                    cand.dwIndex = 0;
                    cand.dwStyle = CFS_CANDIDATEPOS;
                    cand.ptCurrentPos = pt;
                    ImmSetCandidateWindow(hIMC, &cand);
                } else {
                    isActive = false;
                }
            }

            if (isActive) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode == 8) {
                        if (cursorPosition > 0) {
                            m_showCursor = false;
                            m_text.erase(cursorPosition - 1);
                            --cursorPosition;
                        }
                    } else {
                        m_showCursor = false;
                        m_text.insert(cursorPosition, event.text.unicode);
                        cursorPosition += 1;
                    }
                } else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Delete && cursorPosition <= static_cast<int>(m_text.
                            getSize())) {
                        m_showCursor = false;
                        m_text.erase(cursorPosition);
                    } else if (event.key.code == sf::Keyboard::Left && cursorPosition > 0) {
                        m_showCursor = false;

                        cursorPosition -= 1;
                    } else if (event.key.code == sf::Keyboard::Right && cursorPosition < static_cast<int>(m_text.
                                   getSize())) {
                        m_showCursor = false;

                        cursorPosition += 1;
                    }
                }
                m_textbox.setTestString(m_text);
            }
        }

        void InputBox::updateCursor() {
            if (intervalPassed(sf::seconds(0.5))) {
                m_showCursor = !m_showCursor;
            }
        }

        const Area &InputBox::getArea() const { return m_inputArea; }

        sf::String &InputBox::getText() { return m_text; }


        void InputBox::draw(sf::RenderWindow &renderWindow) const{
            renderWindow.draw(m_textbox.getSprite());
            if (isActive && !m_showCursor) {
                const auto cursorPixelPos = m_textbox.getSprite().findCharacterPos(cursorPosition);
                sf::RectangleShape cursor;
                cursor.setSize({3.f, static_cast<float>(m_textbox.getSprite().getCharacterSize()) + 10});
                cursor.setFillColor(sf::Color::White);
                cursor.setPosition(cursorPixelPos);
                renderWindow.draw(cursor);
            }
        }

}

