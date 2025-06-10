#pragma once
#include <SFML/Graphics.hpp>

namespace sfui {
    using FilePath = std::string;
    /**
     * @brief 贴图项，封装SFML贴图，支持加载、缩放、位置设置等
     */
    class TextureItem {
    public:
        /**
         * @brief 默认构造函数
         */
        TextureItem();

        /**
         * @brief 移动构造函数
         * @param other 右值引用对象
         */
        TextureItem(TextureItem &&other) noexcept;

        /**
         * @brief 移动赋值运算符
         * @param other 右值引用对象
         * @return 自身引用
         */
        TextureItem &operator=(TextureItem &&other) noexcept;

        /**
         * @brief 拷贝构造函数
         * @param other 拷贝对象
         */
        TextureItem(const TextureItem &other);

        /**
         * @brief 初始化贴图项
         * @param filepath 图片路径
         * @param width 显示宽度
         * @param height 显示高度
         * @param x X坐标
         * @param y Y坐标
         * @return 是否初始化成功
         */
        bool init(const FilePath &filepath = "images/unspecified.png",
                  const int &width = 0, const int &height = 0,
                  const float &x = 0, const float &y = 0
        );

        /**
         * @brief 设置显示宽度
         * @param width 新宽度
         */
        void setShowWidth(const int &width);

        /**
         * @brief 设置显示高度
         * @param height 新高度
         */
        void setShowHeight(const int &height);

        /**
         * @brief 设置显示大小
         * @param width 新宽度
         * @param height 新高度
         */
        void setShowSize(const int width, const int &height);

        /**
         * @brief 设置X坐标
         * @param x 新X坐标
         */
        void setX(const float &x);

        /**
         * @brief 设置Y坐标
         * @param y 新Y坐标
         */
        void setY(const float &y);

        /**
         * @brief 设置位置
         * @param x 新X坐标
         * @param y 新Y坐标
         */
        void setPosition(const float &x, const float &y);

        /**
         * @brief 获取显示宽度
         * @return 显示宽度
         */
        const float getShowWidth() const;

        /**
         * @brief 获取显示高度
         * @return 显示高度
         */
        const float getShowHidth() const;

        /**
         * @brief 获取纹理宽度
         * @return 纹理宽度
         */
        int getTextureWidth() const;

        /**
         * @brief 获取纹理高度
         * @return 纹理高度
         */
        int getTextureHeight() const;

        /**
         * @brief 获取X坐标
         * @return X坐标
         */
        float getX() const;

        /**
         * @brief 获取Y坐标
         * @return Y坐标
         */
        float getY() const;

        /**
         * @brief 获取加载内容（Sprite）
         * @return SFML Sprite对象引用
         */
        const sf::Sprite &getSprite() const;

    private:
        sf::Texture m_sf_texture; ///< SFML纹理对象
        sf::Sprite m_sf_sprite;   ///< SFML精灵对象
    };
}
