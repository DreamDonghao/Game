//
// Created by donghao on 25-10-5.
//
#ifndef ITEM_INVENTORY_HPP
#define ITEM_INVENTORY_HPP
#include <iostream>
#include <memory>
#include <vector>
#include <test/testitems.hpp>

namespace game {
    class Item_Inventory {
    public:
        explicit Item_Inventory(std::vector<std::pair<std::unique_ptr<Item>, int> > *items)
            : m_items(items) {
        }

        void printItemMessage() {
            for (auto &[item,num]:*m_items) {
                std::cout<<item->getName()<<" "<<num<<std::endl;
            }
        }

    private:
        std::vector<std::pair<std::unique_ptr<Item>, int> > *m_items;
    };
} // game

#endif //ITEM_INVENTORY_HPP
