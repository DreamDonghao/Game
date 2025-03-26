#pragma once
const double PI = 3.14159265358979323846;
namespace game {

    // 元素，是游戏世界内所有内容
    class Elemental {
    public:
        Elemental();

// 虚拟析构函数
        virtual ~Elemental() = default;

        // 获取ID
        [[nodiscard]] int getId() const;

        // 设置元素激活状态
        void setActive(bool activeState);

        // 返回是否活跃
        [[nodiscard]] bool isActive() const;

    protected:
        // 保护构造函数，防止直接创建Elemental对象
        Elemental(int id,bool active);

    private:
        int m_id;           // 元素的唯一标识符
        bool m_active;      // 元素是否活跃
    };

}
