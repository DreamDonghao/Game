#pragma once

namespace sfui {

	class TimeAnimatedSprite {
	public:
		TimeAnimatedSprite() {}

        // ��ʼ��ѭ����ͼ�ĳ���֡����С������
        bool init(const float &continuationtTime,
            const int &width, const int &height, const int &x, const int &y) {
            m_continuationTime = sf::seconds(continuationtTime);
            m_width = width;
            m_height = height;
            m_x = x;
            m_y = y;
            return true;
        }

        // ���ѭ�����ŵ�ͼƬ
        void addTextureItems(const FilePath &filepath) {
            m_textureItems.emplace_back().init(filepath, m_width, m_height, m_x, m_y);
        }

        //���ô�С������
        void set(const float &continuationtTime,
            const int &width, const int &height, const int &x, const int &y) {
            m_continuationTime = sf::seconds(continuationtTime);
            m_width = width;
            m_height = height;
            m_x = x;
            m_y = y;;
            for (auto &textureItem : m_textureItems) {
                textureItem.setPosition(m_x, m_y);
                textureItem.setShowSize(m_width, m_height);
            }
        }

        // ��ȡ��������
        const sf::Sprite &getSprite() {
            if (m_clock.getElapsedTime()>=m_continuationTime) {
                m_clock.restart();
                ++m_nowTextureItemsIndex;
                if (m_nowTextureItemsIndex == m_textureItems.size()) {
                    m_nowTextureItemsIndex = 0;
                }
            }
            return m_textureItems[m_nowTextureItemsIndex].getSprite();
        }

    private:
        std::vector< TextureItem> m_textureItems;
        int m_x;
        int m_y;
        int m_width;
        int m_height;
        std::size_t m_nowTextureItemsIndex = 0;
        sf::Clock m_clock;
        sf::Time m_continuationTime;
	};


}