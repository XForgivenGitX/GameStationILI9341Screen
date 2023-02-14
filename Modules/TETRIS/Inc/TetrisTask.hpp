#pragma once
#include <Inc/TetrisLogic.hpp>
#include <Inc/MainThread.hpp>

constexpr uint32_t TETRIS_HIGH_DELAY 	= 500;
constexpr uint32_t TETRIS_LOW_DELAY 	= 100;
constexpr uint32_t SQUARE_RADIUS 		= 3;
constexpr uint32_t SIDE_SQUARE 			= 15;

void TetrisTask();
bool TetrisButtonHandler(TetrisFigure& figure, uint32_t& delay);
void PrintTetrisField(block_t& myBlock);
void ErasePrevFigure(const TetrisFigure& figure);
void PrintTetrisFigure(const TetrisFigure& figure);
