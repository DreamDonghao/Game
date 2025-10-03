//
// Created by donghao on 25-6-28.
//
#ifndef PARTICLEBUILDER_HPP
#define PARTICLEBUILDER_HPP
#include <Circle.hpp>
#include <tool.hpp>
#include <SFML/Window.hpp>
#include <timepiece.hpp>

namespace sfui {
    class Particle {
    public:
        Particle(const float x, const float y, const float size, const sf::Color color,
                 const std::chrono::milliseconds &existenceTime, const float speed, const float moveAngle)
            : m_circle(x, y, size, color), m_existenceTime(existenceTime),
              m_speed(speed), m_moveAngle(moveAngle) {
        };

        void move() {
            m_circle.moveX(m_speed * cosf(m_moveAngle));
            m_circle.moveY(m_speed * sinf(m_moveAngle));
        }

        float getX() const {
            return m_circle.getX();
        }

        float getY() const {
            return m_circle.getY();
        }

        void dying(const std::chrono::milliseconds time) {
            m_existenceTime -= time;
            if (m_existenceTime < std::chrono::milliseconds(0)) {
                m_isAlive = false;
            }
        }

        void setIsAlive(const bool isAlive) {
            m_isAlive = isAlive;
        }

        bool isAlive() const {
            return m_isAlive;
        }

        void draw(sf::RenderWindow &renderWindow) const {
            m_circle.draw(renderWindow);
        }

    private:
        Circle m_circle;
        std::chrono::milliseconds m_existenceTime;
        float m_speed;
        float m_moveAngle;
        bool m_isAlive{true};
    };

    class ParticleBuilder {
    public:
        ParticleBuilder(const float x, const float y,
                        const float ActivityRadius, const float particleSize,
                        const std::chrono::milliseconds &existenceTime,
                        const std::chrono::milliseconds particleGenerationTimeInterval,
                        const std::pair<float, float> speedRange, const sf::Color particleColor)
            : m_x(x), m_y(y), m_ActivityRadius(ActivityRadius),
              m_particleGenerationTimeInterval(particleGenerationTimeInterval),
              m_particleSize(particleSize), m_particleColor(particleColor), m_speedRange(speedRange),
              m_particleExistenceTime(existenceTime) {
        }

        void setX(const float &x) {
            m_x = x;
        }

        void setY(const float &y) {
            m_y = y;
        }

        void run() {
            if (m_particleGenerationTimeInterval) {
                m_particles.emplace_back(
                    m_x, m_y, m_particleSize, m_particleColor,
                    m_particleExistenceTime, randomDouble(m_speedRange.first, m_speedRange.second),
                    randomDouble(0, 2 * 3.14159269));
            }

            const auto timeInterval = m_timeIntervalMs.elapsedMs();
            m_timeIntervalMs.reset();
            for (size_t i = 0; i < m_particles.size();) {
                auto &p = m_particles[i];

                p.dying(std::chrono::milliseconds(timeInterval));
                p.move();

                if (m_ActivityRadius > 0 && distance(m_x, m_y, p.getX(), p.getY()) > m_ActivityRadius) {
                    p.setIsAlive(false);
                }

                if (!p.isAlive()) {
                    p = m_particles.back();
                    m_particles.pop_back();
                } else {
                    ++i;
                }
            }
        }

        void drow(sf::RenderWindow &renderWindow) const {
            for (const auto &particle: m_particles) {
                particle.draw(renderWindow);
            }
        }

    private:
        float m_x;
        float m_y;
        float m_ActivityRadius;
        Timepiece m_particleGenerationTimeInterval;
        std::vector<Particle> m_particles;
        float m_particleSize;
        sf::Color m_particleColor;
        std::pair<float, float> m_speedRange;
        std::chrono::milliseconds m_particleExistenceTime;

        TimeInterval m_timeIntervalMs;
    };
}

#endif //PARTICLEBUILDER_HPP
