#pragma once

namespace game {

    // 元素，是游戏世界内所有内容
    class Elemental {
    public:
        // 虚拟析构函数
        virtual ~Elemental() {} 

        // 获取ID
        int getId() const;

        // 激活/禁用元素
        void setActive(bool activeState);

        // 返回是否活跃
        bool isActive() const;

    protected:
        // 保护构造函数，防止直接创建Elemental对象
        Elemental(int id,bool active);

    private:
        int m_id;           // 元素的唯一标识符
        bool m_active;      // 元素是否活跃
    };

}