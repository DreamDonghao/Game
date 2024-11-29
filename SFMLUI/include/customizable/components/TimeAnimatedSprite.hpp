#pragma once
#include <TextureItem.hpp>
namespace sfui {

	class TimeAnimatedSprite {
	public:
        TimeAnimatedSprite();

        // 初始化循环动图的持续帧，大小，坐标
        bool init(const float &continuationtTime,
            const int &width, const int &height, const float &x, const float &y);

        // 添加循环播放的图片
        void addTextureItems(const FilePath &filepath);

        //重新设置大小和坐标
        void set(const float &continuationtTime,
            const int &width, const int &height, const float &x, const float &y);

        // 获取加载内容,每次获取切换为下一个图片,最后一个图片的下一个为第一个图片
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