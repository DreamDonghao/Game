//
// Created by donghao on 25-8-25.
//
#ifndef ITEM_HPP
#define ITEM_HPP
#include <functional>
#include <memory>
#include <string>

// namespace game {
//     enum class ItemType { weapon, potion };
//
//     inline int getItemTypeMaxStack(const ItemType itemType) {
//         switch (itemType) {
//             case ItemType::weapon:
//                 return 1;
//             case ItemType::potion:
//                 return 100;
//         }
//         return 0;
//     }
//
//     class Item {
//     public:
//         virtual ~Item() = default;
//
//         explicit Item(const ItemType type, const sf::String &name, const std::filesystem::path &iconPath)
//             : m_name(name), m_type(type), m_maxStack(getItemTypeMaxStack(type)) {
//             if (!m_icon.loadFromFile(iconPath.string())) {
//                 std::cerr << "Failed to load icon from " << iconPath.string() << std::endl;
//             }
//         }
//
//         [[nodiscard]] ItemType getType() const {
//             return m_type;
//         }
//
//         virtual void use(float playerX, float playerY, sfui::Mouse mouse, Barrage &barrage, Boss &boss) = 0;
//
//         virtual const sf::Texture &getIcon() const {
//             return m_icon;
//         }
//
//     private:
//         sf::String m_name;
//         ItemType m_type;
//         int m_maxStack;
//         sf::Texture m_icon;
//     };
//
//     class Weapon : public Item {
//     public:
//         explicit Weapon(const sf::String &name, const std::filesystem::path &iconPath): Item(
//             ItemType::weapon, name, iconPath) {
//         }
//
//         void use(float x, float y, sfui::Mouse mouse, Barrage &barrage, Boss &boss) override = 0;
//
//     private:
//     };
// } // game

namespace game {

    class Item {
    public:
        virtual ~Item() = default;
        virtual void use() = 0;
        void setName(const std::string &name) {
            m_name = name;
        }
        std::string getName() {
            return m_name;
        }
    private:
        static constexpr unsigned long long typeId = 0;
        std::string m_name;
        unsigned long long id = 0;
    };

    template<typename Derived>
    class AutoItem : public Item {
    protected:
        static void check() {
            (void) Derived::reg;
        }
        AutoItem() { check(); }
    };

    class ItemFactory {
    public:
        using Creator = std::function<std::unique_ptr<Item>()>;

        static ItemFactory &instance() {
            static ItemFactory itemFactory;
            return itemFactory;
        }

        void registerType(const std::string &name, Creator creator) {
            m_creators[name] = std::move(creator);
        }

        std::unique_ptr<Item> create(const std::string &name) {
            if (const auto it = m_creators.find(name); it != m_creators.end()) {
                auto item = it->second();
                item->setName(name);
                return item;
            }
            return nullptr;
        }
    private:
        std::unordered_map<std::string, Creator > m_creators;
    };

    template<typename T>
    struct ItemRegistrar {
        explicit ItemRegistrar(const std::string &name) {
            ItemFactory::instance().registerType(name, [] {
                return std::make_unique<T>();
            });
        }
    };

}
#endif //ITEM_HPP
