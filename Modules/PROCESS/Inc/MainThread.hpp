#pragma once
#include <main.hpp>
#include "stm32f1xx_hal.h"
#include <Inc/SnakeTask.hpp>
#include <Inc/but_main.hpp>
#include <Adafruit_GFX.hpp>

#define i

extern but::ButtonWrapper* but1;
extern but::ButtonWrapper* but2;
extern but::ButtonWrapper* but3;
extern but::ButtonWrapper* but4;

void MainThread();
void SysTickThread();
void MainInit();

