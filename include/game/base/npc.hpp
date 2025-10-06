//
// Created by donghao on 25-10-5.
//
#ifndef NPC_HPP
#define NPC_HPP
#include <base/entity.hpp>
#include "co.hpp"

namespace game {
    class Npc : public Entity {
    public:
        Npc() = default;

        Npc(const float x, const float y, const float hitboxWidth, const float hitboxHeight)
            : Entity(x, y, hitboxWidth, hitboxHeight, 0, sfui::Angle(0), 100) {
        }

        ~Npc() override = default;

        void interactive() {
            isInteraction = true;
        }

        sfui::Task update(const float &dt) {
            while (isAlive()) {
                if (isInteraction) {

                    isInteraction = false;
                }
                co_await std::suspend_always{};
            }
            co_return;
        }

    private:
        bool isInteraction = false;
    };
} // game

#endif //NPC_HPP
