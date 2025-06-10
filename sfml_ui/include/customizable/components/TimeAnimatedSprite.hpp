#pragma once
#include <TextureItem.hpp>
namespace sfui {
    /**
     * @brief 以时间为依据循环播放的动图类
     *
     * 支持多帧图片的循环播放，基于时间切换。
     */
	class TimeAnimatedSprite {
	public:
        /**
         * @brief 默认构造函数
         */
        TimeAnimatedSprite();

        /**
         * @brief 初始化循环动图的持续时间、大小、坐标
         * @param continuationtTime 持续时间（秒）
         * @param width 图片宽度
         * @param height 图片高度
         * @param x X坐标
         * @param y Y坐标
         * @return 是否初始化成功
         */
        bool init(const float &continuationtTime,
            const int &width, const int &height, const float &x, const float &y);

        /**
         * @brief 添加循环播放的图片
         * @param filepath 图片文件路径
         */
        void addTextureItems(const FilePath &filepath);

        /**
         * @brief 重新设置大小和坐标
         * @param continuationtTime 持续时间（秒）
         * @param width 图片宽度
         * @param height 图片高度
         * @param x X坐标
         * @param y Y坐标
         */
        void set(const float &continuationtTime,
            const int &width, const int &height, const float &x, const float &y);

        /**
         * @brief 设置动图的坐标
         * @param x X坐标
         * @param y Y坐标
         */
        void setXY(const float &x,const float &y);

        /**
         * @brief 获取当前帧的Sprite（每次调用会自动切换帧）
         * @return 当前帧的Sprite引用
         */
        const sf::Sprite &getSprite();

    private:
        std::vector< TextureItem> m_textureItems; ///< 动画帧图片集合
        float m_x = 0.0; ///< X坐标
        float m_y = 0.0; ///< Y坐标
        int m_width = 0; ///< 图片宽度
        int m_height = 0; ///< 图片高度
        std::size_t m_nowTextureItemsIndex = 0; ///< 当前图片索引
        sf::Clock m_clock; ///< 计时器
        sf::Time m_continuationTime; ///< 持续时间
	};


}
