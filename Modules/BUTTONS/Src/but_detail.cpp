#include <BUTTONS/Inc/but_main.hpp>
using namespace but;

void ButtonWrapper::NevermindHandle(bool PinState)
{
	if(PinState)
	{
		SetTime_ 		= HAL_GetTick();
		ButtonState_  	= ButtonState::PRESS_BOUNCE;
	}
	if(DurationTime() >= DELAY_BETWEEN_DOUBLE_CLICK)
	{
		CurrentСlick_ 		= ShortClickCount_ + (HoldClickCount_ * 10);
		ShortClickCount_ 	= 0;
		HoldClickCount_  	= 0;
	}
	LogicState_  		= LogicState::NONE;
}

void ButtonWrapper::PressBounceHandle(bool PinState)
{
	PinState ? PinStateCount_++ : PinStateCount_ = 0;
	if(PinStateCount_ == TIME_AFTER_BOUNCE)
	{
		TimeBounce_ 		= DurationTime();
		SetTime_ 			= HAL_GetTick();
		ButtonState_ 		= ButtonState::SLICE_WAIT;
		LogicState_ 		= LogicState::WAS_PRESSED;
		PinStateCount_   	= 0;
	}
	else if(TimeBounce_ == DurationTime())
		ButtonState_ 	= ButtonState::NEVERMIND;
}

void ButtonWrapper::SliceWaitHandle(bool PinState)
{
	if(!PinState)
	{
		if(SHORT_CLICK < DurationTime())
		{
			if(HOLD_CLICK < DurationTime())
			{
				LogicState_	= LogicState::WAS_HOLDED;
				HoldClickCount_++;
			}
			else
			{
				LogicState_ 	= LogicState::WAS_SHORT_PRESSED;
				ShortClickCount_++;
			}
			SetTime_ 			= HAL_GetTick();
			ButtonState_ 		= ButtonState::RELEASE_BOUNCE;
		}
		else ButtonState_ 		= ButtonState::NEVERMIND;
	}
}

void ButtonWrapper::ReleaseBounceHandle(bool PinState)
{
	if(TimeBounce_ == DurationTime())
	{
		SetTime_ 		= HAL_GetTick();
		LogicState_		= LogicState::WAS_RELEASED;
		ButtonState_ 	= ButtonState::NEVERMIND;
	}
}

uint32_t ButtonWrapper::DurationTime() const
{
	return HAL_GetTick() - SetTime_;
}

bool ButtonWrapper::ReadPin() const
{
	return HAL_GPIO_ReadPin(Port_, Pin_) ^ ReleaseState_;
}
