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
uint32_t tmp = 1;
void MainThread()
{
	MainInit();
	while(true)
	{
		SnakeTask();
	}
}

void SysTickThread()
{
	but::ButtonControlBlock::ButtonHandler();
}

