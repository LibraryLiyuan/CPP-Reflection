#include "GlobalFunctionsTest.h"

// 全局变量定义
int g_globalCounter = 0;
float g_globalSpeed = 1.0f;
std::string g_globalName = "DefaultName";

const int g_maxPlayers = 4;
const float g_gravity = 9.81f;

GlobalGameState g_currentGameState = GS_MainMenu;

static bool g_initialized = false;

// 全局函数实现
void GlobalPrint(const std::string& message)
{
    std::cout << "[Global] " << message << std::endl;
}

int GlobalAdd(int a, int b)
{
    return a + b;
}

float GlobalMultiply(float a, float b)
{
    return a * b;
}

void GlobalInitialize()
{
    g_initialized = true;
    g_globalCounter = 0;
    g_globalSpeed = 1.0f;
    std::cout << "[Global] System initialized" << std::endl;
}

void GlobalShutdown()
{
    g_initialized = false;
    std::cout << "[Global] System shutdown" << std::endl;
}

std::string GlobalGetVersion()
{
    return "1.0.0";
}

int GlobalGetRandomNumber()
{
    return rand() % 100;
}

void GlobalLog(int level, const std::string& category, const std::string& message)
{
    std::cout << "[Level " << level << "][" << category << "] " << message << std::endl;
}

float GlobalCalculate(float x, float y, float z)
{
    return (x + y) * z;
}

void GlobalResetAll()
{
    g_globalCounter = 0;
    g_globalSpeed = 1.0f;
    g_globalName = "DefaultName";
    g_currentGameState = GS_MainMenu;
    std::cout << "[Global] All globals reset" << std::endl;
}

void GlobalIncrementCounter()
{
    g_globalCounter++;
}

bool GlobalIsInitialized()
{
    return g_initialized;
}

int GlobalGetCounter()
{
    return g_globalCounter;
}

float GlobalGetSpeed()
{
    return g_globalSpeed;
}