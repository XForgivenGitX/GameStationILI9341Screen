#pragma once
#include "stm32f1xx_hal.h"
#include <main.hpp>
#include <Inc/SnakeTask.hpp>
#include <Inc/TetrisTask.hpp>
#include <Inc/but_main.hpp>
#include <Adafruit_GFX.hpp>
//#include <Fonts/FreeSansOblique9pt7b.h>

extern but::ButtonWrapper* but1;
extern but::ButtonWrapper* but2;
extern but::ButtonWrapper* but3;
extern but::ButtonWrapper* but4;

void MainThread();
void SysTickThread();
void MainInit();

