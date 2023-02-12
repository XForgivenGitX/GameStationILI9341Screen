#include <Inc/General.hpp>


uint32_t computeTimeDuration(uint32_t time)
{
	return HAL_GetTick() - time;
}
