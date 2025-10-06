//
// Created by donghao on 25-10-5.
//
#ifndef TESTITEMS_HPP
#define TESTITEMS_HPP
#include <base/item.hpp>

namespace game {
    class TestItem final : public AutoItem<TestItem> {
    public:
        TestItem(){}
        ~TestItem() override = default;
        void use() override{}
        static ItemRegistrar<TestItem> reg;
    private:
        static constexpr unsigned long long typeId = -1;
    };

    ItemRegistrar<TestItem> TestItem::reg("test1");


} // game

#endif //TESTITEMS_HPP
