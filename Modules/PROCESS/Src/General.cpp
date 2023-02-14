#include <Inc/General.hpp>


uint32_t computeTimeDuration(uint32_t time)
{
	return HAL_GetTick() - time;
}

std::default_random_engine random_generator::generator;

int32_t random_generator::generate(int32_t max, int32_t min)
{
	std::uniform_int_distribution<int32_t> distance{ max , min };
	return distance(generator);
}
