#include <elemental.hpp>

namespace game {

    // 获取ID
    int Elemental::getId() const { return m_id; }

    // 激活/禁用元素
    void Elemental::setActive(bool activeState) { m_active = activeState; }
    bool Elemental::isActive() const { return m_active; }


    // 保护构造函数，防止直接创建Elemental对象
    Elemental::Elemental(int id, bool active): m_id(id), m_active(active){}

}
