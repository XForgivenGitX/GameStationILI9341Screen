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

constexpr auto ROW_OF_FIELD			= 25;
constexpr auto HIDDEN_ROW_OF_FIELD 	= 4;
constexpr auto COL_OF_FIELD			= 16;
constexpr auto QUANTITY_FIGURE		= 7;

struct PartTetrisBlock;
struct TetrisFigure;

using color_t = uint32_t;
using block_t = std::vector<PartTetrisBlock>;

enum TetrisColors
{
	BACKGROUND 	= ILI9341_BLACK,
	FIG1COLOR 	= ILI9341_BLUE,
	FIG2COLOR 	= ILI9341_DARKCYAN,
	FIG3COLOR 	= ILI9341_OLIVE,
	FIG4COLOR 	= ILI9341_GREEN,
	FIG5COLOR 	= ILI9341_RED,
	FIG6COLOR 	= ILI9341_PURPLE,
	FIG7COLOR 	= ILI9341_YELLOW
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
	bool END_OF_GAME = true;

	TetrisManager();
	bool EraseFilledRow();
	void GenerateNewFigure();

private:
	std::vector<TetrisFigure> myFigure{};
	random_generator generator{};
};

struct TetrisFigure
{
	block_t figure, prevFigure;
	const block_t initFigure;

	Coordinate coord, prevCoord;
	const Coordinate initCoord;

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

	bool CheckEndGame();
	void FillFieldFigure();
};

std::vector<TetrisFigure>&& CreateFigure(TetrisManager& man);
