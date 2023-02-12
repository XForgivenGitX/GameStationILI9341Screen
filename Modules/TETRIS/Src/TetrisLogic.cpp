#include <Inc/TetrisLogic.hpp>

TetrisManager::TetrisManager()
{
	field.resize(ROW_OF_FIELD * COL_OF_FIELD);
	myFigure = CreateFigure(*this);
}

void TetrisManager::EraseFilledRow()
{
	auto itBeg = field.begin();
	auto itEnd = itBeg;
	size_t row = 0;
	for (; itBeg != field.end(); itBeg += COL_OF_FIELD, ++row)
	{
		itEnd += COL_OF_FIELD;
		if (std::all_of(itBeg, itEnd, [](auto& block)
			{return block.isFeeled; }))
		{
			field.erase(itBeg, itEnd);
			field.insert(field.begin(), COL_OF_FIELD, {});
			itBeg = field.begin() + (COL_OF_FIELD * row);
			itEnd = itBeg + COL_OF_FIELD;
		}
	}
}

TetrisFigure::TetrisFigure(block_t&& figure_, Coordinate coordFigure_, size_t sideFigure_, color_t colorFigure, TetrisManager& manager_)
	: figure(std::move(figure_)), initFigure(figure), coord(coordFigure_), initCoord(coordFigure_), manager(manager_), side(sideFigure_)
{
	std::for_each(figure.begin(), figure.end(), [&](auto& part)
		{if (part.isFeeled) part.color = colorFigure; });
}

void TetrisFigure::Rotate()
{
	prevFigure = figure;
	auto tmpCoord = coord;
	auto counter = 1;
	size_t row = side - counter;
	std::for_each(figure.begin(), figure.end(), [&](auto& block)
		{block = prevFigure[row]; row += side; if (row > pow(side, 2)) row = side - ++counter; });
	while (CheckBoundaries());
	if (isIntersectionBlocks())
	{
		figure = prevFigure;
		coord = tmpCoord;
	}
}
void TetrisFigure::MoveHorizontally(Directions direction)
{
	auto tmpCoord = coord;
	switch (direction)
	{
	case Directions::LEFT: --coord.X; break;
	case Directions::RIGHT: ++coord.X; break;
	default: return;
	}
	CheckBoundaries();
	if (isIntersectionBlocks()) coord = tmpCoord;
}
bool TetrisFigure::MoveDown()
{
	++coord.Y;
	if (CheckBoundaries() || isIntersectionBlocks())
	{
		if(CheckEndGame()) return true;
		FillFieldFigure();
		figure = initFigure;
		coord = initCoord;
		return false;
	}
	else return true;
}

bool TetrisFigure::CheckBoundaries()
{
	bool returnStatus = false;
	if ((coord.Y + side - 1) >= ROW_OF_FIELD)
	{
		if (isContainsUnitInRow((ROW_OF_FIELD - (coord.Y + (side - 1)) + (side - 1))))
		{
			coord.Y -= 1; returnStatus = true;
		}
	}
	else if (coord.X < 0)
	{
		if (isContainsUnitInColumne(abs(coord.X) - 1))
		{
			coord.X += 1; returnStatus = true;
		}
	}
	else if ((coord.X + side - 1) >= COL_OF_FIELD)
	{
		if (isContainsUnitInColumne((COL_OF_FIELD - (coord.X + (side - 1)) + (side - 1))))
		{
			coord.X -= 1; returnStatus = true;
		}
	}
	return returnStatus;
}

bool TetrisFigure::isContainsUnitInColumne(size_t icol)
{
	size_t irow = 0;
	auto lambd1 = [&](auto& block)
	{
		if (irow == side) irow = 0;
		if (irow++ == icol) return !block.isFeeled;
		else return true;
	};
	return !std::all_of(figure.begin(), figure.end(), lambd1);
}
bool TetrisFigure::isContainsUnitInRow(size_t irow)
{
	size_t counter = 0;
	auto lambd2 = [&](auto& block)
	{
		if (irow == size_t(counter++ / side)) return !block.isFeeled;
		else return true;
	};
	return !std::all_of(figure.begin(), figure.end(), lambd2);
}
bool TetrisFigure::isIntersectionBlocks()
{
	size_t row = 0, col = 0;
	bool flag = false;
	auto lambd3 = [&](auto& block)
	{
		flag = false;
		if (block.isFeeled) {
			if (manager.field[((coord.Y + row) * COL_OF_FIELD) + coord.X + col].isFeeled)
				flag = true;
		}
		if (++col == side) { ++row, col = 0; }
		return flag;
	};
	return std::any_of(figure.begin(), figure.end(), lambd3);
}

void TetrisFigure::FillFieldFigure()
{
	size_t row = 0, col = 0;
	auto lambd4 = [&](auto& block)
	{
		if (block.isFeeled)
		{
			auto index = ((coord.Y + row) * COL_OF_FIELD) + coord.X + col;
			manager.field[index].isFeeled = true;
			manager.field[index].color = block.color;
		}
		if (++col == side) { ++row, col = 0; }
	};
	std::for_each(figure.begin(), figure.end(), lambd4);
}
bool TetrisFigure::CheckEndGame()
{
	if((coord.Y < HIDDEN_ROW_OF_FIELD) && ((coord.Y + (side - 1) >= HIDDEN_ROW_OF_FIELD)))
	{
		if(isContainsUnitInRow((HIDDEN_ROW_OF_FIELD - 1) - coord.Y))
		{
			manager.END_OF_GAME = false;
			return true;
		}
	}
	return false;
}
std::vector<TetrisFigure>&& CreateFigure(TetrisManager& man)
{
	block_t fig1
	{
		{0},{0},{1},{0},
		{0},{0},{1},{0},
		{0},{0},{1},{0},
		{0},{0},{1},{0}
	};
	block_t fig2
	{
		{1},{1},{0},
		{0},{1},{0},
		{0},{1},{0}
	};
	block_t fig3
	{
		{0},{1},{0},
		{0},{1},{0},
		{0},{1},{1}
	};
	block_t fig4
	{
		{0},{1},{0},
		{0},{1},{1},
		{0},{0},{1}
	};
	block_t fig5
	{
		{0},{1},{0},
		{1},{1},{0},
		{1},{0},{0}
	};
	block_t fig6
	{
		{0},{1},{0},
		{1},{1},{0},
		{0},{1},{0}
	};
	block_t fig7
	{
		{1},{1},
		{1},{1}
	};
	std::vector<TetrisFigure> myFigure;
	myFigure.reserve(QUANTITY_FIGURE);
	myFigure.emplace_back(std::move(fig1), Coordinate{ 6, 0 }, 4, FIG1COLOR, man);
	myFigure.emplace_back(std::move(fig2), Coordinate{ 6, 1 }, 3, FIG2COLOR, man);
	myFigure.emplace_back(std::move(fig3), Coordinate{ 6, 1 }, 3, FIG3COLOR, man);
	myFigure.emplace_back(std::move(fig4), Coordinate{ 6, 1 }, 3, FIG4COLOR, man);
	myFigure.emplace_back(std::move(fig5), Coordinate{ 6, 1 }, 3, FIG5COLOR, man);
	myFigure.emplace_back(std::move(fig6), Coordinate{ 6, 1 }, 3, FIG6COLOR, man);
	myFigure.emplace_back(std::move(fig7), Coordinate{ 6, 2 }, 2, FIG7COLOR, man);
	return std::move(myFigure);
}
