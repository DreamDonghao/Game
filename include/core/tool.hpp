//
// Created by donghao on 25-6-12.
//

#ifndef TOOL_HPP
#define TOOL_HPP
#include <string>

#include "SFML/System/Clock.hpp"
#include "SFML/System/String.hpp"
#include <random>

inline std::string SfStrToStdStr(const sf::String& sfStr) {
    std::string utf8Str;
    sf::Utf32::toUtf8(sfStr.begin(), sfStr.end(), std::back_inserter(utf8Str));
    return utf8Str;
}

/**
 * @brief 判断指定时间间隔是否已过去。
 *
 * 该函数用于定时触发逻辑，比如光标闪烁、定时刷新等。
 * 每次调用都会检查距离上一次触发是否已超过 `interval`，如果超过则返回 true，并重置计时器。
 * 内部使用静态计时器，因此无需手动维护 `sf::Clock` 对象。
 *
 * @param interval 触发的时间间隔，例如 `sf::seconds(0.5f)`。
 * @return 如果间隔已到，则返回 true，并重启计时器；否则返回 false。
 *
 * @note 本函数为静态节流器，适用于非并发环境；不适用于多线程或多个独立定时器需求。
 */
inline bool intervalPassed(const sf::Time interval) {
    static sf::Clock timer;
    if (timer.getElapsedTime() >= interval) {
        timer.restart();
        return true;
    }
    return false;
}


inline double randomDouble(const double a, const double b) {
    if (a == b) {
        return a;
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(a, std::nextafter(b, std::numeric_limits<double>::max()));
    return dist(gen);
}

inline int randomInt(const int min, const int max) {
    // 静态局部变量，只初始化一次
    static std::random_device rd;
    static std::mt19937 gen(rd()); // Mersenne Twister 引擎

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}


inline float distance(const float x1, const float y1, const float x2, const float y2) {
    return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline double distance(const double x1, const double y1, const double x2, const double y2) {
    return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline float get_angle_radians(const float x1, const float y1, const float x2, const float y2) {
    return std::atan2(y2-y1, x2-x1);
}

#endif //TOOL_HPP
