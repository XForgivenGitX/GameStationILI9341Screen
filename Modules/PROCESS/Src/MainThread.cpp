#include <Inc/MainThread.hpp>

but::ButtonWrapper *but1 = but::ButtonControlBlock::CreateButton(DB4_GPIO_Port, DB4_Pin, GPIO_PIN_SET);
but::ButtonWrapper *but2 = but::ButtonControlBlock::CreateButton(DB5_GPIO_Port, DB5_Pin, GPIO_PIN_SET);
but::ButtonWrapper *but3 = but::ButtonControlBlock::CreateButton(DB6_GPIO_Port, DB6_Pin, GPIO_PIN_SET);
but::ButtonWrapper *but4 = but::ButtonControlBlock::CreateButton(DB7_GPIO_Port, DB7_Pin, GPIO_PIN_SET);

void MainInit()
{
	tft_begin();
	tft_setRotation(true);
}

void MainThread()
{
	MainInit();
	while(true)
	{
		//SnakeTask();
		TetrisTask();
	}
}

void SysTickThread()
{
	but::ButtonControlBlock::ButtonHandler();
	//random_generator::generator.seed(HAL_GetTick());
}

