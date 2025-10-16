#pragma once

#include <Meta.h>
#include "TestProperties.h"
#include <string>
#include <vector>

// ==================== 命名空间测试 ====================
namespace GameEngine
{
    // 命名空间中的枚举
    enum class EntityType
    {
        Player,
        Enemy,
        NPC,
        Item
    } Meta(Enable);

    // 命名空间中的类
    class Entity
    {
    public:
        Meta(Enable)
        Entity() : id(0), name("Unnamed"), type(EntityType::Player) {}

        Meta(Enable)
        Entity(int id, const std::string& name) 
            : id(id), name(name), type(EntityType::Player) {}

        // 成员变量
        Meta(Enable)
        int id;

        Meta(Enable)
        std::string name;

        Meta(Enable)
        EntityType type;

        // 成员方法
        Meta(Enable)
        void SetName(const std::string& newName) 
        {
            name = newName;
            std::cout << "Entity name set to: " << name << std::endl;
        }

        Meta(Enable)
        std::string GetName() const 
        {
            return name;
        }

        Meta(Enable)
        int GetId() const 
        {
            return id;
        }

        // 带多个参数的方法
        Meta(Enable)
        void Initialize(int newId, const std::string& newName, EntityType newType)
        {
            id = newId;
            name = newName;
            type = newType;
            std::cout << "Entity initialized: " << id << ", " << name << std::endl;
        }
    } Meta(Enable);

} // namespace GameEngine

// ==================== 继承测试 ====================
class Base
{
public:
    Meta(Enable)
    Base() : baseValue(0) {}

    Meta(Enable)
    int baseValue;

    Meta(Enable)
    virtual void BaseMethod()
    {
        std::cout << "Base::BaseMethod called" << std::endl;
    }

    Meta(Enable)
    void CommonMethod()
    {
        std::cout << "Base::CommonMethod" << std::endl;
    }
} Meta(Enable);

class Derived : public Base
{
public:
    Meta(Enable)
    Derived() : derivedValue(0) {}

    Meta(Enable)
    int derivedValue;

    Meta(Enable)
    void DerivedMethod()
    {
        std::cout << "Derived::DerivedMethod called" << std::endl;
    }

    Meta(Enable)
    virtual void BaseMethod() override
    {
        std::cout << "Derived::BaseMethod called (overridden)" << std::endl;
    }
} Meta(Enable);

// ==================== 静态成员测试 ====================
class StaticMembers
{
public:
    Meta(Enable)
    StaticMembers() : instanceValue(0) {}

    // 静态变量
    Meta(Enable)
    static int staticCounter;

    Meta(Enable)
    static std::string staticName;

    // 实例变量
    Meta(Enable)
    int instanceValue;

    // 静态方法
    Meta(Enable)
    static int GetStaticCounter()
    {
        return staticCounter;
    }

    Meta(Enable)
    static void IncrementCounter()
    {
        staticCounter++;
        std::cout << "Static counter: " << staticCounter << std::endl;
    }

    Meta(Enable)
    static void ResetCounter()
    {
        staticCounter = 0;
    }

    // 实例方法
    Meta(Enable)
    void SetInstanceValue(int value)
    {
        instanceValue = value;
    }

    Meta(Enable)
    int GetInstanceValue() const
    {
        return instanceValue;
    }
} Meta(Enable);

// ==================== 重载方法测试 ====================
class OverloadedMethods
{
public:
    Meta(Enable)
    OverloadedMethods() : value(0) {}

    Meta(Enable)
    int value;

    // 方法重载 - 无参数
    Meta(Enable)
    void Process()
    {
        std::cout << "Process() - no parameters" << std::endl;
    }

    // 方法重载 - 一个参数
    Meta(Enable)
    void Process(int x)
    {
        value = x;
        std::cout << "Process(int) - value set to: " << x << std::endl;
    }

    // 方法重载 - 两个参数
    Meta(Enable)
    void Process(int x, int y)
    {
        value = x + y;
        std::cout << "Process(int, int) - value set to: " << (x + y) << std::endl;
    }

    // 方法重载 - 字符串参数
    Meta(Enable)
    void Process(const std::string& str)
    {
        std::cout << "Process(string) - " << str << std::endl;
    }

    // 返回值不同的重载
    Meta(Enable)
    int GetValue() const
    {
        return value;
    }

    Meta(Enable)
    float GetValueAsFloat() const
    {
        return static_cast<float>(value);
    }
} Meta(Enable);

// ==================== 构造函数测试 ====================
class MultipleConstructors
{
public:
    Meta(Enable)
    int x;

    Meta(Enable)
    int y;

    Meta(Enable)
    std::string label;

    // 默认构造函数
    Meta(Enable)
    MultipleConstructors() : x(0), y(0), label("default") 
    {
        std::cout << "Default constructor" << std::endl;
    }

    // 单参数构造函数
    Meta(Enable)
    MultipleConstructors(int value) : x(value), y(value), label("single") 
    {
        std::cout << "Single parameter constructor: " << value << std::endl;
    }

    // 双参数构造函数
    Meta(Enable)
    MultipleConstructors(int xVal, int yVal) : x(xVal), y(yVal), label("double") 
    {
        std::cout << "Two parameter constructor: " << xVal << ", " << yVal << std::endl;
    }

    // 三参数构造函数
    Meta(Enable)
    MultipleConstructors(int xVal, int yVal, const std::string& labelVal)
        : x(xVal), y(yVal), label(labelVal) 
    {
        std::cout << "Three parameter constructor: " << xVal << ", " << yVal 
                  << ", " << labelVal << std::endl;
    }

    Meta(Enable)
    void Print() const
    {
        std::cout << "x: " << x << ", y: " << y << ", label: " << label << std::endl;
    }
} Meta(Enable);

// ==================== const 和引用测试 ====================
class ConstAndReferences
{
public:
    Meta(Enable)
    ConstAndReferences() : value(0) {}

    Meta(Enable)
    int value;

    // const 方法
    Meta(Enable)
    int GetValue() const
    {
        return value;
    }

    // 非 const 方法
    Meta(Enable)
    void SetValue(int v)
    {
        value = v;
    }

    // 接受 const 引用参数
    Meta(Enable)
    void ProcessConst(const int& v)
    {
        std::cout << "ProcessConst: " << v << std::endl;
    }

    // 返回引用
    Meta(Enable)
    int& GetValueRef()
    {
        return value;
    }
} Meta(Enable);

// ==================== 嵌套类型测试 ====================
class OuterClass
{
public:
    Meta(Enable)
    OuterClass() : outerValue(0) {}

    Meta(Enable)
    int outerValue;

    // 嵌套枚举
    enum class Status
    {
        Idle,
        Active,
        Paused,
        Stopped
    } Meta(Enable);

    Meta(Enable)
    Status currentStatus;

    // 嵌套结构体
    struct InnerData
    {
        Meta(Enable)
        int innerValue;

        Meta(Enable)
        std::string innerName;

        Meta(Enable)
        InnerData() : innerValue(0), innerName("") {}
    } Meta(Enable);

    Meta(Enable)
    InnerData data;

    Meta(Enable)
    void SetStatus(Status status)
    {
        currentStatus = status;
    }
} Meta(Enable);

// ==================== 模板和数组测试 ====================
class ArrayContainer
{
public:
    Meta(Enable)
    ArrayContainer() : count(0) {}

    Meta(Enable)
    int count;

    Meta(Enable)
    ursine::Array<int> intArray;

    Meta(Enable)
    ursine::Array<float> floatArray;

    Meta(Enable)
    ursine::Array<std::string> stringArray;

    Meta(Enable)
    void AddInt(int value)
    {
        intArray.emplace_back(value);
        count++;
    }

    Meta(Enable)
    void ClearArrays()
    {
        intArray.clear();
        floatArray.clear();
        stringArray.clear();
        count = 0;
    }

    Meta(Enable)
    int GetCount() const
    {
        return count;
    }
} Meta(Enable);

// ==================== 元属性应用测试 ====================
class MetaPropertyExample
{
public:
    Meta(Enable)
    MetaPropertyExample() : health(100.0f), speed(1.0f), experience(0) {}

    // 应用 Range 属性
    Meta(Enable, Range(0.0f, 100.0f))
    float health;

    // 应用多个元属性
    Meta(Enable, Range(0.0f, 10.0f), Slider(SliderType::Horizontal))
    float speed;

    Meta(Enable, Range(0.0f, 1000.0f), Slider(SliderType::Vertical))
    int experience;

    Meta(Enable)
    void TakeDamage(float damage)
    {
        health -= damage;
        if (health < 0.0f) health = 0.0f;
        std::cout << "Health: " << health << std::endl;
    }

    Meta(Enable)
    void Heal(float amount)
    {
        health += amount;
        if (health > 100.0f) health = 100.0f;
        std::cout << "Health: " << health << std::endl;
    }
} Meta(Enable);