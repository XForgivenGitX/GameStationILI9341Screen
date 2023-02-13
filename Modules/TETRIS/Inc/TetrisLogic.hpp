#pragma once
#include <Inc/General.hpp>

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
	block_t field{};
	std::vector<TetrisFigure> myFigure{};
	random_generator generator{};
	bool END_OF_GAME = true;

	TetrisManager();
	void EraseFilledRow();
};

struct TetrisFigure
{
	block_t figure, prevFigure;
	block_t initFigure;

	Coordinate coord;
	Coordinate initCoord;

	TetrisManager& manager;
	size_t side;

	TetrisFigure(block_t&& figure_, Coordinate coordFigure_, size_t sideFigure_,
		color_t colorFigure, TetrisManager& manager_);
	//TetrisFigure(const TetrisFigure& TF) = delete;
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
