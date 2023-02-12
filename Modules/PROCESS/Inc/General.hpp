#pragma once

#include "stm32f1xx_hal.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <list>
#include <Adafruit_GFX.hpp>

#define PORTRAIT_ORIENTATION 0
#define RECTANGLE_ORIENTATION 1
struct Coordinate
{
	int32_t X;
	int32_t Y;
	Coordinate(int32_t X_, int32_t Y_) : X(X_), Y(Y_) {}
};

struct random_generator
{
	int32_t generate(int32_t max, int32_t min)
	{
		std::uniform_int_distribution<int32_t> distance{ max , min };
		return distance(generator);
	}
private:
	std::default_random_engine generator{};
};

uint32_t computeTimeDuration(uint32_t time);
