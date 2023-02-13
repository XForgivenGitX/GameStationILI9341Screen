#pragma once
#include <Inc/TetrisLogic.hpp>
#include <Inc/MainThread.hpp>

constexpr uint32_t TetrisHighDelay 	= 250;
constexpr uint32_t TetrisLowDelay 	= 100;

void TetrisTask();
bool TetrisButtonHandler(TetrisFigure& figure, uint32_t& delay);