#pragma once

namespace sfui {
    // 按钮
    class Button {
    public:
        // 按钮的区域
        struct ButtonArea {
            int left;
            int up;
            int right;
            int lower;
            bool isInButtonArea(const int &x, const int &y) const {
                if (left <= x && x <= right && up <= y && y <= lower) {
                    return true;
                } else {
                    return false;
                }
            }
        }; 

        Button() {}

        ~Button() {}

        // 初始化
        bool init(const float &x,const float &y,const int &width,const int &heigth) {
            m_x = x;
            m_y = y;
            m_width = width;
            m_height = heigth;
            m_buttonArea.left = static_cast<int>(m_x);
            m_buttonArea.up = static_cast<int>(m_y);
            m_buttonArea.right = static_cast<int>(m_x + m_width);
            m_buttonArea.lower = static_cast<int>(m_x + m_height);
        }

        //获取按钮区域
        const ButtonArea &getButtonArea() const{
            return m_buttonArea;
        }

    private:
        float m_x = 0.0;
        float m_y = 0.0;
        int m_width = 0;
        int m_height = 0;
        ButtonArea m_buttonArea;
        Mouse m_mouse;
    };

}