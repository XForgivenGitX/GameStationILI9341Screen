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
			delay = TetrisLowDelay;
			but4->LogicState_ = LogicState::WAS_SHORT_PRESSED;
		}
		else if(but4->LogicState_ == LogicState::WAS_RELEASED)
		{
			delay = TetrisHighDelay;
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

void printTetrisSquare()
{

}

void TetrisTask()
{
	tft_fillScreen(BACKGROUND);
	tft_setRotation(PORTRAIT_ORIENTATION);

	TetrisManager manager;
	uint32_t delay = TetrisHighDelay;
	uint32_t time = HAL_GetTick();
	uint32_t numFigure = manager.generator.generate(0, QUANTITY_FIGURE - 1);

	while(manager.END_OF_GAME)
	{
		if(!manager.myFigure[numFigure].MoveDown())
		{
			numFigure = manager.generator.generate(0, QUANTITY_FIGURE - 1);
		}
		while(computeTimeDuration(time) < delay)
		{
			TetrisButtonHandler(manager.myFigure[numFigure], delay);
		}
		time = HAL_GetTick();
	}
}
