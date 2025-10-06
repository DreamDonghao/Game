//
// Created by donghao on 25-8-23.
//
#ifndef PLAYER_A_HPP
#define PLAYER_A_HPP
#include "bullet.hpp"
#include "player.hpp"
#include "soundEffect.hpp"

#include "weapon1.hpp"

namespace game {
    class Inventory {
    public:
        void addItem(std::unique_ptr<Item> &&item) {
            m_items.emplace_back(std::move(item));
        }

        void setNowItemIndex(const size_t index) {
            m_nowItemIndex = index;
        }

        [[nodiscard]] Item *getNowItem() const {
            return m_items[m_nowItemIndex].get();
        }

        void draw(sf::RenderWindow &window) const {
            sf::Sprite sprite;
            const sfui::Rectangle a(static_cast<float>(m_nowItemIndex*210+110),30+100,220,220,sf::Color::Cyan,sf::Color::Cyan);
            a.draw(window);
            for (size_t i = 0; i < m_items.size(); ++i) {
                sprite.setTexture(m_items[i]->getIcon());
                sprite.setPosition( static_cast<float>(i * 220) ,30);
                sprite.setScale(
                    200 / static_cast<float>(m_items[i]->getIcon().getSize().x),
                    200 / static_cast<float>(m_items[i]->getIcon().getSize().y)
                );
                window.draw(sprite);
            }
        }

    private:
        std::vector<std::unique_ptr<Item> > m_items;
        size_t m_nowItemIndex{0};
    };


    class Player_a : public Player {
    public:
        Player_a(const float x, const float y, const float hitboxWidth, const float hitboxHeight,
                 const float speed, const double health)
            : Player(x, y, hitboxWidth, hitboxHeight, speed,sfui::Angle(0.0), health), m_noDodgeSpeed(speed) {
            m_items.addItem(std::make_unique<Weapon1>("wp1", "assets/images/gun.png"));
            m_items.addItem(std::make_unique<bow1>("bow1", "assets/images/bow1.png"));
        }

        void setNowItemIndex(const size_t index) {
            m_items.setNowItemIndex(index);
        }

        void dodge() {
            if (dt.elapsedMs() > 3000) {
                dt.reset();
                m_isDodge = true;
            }
        }

        double getDodgeCooldownTime() const {
            return static_cast<double>(dt.elapsedMs()) / 1000;
        }

        sfui::Task<void> update(const sfui::Mouse &mouse, Barrage &barrage, Barrage &enemyBarrage, Boss &boss) {
            co_await std::suspend_always{};
            sfui::TimeInterval time, t2;
            while (getHealth() > 0) {
                changeHealth(-enemyBarrage.dealDamage(getHitbox()));
                if (m_isDodge) {
                    m_isDodge = false;
                    t2.reset();
                }

                if (t2.elapsedMs() > 50) {

                }
                m_items.getNowItem()->use( getX(), getY(), mouse,barrage, boss);
                co_await std::suspend_always{};
            }
            co_return;
        }

        void draw(sf::RenderWindow &window) override {
            const sfui::Circle c(getX(), getY(), 25, sf::Color::Yellow);
            c.draw(window);
        }

        const Inventory &getInventory() const {
            return m_items;
        }

    private:
        bool m_isDodge{false};
        sfui::TimeInterval dt;
        float m_dodgeSpeed{87};
        float m_noDodgeSpeed;

        Inventory m_items;
    };
} // game

#endif //PLAYER_A_HPP
