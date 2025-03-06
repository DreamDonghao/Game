#pragma once

namespace game {

    // Ԫ�أ�����Ϸ��������������
    class Elemental {
    public:
        // ������������
        virtual ~Elemental() {} 

        // ��ȡID
        int getId() const;

        // ����/����Ԫ��
        void setActive(bool activeState);

        // �����Ƿ��Ծ
        bool isActive() const;

    protected:
        // �������캯������ֱֹ�Ӵ���Elemental����
        Elemental(int id,bool active);

    private:
        int m_id;           // Ԫ�ص�Ψһ��ʶ��
        bool m_active;      // Ԫ���Ƿ��Ծ
    };

}