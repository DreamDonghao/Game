//
// Created by donghao on 25-10-5.
//
#ifndef TESTNPC_HPP
#define TESTNPC_HPP
#include <base/npc.hpp>

namespace game {
    class TestNpc : public Npc {
    public:
        TestNpc(): Npc() {
        }

        TestNpc(const float x, const float y, const float hitboxWidth, const float hitboxHeight): Npc(
            x, y, hitboxWidth, hitboxHeight) {
        }

        void draw(sf::RenderWindow &window) const {
            sf::RectangleShape rect;
            rect.setSize({30,30});
            rect.setPosition({getX()-15,getY()-15});
            rect.setFillColor(sf::Color::White);
            window.draw(rect);
        }

    private:
    };
} // game

#endif //TESTNPC_HPP
