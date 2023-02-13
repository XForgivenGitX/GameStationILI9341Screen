#pragma once
#include <Inc/TetrisLogic.hpp>
#include <Inc/MainThread.hpp>

constexpr uint32_t TETRIS_HIGH_DELAY 	= 250;
constexpr uint32_t TETRIS_LOW_DELAY 	= 100;
constexpr uint32_t SQUARE_RADIUS 		= 3;
constexpr uint32_t SIDE_SQUARE 			= 15;

void TetrisTask();
bool TetrisButtonHandler(TetrisFigure& figure, uint32_t& delay);
void PrintTetrisFigure(const block_t& block, const Coordinate& coord, size_t side, color_t color);
void PrintTetrisFigure(const block_t& block, const Coordinate& coord, size_t side);
void PrintedField(TetrisManager& manager);
