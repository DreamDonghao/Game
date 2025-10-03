//
// Created by donghao on 25-8-25.
//
#ifndef WEAPON1_HPP
#define WEAPON1_HPP
#include <item.hpp>

namespace game {
    class Weapon1 : public Weapon {
        class PlayerBullet final : public Bullet {
        public:
            PlayerBullet(const float x, const float y, const float speed, const float moveAngle,
                         const float hitboxWidth, const float hitboxHeight, const double attack, Boss &boss)
                : Bullet(x, y, speed, moveAngle, hitboxWidth, hitboxHeight, attack), m_boss(boss) {
            }

            ~PlayerBullet() override = default;

            void move(const double dt) override {
                // 归一化到 (-PI, PI]
                auto normalize = [](double rad) {
                    while (rad <= -sfui::PI) rad += 2 * sfui::PI;
                    while (rad > sfui::PI) rad -= 2 * sfui::PI;
                    return rad;
                };
                if (const float d = distance(m_boss.getX(), m_boss.getY(), getX(), getY()); d < 500) {
                    const double angleToBoss = get_angle_radians(getX(), getY(), m_boss.getX(), m_boss.getY());
                    const double current = getMoveAngle().getAngleValue();

                    if (const double diff = normalize(angleToBoss - current); diff > 0) {
                        turnAngle((500 - d) * static_cast<float>(0.10 * dt)); // 朝右转
                    } else {
                        turnAngle((500 - d) * static_cast<float>(-0.10 * dt)); // 朝左转
                    }
                }

                this->Bullet::move(dt);
            }

            void draw(sf::RenderWindow &window) const override {
                const sfui::Circle circle(getX(), getY(), 3, sf::Color::Yellow);
                circle.draw(window);
            }

        private:
            Boss &m_boss;
        };

    public:
        explicit Weapon1(const sf::String &name, const std::filesystem::path &iconPath): Weapon(name, iconPath) {
            for (int i = 0; i < 10; ++i) {
                sounds.emplace_back("assets/media/a.mp3");
            }
        }

        void use(float x, float y, const sfui::Mouse mouse, Barrage &barrage, Boss &boss) override {
            if (m_attackInterval.elapsedMs() > 100) {
                m_attackInterval.reset();
                if (mouse.isLeftPressed()) {
                    if (index == sounds.size()) {
                        index = 0;
                    }
                    sounds[index++].play();

                    barrage.addBullet(std::make_unique<PlayerBullet>(
                            x, y, 3000,
                            get_angle_radians(x, y, mouse.getViewPosition().x,
                                              mouse.getViewPosition().y),
                            3, 3, 15, boss)
                    );
                }
            }
        }

    private:
        std::vector<sfui::SoundEffect> sounds;
        std::size_t index{0};
        sfui::TimeInterval m_attackInterval;
    };


    class bow1 final : public Weapon {
        class Arrow1 final : public Bullet {
        public:
            Arrow1(const float x, const float y, const float speed, const float moveAngle,
                   const float hitboxWidth, const float hitboxHeight, const double attack, Boss &boss)
                : Bullet(x, y, speed, moveAngle, hitboxWidth, hitboxHeight, attack), m_boss(boss) {
            }

            ~Arrow1() override = default;

            void draw(sf::RenderWindow &window) const override {
                float arrowLength = 100.f;
                float x = getX(), y = getY();                  // 箭尾位置
                double theta = getMoveAngle().getAngleValue(); // 弧度

                // 箭杆
                sf::RectangleShape shaft(sf::Vector2f(arrowLength, 5));
                shaft.setFillColor(sf::Color::White);
                shaft.setOrigin(0, 2.5f); // 左端为原点
                shaft.setPosition(x, y);
                shaft.setRotation(static_cast<float>(theta) * 180.f / 3.14159265f);

                // 箭头（三角形）
                sf::ConvexShape head;
                head.setPointCount(3);
                head.setPoint(0, sf::Vector2f(0, -10));
                head.setPoint(1, sf::Vector2f(20, 0));
                head.setPoint(2, sf::Vector2f(0, 10));
                head.setFillColor(sf::Color::Red);
                head.setOrigin(0, 0);
                head.setPosition(x + arrowLength * static_cast<float>(std::cos(theta)),
                                 y + arrowLength * static_cast<float>(std::sin(theta)));
                head.setRotation(static_cast<float>(theta) * 180.f / 3.14159265f);

                window.draw(shaft);
                window.draw(head);
            }

        private:
            Boss &m_boss;
        };

    public:
        explicit bow1(const sf::String &name, const std::filesystem::path &iconPath)
            : Weapon(name, iconPath), m_chargeBar(20, 50, 100, 20, 2000, 0, sf::Color::White, sf::Color::Blue) {
        }

        void use(float playerX, float playerY, const sfui::Mouse mouse, Barrage &barrage, Boss &boss) override {
            if (!beginCharge) {
                m_chargeBar.updateCurrentValue(0);
            } else {
                m_chargeBar.updateCurrentValue(
                    static_cast<double>(std::min(m_chargeTime.elapsedMs(), m_MaxChargeTime))
                );
            }

            if (!beginCharge && mouse.isLeftPressed()) {
                m_chargeTime.reset();
                beginCharge = true;
            }
            if (beginCharge && !mouse.isLeftPressed()) {
                beginCharge = false;
                barrage.addBullet(std::make_unique<Arrow1>(
                        playerX, playerY, 30,
                        get_angle_radians(playerX, playerY, mouse.getViewPosition().x,
                                          mouse.getViewPosition().y),
                        3, 3, std::min(m_MaxChargeTime, m_chargeTime.elapsedMs()), boss)
                );
            }
        }

    private:
        sfui::TimeInterval m_chargeTime;
        long long m_MaxChargeTime{2000};
        bool beginCharge{false};

        sfui::ProgressBar m_chargeBar;
    };
} // game

#endif //WEAPON1_HPP
