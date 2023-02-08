#include <Inc/SnakeTask.hpp>
using namespace snake;

extern but::ButtonWrapper* but1;
extern but::ButtonWrapper* but2;
extern but::ButtonWrapper* but3;
extern but::ButtonWrapper* but4;

void SnakeButtonHandler(ClassicSnake& cd)
{
	if((but1->LogicState_ == LogicState::WAS_PRESSED) && (cd.currentDir != directions::RIGHT)){
		cd.NewDirection(directions::LEFT);
		but1->LogicState_ = LogicState::NONE;
	}
	else if((but2->LogicState_ == LogicState::WAS_PRESSED) && (cd.currentDir != directions::DOWN)){
		cd.NewDirection(directions::UP);
		but2->LogicState_ = LogicState::NONE;
	}
	else if((but3->LogicState_ == LogicState::WAS_PRESSED) && (cd.currentDir != directions::UP)){
		cd.NewDirection(directions::DOWN);
		but3->LogicState_ = LogicState::NONE;
	}
	else if((but4->LogicState_ == LogicState::WAS_PRESSED) && (cd.currentDir != directions::LEFT)){
		cd.NewDirection(directions::RIGHT);
		but4->LogicState_ = LogicState::NONE;
	}
}

void printSquare(SnakeNode& sn)
{
	tft_fillRoundRect(sn.Coord.X * SIZE_SIDE_SQUARE, sn.Coord.Y *
			SIZE_SIDE_SQUARE, SIZE_SIDE_SQUARE, SIZE_SIDE_SQUARE, RADIUS_ROUNDING, sn.color);
}

uint32_t computeTimeDuration(uint32_t time)
{
	return HAL_GetTick() - time;
}

void SnakeTask()
{
	ClassicSnake SnakeObj(Coordinate{0, 0}, Coordinate{20, 15},
			ILI9341_BLACK, ILI9341_GREEN, ILI9341_DARKRED, ILI9341_BLUE);
	uint32_t time = HAL_GetTick();
	directions tmpDir;
	uint32_t currentDelay = INIT_SPEED_GAME;

	//SnakeInterface();
	tft_fillScreen(ILI9341_BLUE);

	printSquare(SnakeObj.fruitCoordinate);

	while(!SnakeObj.CheckSnakeCollision(*SnakeObj.mySnake.rbegin()))
	{
		SnakeObj.Move();
		if(SnakeObj.CheckFruit())
		{
			SnakeObj.GenerateNewFruit();
			SnakeObj.AddNodeToEnd();
			while(SnakeObj.CheckSnakeCollision(SnakeObj.fruitCoordinate))
				SnakeObj.GenerateNewFruit();
			printSquare(SnakeObj.fruitCoordinate);
			if(!((SnakeObj.mySnake.size() - 1) % 3) && (currentDelay != FINAL_SPEED_GAME))
				currentDelay -= 25;
		}
		std::for_each(SnakeObj.mySnake.begin(), SnakeObj.mySnake.end(), printSquare);
		tmpDir = SnakeObj.currentDir;
		while(computeTimeDuration(time) < currentDelay)
		{
			if(tmpDir == SnakeObj.currentDir)
				SnakeButtonHandler(SnakeObj);
		}
		time = HAL_GetTick();
	}
	while(but1->LogicState_ != LogicState::WAS_HOLDED)computeTimeDuration(time);
}

void SnakeInterface()
{
	tft_fillScreen(ILI9341_BLUE);
	tft_drawRect(9, 9, 222, 222, ILI9341_CYAN);
	tft_drawRect(240, 10, 70, 220, ILI9341_CYAN);
	tft_fillRoundRect(11, 11, 218, 218, 0, ILI9341_PINK);
	tft_fillRoundRect(241, 11, 68, 218, 0, ILI9341_PINK);
}
