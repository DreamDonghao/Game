// //
// // Created by donghao on 25-7-2.
// //
// #ifndef BOSS_HPP
// #define BOSS_HPP
// #include <tool.hpp>
// #include <chrono>
// #include <entity.hpp>
//
// #include "bullet.hpp"
// #include "button.hpp"
// #include "Circle.hpp"
//
//
// namespace game {
//
//     class Boss:public Entity{
//     public:
//         ~Boss() override = default;
//
//         Boss(const float x, const float y, const float hitboxWidth, const float hitboxHeight, const double health)
//             : Entity(x,y,hitboxWidth,hitboxHeight,0,sfui::Angle(0),0){
//         }
//
//         void move(double dt);
//
//
//
//         void setMoveAngle(double angle);
//
//
//         // virtual sfui::Task update(const double &dt,Barrage &barrage, float &playerX, float &playerY) {
//         //     while (m_health > 0) {
//         //         while (distance(m_x, m_y, playerX, playerY) < 1000) {
//         //             move(dt);
//         //             co_await std::suspend_always{};
//         //         }
//         //         while (distance(m_x, m_y, playerX, playerY) >= 1000) {
//         //             co_await std::suspend_always{};
//         //         }
//         //     }
//         //     co_return;
//         // }
//
//         virtual void draw(sf::RenderWindow &window) {
//
//         }
//
//     private:
//         int state{0};
//     };
// } // game
//
//
// #endif //BOSS_HPP
