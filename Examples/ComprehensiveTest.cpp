#include "TestReflectionModule.h"
#include "AdvancedTestTypes.h"
#include "GlobalFunctionsTest.h"

#include <iostream>

using namespace ursine;
using namespace meta;

void TestNamespaceReflection()
{
    std::cout << "\n========== 命名空间反射测试 ==========" << std::endl;
    
    Type entityType = Type::Get("GameEngine::Entity");
    if (entityType.IsValid())
    {
        std::cout << "找到类型: " << entityType.GetName() << std::endl;
        
        auto methods = entityType.GetMethods();
        std::cout << "方法数量: " << methods.size() << std::endl;
    }
}

void TestStaticMembers()
{
    std::cout << "\n========== 静态成员测试 ==========" << std::endl;
    
    Type type = typeof(StaticMembers);
    
    // 测试静态字段
    auto staticCounterField = type.GetStaticField("staticCounter");
    if (staticCounterField.IsValid())
    {
        std::cout << "静态字段: " << staticCounterField.GetName() << std::endl;
    }
    
    // 测试静态方法
    auto staticMethods = type.GetStaticMethods();
    for (auto& method : staticMethods)
    {
        if (method.IsValid())
        {
            std::cout << "静态方法: " << method.GetName() << std::endl;
        }
    }
}

void TestGlobalFunctions()
{
    std::cout << "\n========== 全局函数测试 ==========" << std::endl;
    
    // 通过 Type::Invalid() 获取全局作用域的函数
    Type globalScope = Type::Invalid();

    auto globalFunctions = globalScope.GetGlobalFunctions();
    std::cout << "全局函数数量: " << globalFunctions.size() << std::endl;

    // 遍历所有全局函数
    for (auto& func : globalFunctions)
    {
        std::cout << "  全局函数: " << func.GetName() << std::endl;

        // 尝试调用一些特定的函数
        if (func.GetName() == "GlobalPrint")
        {
            std::cout << "    调用 GlobalPrint:" << std::endl;
            func.Invoke(std::string("Hello from reflection!"));
        }
        else if (func.GetName() == "GlobalAdd")
        {
            std::cout << "    调用 GlobalAdd(10, 20):" << std::endl;
            Variant result = func.Invoke(10, 20);
            std::cout << "    结果: " << result.ToInt() << std::endl;
        }
        else if (func.GetName() == "GlobalMultiply")
        {
            std::cout << "    调用 GlobalMultiply(3.5, 2.0):" << std::endl;
            Variant result = func.Invoke(3.5f, 2.0f);
            std::cout << "    结果: " << result.ToFloat() << std::endl;
        }
    }
}

void TestGlobalVariables()
{
    std::cout << "\n========== 全局变量测试 ==========" << std::endl;

    // 通过 Type::Invalid() 获取全局作用域的变量
    Type globalScope = Type::Invalid();

    auto globalVars = globalScope.GetGlobals();
    std::cout << "全局变量数量: " << globalVars.size() << std::endl;

    // 遍历所有全局变量
    for (auto& global : globalVars)
    {
        std::cout << "  全局变量: " << global.GetName() << std::endl;
        std::cout << "    类型: " << global.GetType().GetName() << std::endl;
        std::cout << "    是否只读: " << (global.IsReadOnly() ? "是" : "否") << std::endl;

        // 测试特定的全局变量
        if (global.GetName() == "g_globalCounter")
        {
            std::cout << "    当前值: " << global.GetValue().ToInt() << std::endl;

            // 设置新值
            global.SetValue(42);
            std::cout << "    设置后: " << global.GetValue().ToInt() << std::endl;
            std::cout << "    实际值: " << g_globalCounter << std::endl;
        }
        else if (global.GetName() == "g_globalSpeed")
        {
            std::cout << "    当前值: " << global.GetValue().ToFloat() << std::endl;

            global.SetValue(2.5f);
            std::cout << "    设置后: " << global.GetValue().ToFloat() << std::endl;
            std::cout << "    实际值: " << g_globalSpeed << std::endl;
        }
        else if (global.GetName() == "g_globalName")
        {
            std::cout << "    当前值: " << global.GetValue().ToString() << std::endl;

            global.SetValue(std::string("ReflectedName"));
            std::cout << "    设置后: " << global.GetValue().ToString() << std::endl;
            std::cout << "    实际值: " << g_globalName << std::endl;
        }
    }
}

void TestConstructors()
{
    std::cout << "\n========== 构造函数测试 ==========" << std::endl;
    
    Type type = typeof(MultipleConstructors);
    auto ctors = type.GetConstructors();
    
    std::cout << "构造函数数量: " << ctors.size() << std::endl;
    
    // 测试不同的构造函数
    if (ctors.size() >= 3)
    {
        // 默认构造函数
        Variant obj1 = ctors[0].Invoke();
        
        // 单参数构造函数
        Variant obj2 = ctors[1].Invoke(100);
        
        // 双参数构造函数
        Variant obj3 = ctors[2].Invoke(10, 20);
    }
}

void TestInheritance()
{
    std::cout << "\n========== 继承测试 ==========" << std::endl;
    
    Type derivedType = typeof(Derived);
    Type baseType = typeof(Base);
    
    std::cout << "Derived 类型: " << derivedType.GetName() << std::endl;
    std::cout << "Base 类型: " << baseType.GetName() << std::endl;
    
    auto derivedFields = derivedType.GetFields();
    std::cout << "Derived 字段数量: " << derivedFields.size() << std::endl;
    
    for (auto& field : derivedFields)
    {
        std::cout << "  字段: " << field.GetName() << std::endl;
    }
}

int main(void)
{
    MetaInitialize( UsingModule( TestModule ) );

    std::cout << "========== 综合反射测试 ==========" << std::endl;

    TestNamespaceReflection();
    TestStaticMembers();
    TestGlobalFunctions();
    TestGlobalVariables();
    TestConstructors();
    TestInheritance();

    std::cout << "\n========== 测试完成 ==========" << std::endl;

    return 0;
}