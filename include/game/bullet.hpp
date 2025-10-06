//
// Created by donghao on 25-7-2.
//
#ifndef BULLET_HPP
#define BULLET_HPP
#include <base/hitbox.hpp>
#include <algorithm>
#include <execution>
#include <tool.hpp>
#include "angle.hpp"

namespace game {
    /**
     * @brief 子弹类，表示游戏中的单个子弹。
     */
    class Bullet {
    public:
        /**
         * @brief 构造一个子弹对象
         * @param x 子弹初始 X 坐标
         * @param y 子弹初始 Y 坐标
         * @param speed 子弹速度
         * @param moveAngle 移动角度（弧度制）
         * @param hitboxWidth 碰撞箱宽度
         * @param hitboxHeight 碰撞箱高度
         * @param attack 子弹攻击力
         */
        Bullet(float x, float y, float speed, float moveAngle,
               float hitboxWidth, float hitboxHeight, double attack);

        virtual ~Bullet() = default;

        void turnAngle(const float angle) {
            m_moveAngle.revolve(angle);
        }

        sfui::Angle getMoveAngle() const {
            return m_moveAngle;
        }

        /**
         * @brief 更新子弹位置并处理生命周期。
         */
        virtual void move(double dt);

        /**
         * @brief 获取子弹 X 坐标
         * @return X 坐标
         */
        [[nodiscard]] float getX() const;

        /**
         * @brief 获取子弹 Y 坐标
         * @return Y 坐标
         */
        [[nodiscard]] float getY() const;

        /**
         * @brief 获取子弹的碰撞箱
         * @return 碰撞箱对象
         */
        [[nodiscard]] const Hitbox &getHitbox() const;

        /**
         * @brief 获取子弹的攻击力
         * @return 攻击力数值
         */
        [[nodiscard]] double getAttack() const;

        /**
         * @brief 设置子弹是否存活
         * @param alive 是否存活
         */
        void setAlive(bool alive);

        /**
         * @brief 判断子弹是否仍存活
         * @return true 表示存活，false 表示消失
         */
        [[nodiscard]] bool isAlive() const;

        /**
         * @brief 绘制子弹
         * @param window 渲染窗口
         */
        virtual void draw(sf::RenderWindow &window) const = 0;

        /**
         * @brief 绘制子弹的碰撞箱
         * @param window 渲染窗口
         */
        void drawHitbox(sf::RenderWindow &window) const;

    private:
        float m_x;               ///< 子弹 X 坐标
        float m_y;               ///< 子弹 Y 坐标
        float m_speed;           ///< 子弹速度
        sfui::Angle m_moveAngle; ///< 移动角度（弧度）
        Hitbox m_hitbox;         ///< 碰撞箱
        double m_attack;         ///< 攻击力
        bool m_isAlive{true};    ///< 是否存活
        int m_existFrame{1000000};  ///< 存活帧数
    };

    /**
     * @brief 弹幕类，管理多个子弹对象。
     */
    class Barrage {
    public:
        /**
         * @brief 默认构造函数
         */
        Barrage() = default;

        Barrage &operator=(Barrage &&) = default;

        Barrage(const Barrage &) = delete;

        Barrage &operator=(const Barrage &) = delete;

        /**
         * @brief 添加一颗子弹
         * @param bullet
         */
        void addBullet(std::unique_ptr<Bullet> &&bullet);

        /**
         * @brief 检测与指定碰撞箱的碰撞，并结算伤害。
         * @param hitbox 目标碰撞箱
         * @return 本次造成的总伤害值
         */
        [[nodiscard]] double dealDamage(const Hitbox &hitbox);

        /**
         * @brief 更新所有子弹的状态与位置。
         */
        void run();

        /**
         * @brief 设置是否绘制子弹的碰撞箱
         * @param drawHitbox true 绘制，false 不绘制
         */
        void setIsDrawHitbox(bool drawHitbox);

        /**
         * @brief 绘制所有子弹
         * @param window 渲染窗口
         */
        void draw(sf::RenderWindow &window) const;

        double m_dt;

    private:
        std::vector<std::unique_ptr<Bullet> > m_bullets; ///< 子弹容器
        bool m_isDrawHitbox{false};                      ///< 是否绘制碰撞箱
    };
} // namespace game

#endif // BULLET_HPP
