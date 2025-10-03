//
// Created by donghao on 25-8-20.
//
#include <bullet.hpp>
#include "Circle.hpp"

namespace game {
    Bullet::Bullet(const float x, const float y, const float speed, const float moveAngle, const float hitboxWidth,
                   const float hitboxHeight, const double attack)
        : m_x(x), m_y(y), m_speed(speed), m_moveAngle(moveAngle),
          m_hitbox(x, y, hitboxWidth, hitboxHeight),
          m_attack(attack) {
    }

    void Bullet::move(const double dt) {
        --m_existFrame;
        if (m_existFrame == 0) {
            m_isAlive = false;
        }
        m_x += m_speed * static_cast<float>(m_moveAngle.getCos() * dt);
        m_y += m_speed * static_cast<float>(m_moveAngle.getSin() * dt);
        m_hitbox.setPosition(m_x, m_y);
    }

    float Bullet::getX() const {
        return m_x;
    }

    float Bullet::getY() const {
        return m_y;
    }

    const Hitbox &Bullet::getHitbox() const {
        return m_hitbox;
    }

    double Bullet::getAttack() const {
        return m_attack;
    }

    void Bullet::setAlive(const bool alive) {
        m_isAlive = alive;
    }

    bool Bullet::isAlive() const {
        return m_isAlive;
    }

    // void Bullet::draw(sf::RenderWindow &window) const {
    //     std::printf("%s",__FUNCTION__);
    //     const sfui::Circle circle(m_x, m_y, 3, sf::Color::Red);
    //     circle.draw(window);
    // }

    void Bullet::drawHitbox(sf::RenderWindow &window) const {
        m_hitbox.draw(window);
    }

    void Barrage::addBullet(std::unique_ptr<Bullet> &&bullet) {
        m_bullets.push_back(std::move(bullet));
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    double Barrage::dealDamage(const Hitbox &hitbox) {
        double damage = 0;
        std::for_each(
            std::execution::par_unseq, m_bullets.begin(), m_bullets.end(),
            [& hitbox,&damage](auto &bullet) {
                if (isCollide(hitbox, bullet->getHitbox())) {
                    damage += bullet->getAttack();
                    bullet->setAlive(false);
                }
            }
        );
        return damage;
    }

    void Barrage::run() {
        std::for_each(
            std::execution::par_unseq, m_bullets.begin(), m_bullets.end(),
            [this](auto &bullet) {
                bullet->move(m_dt);
            });

        std::erase_if(m_bullets, [](auto &bullet) {
            return !bullet->isAlive();
        });
    }

    void Barrage::setIsDrawHitbox(const bool drawHitbox) {
        m_isDrawHitbox = drawHitbox;
    }

    void Barrage::draw(sf::RenderWindow &window) const {
        std::for_each(
            std::execution::seq, m_bullets.begin(), m_bullets.end(),
            [&](auto &bullet) {
                bullet->draw(window);
                if (m_isDrawHitbox) {
                    bullet->drawHitbox(window);
                }
            }
        );
    }
}
