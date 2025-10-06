//
// Created by donghao on 25-8-19.
//
#ifndef BOSS_A_HPP
#define BOSS_A_HPP
#include <boss.hpp>
#include <Circle.hpp>
#include <bullet.hpp>

#include "timepiece.hpp"


namespace game {
    class Boss_a final : public Boss {
        class Bullet_b final : public Bullet {
        public:
            Bullet_b(const float x, const float y, const float speed, const float moveAngle,
                     const float hitboxWidth, const float hitboxHeight, const double attack)
                : Bullet(x, y, speed, moveAngle, hitboxWidth, hitboxHeight, attack) {
            }

            ~Bullet_b() override = default;

            void draw(sf::RenderWindow &window) const override {
                c.setPosition(getX(), getY());
                c.draw(window);
            }

        private:
            mutable sfui::Circle c;
        };

    public:
        Boss_a(const float x, const float y, const float hitboxWidth, const float hitboxHeight, const double health)
            : Boss(x, y, hitboxWidth, hitboxHeight, health) {
        }

        sfui::Task<void> update(const double &dt,Barrage &barrage, Barrage &enemyBarrage, const Player &player) {
            co_await std::suspend_always{};
            double oldHealth = getHealth();
            sfui::TimeInterval t1, t2, t3;
            while (getHealth() > 0) {
                alwaysActive(dt,barrage, enemyBarrage, player, oldHealth);


                switch (randomInt(0, 7)) {
                    case 1:
                        t2.reset();
                        while (t2.elapsedMs() < 7000) {
                            alwaysActive(dt,barrage, enemyBarrage, player, oldHealth);
                            if (t3.elapsedMs() > 100) {
                                t3.reset();
                                addBullet(barrage);
                            }
                            co_await std::suspend_always{};
                        }
                        break;
                    case 2:
                        t2.reset();
                        while (t2.elapsedMs() < 7000) {
                            setSpeed(300);
                            setMoveAngle(
                                get_angle_radians(getX(), getY(), player.getX(), player.getY()) - sfui::PI / 2);

                            move(dt);
                            angle.revolve(0.05);
                            std::for_each(
                                std::execution::par_unseq,
                                abc.begin(), abc.end(),
                                [this](auto &a) {
                                    a.setPosition(getX() + 60 * angle.getCos(), getY() + 60 * angle.getSin());
                                    angle.revolve(2 * sfui::PI / static_cast<float>(abc.size()));
                                });
                            if (t3.elapsedMs() > 100) {
                                t3.reset();
                                addBullet(barrage);
                            }
                            changeHealth(-enemyBarrage.dealDamage(getHitbox()));
                            co_await std::suspend_always{};
                        }
                        setSpeed(250);
                        break;
                    case 3:
                        t2.reset();
                        while (t2.elapsedMs() < 7000) {
                            setSpeed(300);
                            setMoveAngle(
                                get_angle_radians(getX(), getY(), player.getX(), player.getY()) - sfui::PI / 2);

                            move(dt);
                            angle.revolve(0.05);
                            std::for_each(
                                std::execution::par_unseq,
                                abc.begin(), abc.end(),
                                [this](auto &a) {
                                    a.setPosition(getX() + 60 * angle.getCos(), getY() + 60 * angle.getSin());
                                    angle.revolve(2 * sfui::PI / static_cast<float>(abc.size()));
                                });
                            if (t3.elapsedMs() > 100) {
                                t3.reset();
                                for (auto &a: abc) {
                                    barrage.addBullet(std::make_unique<Bullet_b>(
                                        a.getX(), a.getY(), 1000,
                                        get_angle_radians(a.getX(), a.getY(), player.getX(), player.getY()),
                                        2, 2, 1
                                    ));
                                }
                            }
                            changeHealth(-enemyBarrage.dealDamage(getHitbox()));
                            co_await std::suspend_always{};
                        }
                        setSpeed(250);

                        break;
                    case 4:
                        t2.reset();
                        while (t2.elapsedMs() < 7000) {
                            if (t3.elapsedMs() > 200) {
                                t3.reset();
                                for (int i = static_cast<int>(player.getY()) - 1500;
                                     i < static_cast<int>(player.getY()) + 1500;
                                     i += 250) {
                                    barrage.addBullet(std::make_unique<Bullet_b>(
                                        player.getX() - 1500, i, 100, 0,
                                        2, 2, 1
                                    ));
                                }
                            }
                            alwaysActive(dt,barrage, enemyBarrage, player, oldHealth);
                            co_await std::suspend_always{};
                        }
                        break;
                    case 5:
                        t2.reset();
                        while (t2.elapsedMs() < 7000) {
                            if (t3.elapsedMs() > 200) {
                                t3.reset();
                                for (int i = static_cast<int>(player.getX()) - 1500;
                                     i <= static_cast<int>(player.getX()) + 1500; i += 250) {
                                    barrage.addBullet(std::make_unique<Bullet_b>(
                                        i, player.getY() - 1500, 100, sfui::PI / 2,
                                        2, 2, 1
                                    ));
                                }
                            }
                            alwaysActive(dt,barrage, enemyBarrage, player, oldHealth);
                            co_await std::suspend_always{};
                        }
                        break;
                    case 6:
                        t2.reset();
                        while (t2.elapsedMs() < 7000) {
                            if (t3.elapsedMs() > 200) {
                                t3.reset();

                                for (const auto &x: {player.getX() - 1000, player.getX(), player.getX() + 1000}) {
                                    for (const auto &y: {player.getY() - 1000, player.getY(), player.getY() + 1000}) {
                                        if (!(x == 0 && y == 0)) {
                                            barrage.addBullet(std::make_unique<Bullet_b>(
                                                x, y, 600, get_angle_radians(x, y, player.getX(), player.getY()),
                                                2, 2, 1
                                            ));
                                        }
                                    }
                                }
                            }
                            alwaysActive(dt,barrage, enemyBarrage, player, oldHealth);
                            co_await std::suspend_always{};
                        }
                        break;
                    default:
                        t2.reset();
                        while (t3.elapsedMs() < 5000) {
                            alwaysActive(dt,barrage, enemyBarrage, player, oldHealth);
                            co_await std::suspend_always{};
                        }
                        break;
                }


                co_await std::suspend_always{};
            }
            co_return;
        }


        void addBullet(Barrage &barrage) const {
            for (auto &a: abc) {
                barrage.addBullet(std::make_unique<Bullet_b>(
                        a.getX(), a.getY(), 100, get_angle_radians(getX(), getY(), a.getX(), a.getY()),
                        2, 2, 1)
                );
            }
        }

        void draw(sf::RenderWindow &window) override {
            //printf("1");
            for (const auto &a: abc) {
                a.draw(window);
            }
        }

    private:
        std::vector<sfui::Circle> abc{
            {getX(), getY(), 3, sf::Color::White},
            {getX(), getY(), 3, sf::Color::White}
        };

        sfui::Angle angle{0};

        void alwaysActive(const double dt,Barrage &barrage, Barrage &enemyBarrage, const Player &player,
                          double &oldHealth) {
            if (oldHealth - getHealth() > 1000) {
                abc.emplace_back(getX(), getY(), 3, sf::Color::White);
                oldHealth = getHealth();
            }
            angle.revolve(0.05);

            std::for_each(
                std::execution::par_unseq, abc.begin(), abc.end(),
                [this](auto &a) {
                    a.setPosition(getX() + 60 * static_cast<float>(angle.getCos()), getY() + 60 * static_cast<float>(angle.getSin()));
                    angle.revolve(static_cast<float>(2 * sfui::PI )/ static_cast<float>(abc.size()));
                });

            if (distance(player.getX(), player.getY(), getX(), getY()) > 1000) {
                setSpeed(125);
            } else {
                setSpeed(25);
            }
            changeHealth(-enemyBarrage.dealDamage(getHitbox()));
            move(dt);
        }
    };
} // game

#endif //BOSS_A_HPP
