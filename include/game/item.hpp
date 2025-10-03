//
// Created by donghao on 25-8-25.
//
#ifndef ITEM_HPP
#define ITEM_HPP

#include "boss.hpp"
#include "SFML/System/String.hpp"
#include "Circle.hpp"
#include "Mouse.hpp"

namespace game {
    enum class ItemType { weapon, potion };

    inline int getItemTypeMaxStack(const ItemType itemType) {
        switch (itemType) {
            case ItemType::weapon:
                return 1;
            case ItemType::potion:
                return 100;
        }
        return 0;
    }

    class Item {
    public:
        virtual ~Item() = default;

        explicit Item(const ItemType type, const sf::String &name, const std::filesystem::path &iconPath)
            : m_name(name), m_type(type), m_maxStack(getItemTypeMaxStack(type)) {
            if (!m_icon.loadFromFile(iconPath.string())) {
                std::cerr << "Failed to load icon from " << iconPath.string() << std::endl;
            }
        }

        [[nodiscard]] ItemType getType() const {
            return m_type;
        }

        virtual void use(float playerX, float playerY, sfui::Mouse mouse, Barrage &barrage, Boss &boss) = 0;

        //virtual void use(float playerX, float playerY, sfui::Mouse mouse);

        virtual const sf::Texture &getIcon() const {
            return m_icon;
        }

    private:
        sf::String m_name;
        ItemType m_type;
        int m_maxStack;
        sf::Texture m_icon;
    };

    class Weapon : public Item {
    public:
        explicit Weapon(const sf::String &name, const std::filesystem::path &iconPath): Item(
            ItemType::weapon, name, iconPath) {
        }

        void use(float x, float y, sfui::Mouse mouse, Barrage &barrage, Boss &boss) override = 0;

    private:
    };
} // game

#endif //ITEM_HPP
