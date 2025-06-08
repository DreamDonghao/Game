#pragma once
namespace sfui {
    /**
     * @brief 可交互对象，封装贴图和区域，支持区域更新
     */
    class Interactive {
    public:
        /**
         * @brief 默认构造函数
         */
        Interactive();
        /**
         * @brief 初始化交互对象
         * @param x 左上角x坐标
         * @param y 左上角y坐标
         * @param width 宽度
         * @param height 高度
         * @param filepath 图片路径
         * @return 是否初始化成功
         */
        bool init(const float &x, const float &y, const int &width, const int &height, const FilePath &filepath);
        /**
         * @brief 获取交互区域
         * @return 区域指针
         */
        Area *const getArea();
        /**
         * @brief 更新交互区域
         * @param x 新x
         * @param y 新y
         * @param width 新宽度
         * @param height 新高度
         */
        void updateArea(const float x, const float y, const unsigned width, const unsigned height);
        /**
         * @brief 获取Sprite
         * @return SFML Sprite对象引用
         */
        const sf::Sprite &getSprite()const;
    private:
        float m_x = 0.0; ///< 左上角x坐标
        float m_y = 0.0; ///< 左上角y坐标
        int m_width = 0; ///< 宽度
        int m_height = 0; ///< 高度
        Area m_area; ///< 区域
        sf::RenderWindow *m_sf_window_p = nullptr; ///< 绑定窗口指针
        TextureItem m_textureItem; ///< 贴图
    };

}
