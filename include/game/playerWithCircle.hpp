// //
// // Created by donghao on 25-7-4.
// //
 #ifndef PLAYERWITHCRICLE_HPP
 #define PLAYERWITHCRICLE_HPP
// #include <player.hpp>
// #include <Circle.hpp>
//
// namespace game {
//     class PlayerWithCircle {
//     public:
//         PlayerWithCircle(const float x, const float y, const float hitboxWidth, const float hitboxHeight,
//                          const float speed, const double health,
//                          const float radius, const sf::Color color)
//             : m_player(x, y, hitboxWidth, hitboxHeight, speed, health), m_circle(x, y, radius, color) {
//         }
//
//         void moveUp() {
//             m_player.moveUp();
//             m_circle.setPosition(m_player.getX(), m_player.getY());
//         }
//
//         void moveDown() {
//             m_player.moveDown();
//             m_circle.setPosition(m_player.getX(), m_player.getY());
//         }
//
//         void moveLift() {
//             m_player.moveLift();
//             m_circle.setPosition(m_player.getX(), m_player.getY());
//         }
//
//         void moveRight() {
//             m_player.moveRight();
//             m_circle.setPosition(m_player.getX(), m_player.getY());
//         }
//
//         void changeHealth(const double health) {
//             m_player.changeHealth(health);
//         }
//
//         void draw(sf::RenderWindow &window) const {
//             m_circle.draw(window);
//         }
//
//         float getX() const {
//             return m_player.getX();
//         }
//
//         float getY() const {
//             return m_player.getY();
//         }
//
//         double getHealth() const {
//             return m_player.getHealth();
//         }
//
//         Hitbox getHitbox(){
//             return m_player.getHitbox();
//         }
//
//     private:
//         Player<> m_player;
//         sfui::Circle m_circle;
//     };
// } // game
//
 #endif //PLAYERWITHCRICLE_HPP
