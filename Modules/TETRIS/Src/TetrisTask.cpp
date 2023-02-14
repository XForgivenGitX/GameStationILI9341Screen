#include <Inc/TetrisTask.hpp>

extern but::ButtonWrapper* but1;
extern but::ButtonWrapper* but2;
extern but::ButtonWrapper* but3;
extern but::ButtonWrapper* but4;

bool TetrisButtonHandler(TetrisFigure& figure, uint32_t& delay)
{

	if(but3->LogicState_ != LogicState::NONE)
	{
		if(but3->LogicState_ == LogicState::WAS_PRESSED)
		{
			delay = TETRIS_LOW_DELAY;
			but3->LogicState_ = LogicState::WAS_SHORT_PRESSED;
		}
		else if(but3->LogicState_ == LogicState::WAS_RELEASED)
		{
			delay = TETRIS_HIGH_DELAY;
			but3->LogicState_ = LogicState::NONE;
		}

	}
	else if(but1->LogicState_ == LogicState::WAS_PRESSED){
		figure.MoveHorizontally(Directions::LEFT);
		but1->LogicState_ = LogicState::NONE;
		return true;
	}
	else if(but4->LogicState_ == LogicState::WAS_PRESSED){
		figure.MoveHorizontally(Directions::RIGHT);
		but4->LogicState_ = LogicState::NONE;
		return true;
	}
	else if(but2->LogicState_ == LogicState::WAS_PRESSED){
		figure.Rotate();
		but2->LogicState_ = LogicState::NONE;
		return true;
	}
	return false;
}

void PrintTetrisFigure(const TetrisFigure& figure)
{
	int side = figure.side;
	for(int row = 0; row < side; ++row)
		for (int col = 0; col < side; ++col)
			if (figure.figure[row * side + col].isFeeled && (figure.coord.Y + row) >= HIDDEN_ROW_OF_FIELD)
			{
				tft_fillRoundRect((figure.coord.X + col) * SIDE_SQUARE,
						(figure.coord.Y + row - HIDDEN_ROW_OF_FIELD) * SIDE_SQUARE,
						SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, figure.figure[row * side + col].color);
			}
}

void ErasePrevFigure(const TetrisFigure& figure)
{
	int side = figure.side;
	for (int row = 0; row < side; ++row)
		for (int col = 0; col < side; ++col)
			if (figure.prevFigure[row * side + col].isFeeled && (figure.prevCoord.Y + row) >= HIDDEN_ROW_OF_FIELD)
			{
				tft_fillRoundRect((figure.prevCoord.X + col) * SIDE_SQUARE,
						(figure.prevCoord.Y + row - HIDDEN_ROW_OF_FIELD) * SIDE_SQUARE,
						SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, BACKGROUND);
			}
}

void PrintTetrisField(block_t& myBlock)
{

	for (int row = HIDDEN_ROW_OF_FIELD; row < ROW_OF_FIELD; ++row)
		for (int col = 0; col < COL_OF_FIELD; ++col)
		{
			tft_fillRoundRect(col * SIDE_SQUARE, (row - HIDDEN_ROW_OF_FIELD) * SIDE_SQUARE,
					SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, myBlock[row * COL_OF_FIELD + col].color);
		}

}

void TetrisTask()
{
	tft_fillScreen(BACKGROUND);
	//tft_setRotation(PORTRAIT_ORIENTATION);
	//tft_fillScreen(FIG1COLOR);
	TetrisManager manager;

	uint32_t delay = TETRIS_HIGH_DELAY;
	uint32_t time = HAL_GetTick();

	while(!manager.END_OF_GAME)
	{
		if(!manager.currentFigure->MoveDown())
		{
			if(manager.EraseFilledRow())
			{
				PrintTetrisField(manager.field);
			}
			manager.GenerateNewFigure();
		}
		else
		{
			ErasePrevFigure(*manager.currentFigure);
		}
		PrintTetrisFigure(*manager.currentFigure);
		while(computeTimeDuration(time) < delay)
		{
			if(TetrisButtonHandler(*manager.currentFigure, delay))
			{
				ErasePrevFigure(*manager.currentFigure);
				PrintTetrisFigure(*manager.currentFigure);
			}
		}
		time = HAL_GetTick();
	}
	while(but1->LogicState_ != LogicState::WAS_HOLDED)computeTimeDuration(time);
}
