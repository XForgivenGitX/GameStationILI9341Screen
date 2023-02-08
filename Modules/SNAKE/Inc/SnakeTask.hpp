#pragma once
#include <Inc/SnakeLogic.hpp>
#include <Inc/MainThread.hpp>

constexpr uint32_t SIZE_SIDE_SQUARE = 15;
constexpr uint32_t RADIUS_ROUNDING = 2;
constexpr uint32_t INIT_SPEED_GAME = 200;
constexpr uint32_t FINAL_SPEED_GAME = 100;
//namespace snake{



void SnakeButtonHandler();
void printSquare(snake::SnakeNode& sn);
void SnakeTask();
void SnakeInterface();
uint32_t computeTimeDuration(uint32_t time);
//}
