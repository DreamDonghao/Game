//
// Created by donghao on 25-8-16.
//
#ifndef ANGLE_HPP
#define ANGLE_HPP
#include <cmath>

namespace sfui {
    constexpr double PI = 3.1415926535897932384626433832795;

    class Angle {
    public:
        explicit Angle(const double angle): m_angle(angle) {
        };

        [[nodiscard]] double getSin() const {
            return std::sin(m_angle);
        }

        [[nodiscard]] double getCos() const {
            return std::cos(m_angle);
        }

        [[nodiscard]] double getTan() const {
            return std::tan(m_angle);
        }

        void setAngle(const double angle) {
            m_angle = angle;
        }

        [[nodiscard]] double getAngleValue() const {
            return m_angle;
        }

        void revolve(const double angle) {
            m_angle = std::fmod(m_angle + angle, 2 * PI);
            if (m_angle < 0) {
                m_angle += 2 * PI;
            }
        }

    private:
        double m_angle{0};
    };
} // sfui

#endif //ANGLE_HPP
