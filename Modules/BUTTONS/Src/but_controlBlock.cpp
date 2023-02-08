#include <BUTTONS/Inc/but_main.hpp>
using namespace but;

std::list<ButtonWrapper*> ButtonControlBlock::myButtons;

ButtonWrapper* ButtonControlBlock::CreateButton(GPIO_TypeDef* Port, uint16_t Pin, GPIO_PinState Default)
	{
		ButtonWrapper* newButton = new ButtonWrapper(Port, Pin, Default);
		myButtons.push_back(newButton);
		return newButton;
	}

////////////////////////////////////////////////////////
void ButtonControlBlock::ButtonHandler()
	{
		for(auto it : myButtons)
		{
			bool PinState = it->ReadPin();
			switch(it->ButtonState_)
			{
			case ButtonState::NEVERMIND:
				it->NevermindHandle(PinState);
				break;

			case ButtonState::PRESS_BOUNCE:
				it->PressBounceHandle(PinState);
				break;

			case ButtonState::SLICE_WAIT:
				it->SliceWaitHandle(PinState);
				break;

			case ButtonState::RELEASE_BOUNCE:
				it->ReleaseBounceHandle(PinState);
				break;
			}
		}
	}
