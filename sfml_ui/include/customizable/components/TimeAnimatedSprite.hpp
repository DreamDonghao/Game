#pragma once
#include <TextureItem.hpp>
namespace sfui {

	class TimeAnimatedSprite {
	public:
        TimeAnimatedSprite();

        // ��ʼ��ѭ����ͼ�ĳ���֡����С������
        bool init(const float &continuationtTime,
            const int &width, const int &height, const float &x, const float &y);

        // ���ѭ�����ŵ�ͼƬ
        void addTextureItems(const FilePath &filepath);

        //�������ô�С������
        void set(const float &continuationtTime,
            const int &width, const int &height, const float &x, const float &y);

        // ��ȡ��������,ÿ�λ�ȡ�л�Ϊ��һ��ͼƬ,���һ��ͼƬ����һ��Ϊ��һ��ͼƬ
        const sf::Sprite &getSprite();

    private:
        std::vector< TextureItem> m_textureItems;
        float m_x = 0.0;
        float m_y = 0.0;
        int m_width = 0;
        int m_height = 0;
        std::size_t m_nowTextureItemsIndex = 0;
        sf::Clock m_clock;
        sf::Time m_continuationTime;
	};


}