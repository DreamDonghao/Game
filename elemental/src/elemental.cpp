#include <elemental.hpp>

namespace game {

    // ��ȡID
    int Elemental::getId() const { return m_id; }

    // ����/����Ԫ��
    void Elemental::setActive(bool activeState) { m_active = activeState; }
    bool Elemental::isActive() const { return m_active; }


    // �������캯������ֱֹ�Ӵ���Elemental����
    Elemental::Elemental(int id, bool active): m_id(id), m_active(active){}

}