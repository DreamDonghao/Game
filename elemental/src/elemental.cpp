#include <elemental.hpp>

namespace game {

    // 获取ID
    int Elemental::getId() const { return m_id; }

    // 激活/禁用元素
    void Elemental::setActive(bool activeState) { m_active = activeState; }
    bool Elemental::isActive() const { return m_active; }

}
