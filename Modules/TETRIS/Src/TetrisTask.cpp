#include <Inc/TetrisTask.hpp>

extern but::ButtonWrapper* but1;
extern but::ButtonWrapper* but2;
extern but::ButtonWrapper* but3;
extern but::ButtonWrapper* but4;

bool TetrisButtonHandler(TetrisFigure& figure, uint32_t& delay)
{

	if(but4->LogicState_ != LogicState::NONE)
	{
		if(but4->LogicState_ == LogicState::WAS_PRESSED)
		{
			delay = TETRIS_LOW_DELAY;
			but4->LogicState_ = LogicState::WAS_SHORT_PRESSED;
		}
		else if(but4->LogicState_ == LogicState::WAS_RELEASED)
		{
			delay = TETRIS_HIGH_DELAY;
			but4->LogicState_ = LogicState::NONE;
		}

	}
	else if(but1->LogicState_ == LogicState::WAS_PRESSED){
		figure.MoveHorizontally(Directions::LEFT);
		but1->LogicState_ = LogicState::NONE;
		return true;
	}
	else if(but2->LogicState_ == LogicState::WAS_PRESSED){
		figure.MoveHorizontally(Directions::RIGHT);
		but2->LogicState_ = LogicState::NONE;
		return true;
	}
	else if(but3->LogicState_ == LogicState::WAS_PRESSED){
		figure.Rotate();
		but3->LogicState_ = LogicState::NONE;
		return true;
	}
	return false;
}

void PrintTetrisFigure(const block_t& block, const Coordinate& coord, size_t side, color_t color)
{
	size_t row = 0, col = 0;
	std::for_each(block.begin(), block.end(), [&](auto& subblock)
	{
		if(subblock.isFeeled && (coord.Y + row >= HIDDEN_ROW_OF_FIELD))
		{
			tft_fillRoundRect((coord.X + col) * SIDE_SQUARE,
					(coord.Y + row - HIDDEN_ROW_OF_FIELD) * SIDE_SQUARE,
					SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, color);
		}
		if (++col == side) { ++row, col = 0; }
	});
}

void PrintTetrisFigure(const block_t& block, const Coordinate& coord, size_t side)
{
	size_t row = 0, col = 0;
	std::for_each(block.begin(), block.end(), [&](auto& subblock)
	{
		if(subblock.isFeeled && (coord.Y + row >= HIDDEN_ROW_OF_FIELD))
		{
			tft_fillRoundRect((coord.X + col) * SIDE_SQUARE,
					(coord.Y + row - HIDDEN_ROW_OF_FIELD) * SIDE_SQUARE,
					SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, subblock.color);
		}
		if (++col == side) { ++row, col = 0; }
	});
}
void PrintedField(TetrisManager& manager)
{
	for(auto i = 0; i < ROW_OF_FIELD; ++i)
		for(auto j = 0; j < COL_OF_FIELD; ++j)
			tft_fillRoundRect(j * SIDE_SQUARE, i * SIDE_SQUARE,
			SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, manager.field[i * j].color);
}


void TetrisTask()
{
	tft_fillScreen(BACKGROUND);
	tft_setRotation(PORTRAIT_ORIENTATION);

	TetrisManager manager;

	uint32_t delay = TETRIS_HIGH_DELAY;
	uint32_t time = HAL_GetTick();

	while(manager.END_OF_GAME)
	{
		if(!manager.currentFigure->MoveDown())
		{
			if(manager.EraseFilledRow())
			{
				PrintedField(manager);
			}
			manager.GenerateNewFigure();
		}
		else
		{
			PrintTetrisFigure(manager.currentFigure->prevFigure, manager.currentFigure->prevCoord, manager.currentFigure->side, BACKGROUND);
		}
		PrintTetrisFigure(manager.currentFigure->figure, manager.currentFigure->coord, manager.currentFigure->side);
		while(computeTimeDuration(time) < delay)
		{
			if(TetrisButtonHandler(*manager.currentFigure, delay))
			{
				PrintTetrisFigure(manager.currentFigure->prevFigure, manager.currentFigure->prevCoord, manager.currentFigure->side, BACKGROUND);
				PrintTetrisFigure(manager.currentFigure->figure, manager.currentFigure->coord, manager.currentFigure->side);
			}
		}
		time = HAL_GetTick();
	}
	while(but1->LogicState_ != LogicState::WAS_HOLDED)computeTimeDuration(time);
}
