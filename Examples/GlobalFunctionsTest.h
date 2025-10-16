#pragma once

#include <Meta.h>
#include <string>
#include <iostream>

// ==================== 全局变量 ====================
Meta(Enable)
extern int g_globalCounter;

Meta(Enable)
extern float g_globalSpeed;

Meta(Enable)
extern std::string g_globalName;

// ==================== 全局常量 ====================
Meta(Enable)
extern const int g_maxPlayers;

Meta(Enable)
extern const float g_gravity;

// ==================== 全局枚举 ====================
enum GlobalGameState
{
    GS_MainMenu,
    GS_Playing,
    GS_Paused,
    GS_GameOver
} Meta(Enable);

Meta(Enable)
extern GlobalGameState g_currentGameState;

// ==================== 全局函数 ====================

// 简单的全局函数
Meta(Enable)
void GlobalPrint(const std::string& message);

Meta(Enable)
int GlobalAdd(int a, int b);

Meta(Enable)
float GlobalMultiply(float a, float b);

// 无参数全局函数
Meta(Enable)
void GlobalInitialize();

Meta(Enable)
void GlobalShutdown();

// 返回复杂类型
Meta(Enable)
std::string GlobalGetVersion();

Meta(Enable)
int GlobalGetRandomNumber();

// 多参数函数
Meta(Enable)
void GlobalLog(int level, const std::string& category, const std::string& message);

Meta(Enable)
float GlobalCalculate(float x, float y, float z);

// 返回 void 的函数
Meta(Enable)
void GlobalResetAll();

Meta(Enable)
void GlobalIncrementCounter();

// 状态查询函数
Meta(Enable)
bool GlobalIsInitialized();

Meta(Enable)
int GlobalGetCounter();

Meta(Enable)
float GlobalGetSpeed();