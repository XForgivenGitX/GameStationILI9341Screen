#pragma once
#include <Inc/General.hpp>

/*
 * 1 add const
 * 2 change structure
 * 3 add namespace
 * 4 remove printfigure-function overload
 * 5...
 *
 * */

constexpr auto ROW_OF_FIELD			= 20;
constexpr auto HIDDEN_ROW_OF_FIELD	= 4;
constexpr auto COL_OF_FIELD			= 10;//21
constexpr auto QUANTITY_FIGURE		= 7;

struct PartTetrisBlock;
struct TetrisFigure;

using color_t = uint32_t;
using block_t = std::vector<PartTetrisBlock>;

enum Colors
{
	BACKGROUND = ILI9341_NAVY,
	FIG1COLOR = ILI9341_CYAN,
	FIG2COLOR = ILI9341_GREEN,
	FIG3COLOR = ILI9341_OLIVE,
	FIG4COLOR = ILI9341_RED,
	FIG5COLOR = ILI9341_PINK,
	FIG6COLOR = ILI9341_WHITE,
	FIG7COLOR = ILI9341_YELLOW
};
enum class Directions{LEFT, RIGHT};

struct PartTetrisBlock
{
	bool isFeeled;
	color_t color;
	PartTetrisBlock(bool isFeeled_ = false, color_t color_ = BACKGROUND) : isFeeled(isFeeled_), color(color_) {}
};

struct TetrisManager
{
	std::vector<TetrisFigure>::iterator currentFigure;
	block_t field{};
	bool END_OF_GAME = false;

	TetrisManager();
	bool EraseFilledRow();
	void GenerateNewFigure();

private:
	std::vector<TetrisFigure> myFigure;
	random_generator generator{};
};

struct TetrisFigure
{
	block_t figure, prevFigure, initFigure;
	Coordinate initCoord, prevCoord, coord;

	TetrisManager& manager;
	const size_t side;

	TetrisFigure(block_t&& figure_, Coordinate coordFigure_, size_t sideFigure_,
		color_t colorFigure, TetrisManager& manager_);

	void Rotate();
	void MoveHorizontally(Directions direction);
	bool MoveDown();

private:
	bool CheckBoundaries();

	bool isContainsUnitInColumne(size_t icol);
	bool isContainsUnitInRow(size_t irow);
	bool isIntersectionBlocks();

	void FillFieldFigure();
	bool CheckEndGame();
};

std::vector<TetrisFigure> CreateFigure(TetrisManager& man);
