#pragma once
#include <TextureItem.hpp>

namespace sfui {

    // ����֡��ѭ����ͼ
    class FrameAnimatedSprite {
    public:
        FrameAnimatedSprite(){}

        // ��ʼ��ѭ����ͼ�ĳ���֡����С������
        bool init(const size_t &continuationFrame,
            const int &width, const int &height,const float &x,const float &y) {
            m_continuationFrame = continuationFrame;
            m_width = width;
            m_height = height;
            m_x = x;
            m_y = y;
            return true;
        }
        
        // ���ѭ�����ŵ�ͼƬ
        void addTextureItems(const FilePath &filepath ){
            m_textureItems.emplace_back().init(filepath, m_width, m_height, m_x, m_y);
        }

        //���ô�С������
        void set(const size_t &continuationFrame,
            const int &width, const int &height, const float &x, const float &y) {
            m_continuationFrame = continuationFrame;
            m_width = width;
            m_height = height;
            m_x = x;
            m_y = y;
            for (auto &textureItem : m_textureItems) {
                textureItem.setPosition(x, y);
                textureItem.setShowSize(width, height);
            }
        }

        // ��ȡ��������
        const sf::Sprite &getSprite() {
            if (m_frame == m_continuationFrame) {
                m_frame = 0;
                ++m_nowTextureItemsIndex;
                if (m_nowTextureItemsIndex == m_textureItems.size()) {
                    m_nowTextureItemsIndex = 0;
                }
            }
            ++m_frame;
            return m_textureItems[m_nowTextureItemsIndex].getSprite();
        }

    private:
        std::vector< TextureItem> m_textureItems;
        float m_x = 0.0;
        float m_y = 0.0;
        int m_width = 0;
        int m_height = 0;
        std::size_t m_frame = 0;
        std::size_t m_nowTextureItemsIndex = 0;
        std::size_t m_continuationFrame = 0;
    };
}