#pragma once
#include <list>
#include <random>
#include <algorithm>

namespace snake
{

using color_t = uint16_t;
using coord_t = int32_t;

enum class directions { UP, DOWN, LEFT, RIGHT };

constexpr directions defDirections = directions::UP;
constexpr color_t defColor = 0;
constexpr color_t defNodeColor = 0;

struct Coordinate
{
	coord_t X = 0;
	coord_t Y = 0;
};
struct SnakeNode
{
	Coordinate Coord;
	color_t color;
	SnakeNode(Coordinate Coord_, color_t color_) : Coord{ Coord_ }, color(color_) {}
	SnakeNode() = default;
};

struct random_generator
{
	coord_t generate(coord_t max, coord_t min);
private:
	std::default_random_engine generator{};
};


class ClassicSnake
{
	Coordinate upLeftField;
	Coordinate lowRightField;

	////////////////////////////
	color_t colorHead, colorBody, colorFruit, colorBackGround;
	////////////////////////////
	random_generator fruitGenerator;

	Coordinate& CheckBoundaries(Coordinate& coord);

public:
	directions currentDir;
	///////////////
	Coordinate& Promote(Coordinate& coord);
	///////////////
	SnakeNode fruitCoordinate;
	std::list<SnakeNode> mySnake;

	ClassicSnake(Coordinate UpLeft_, Coordinate DownRight_, color_t ColorHead_, color_t ColorBody_,
			color_t ColorFruit_, color_t ColorBackGround_);

	ClassicSnake& Move();
	ClassicSnake& AddNodeToEnd();
	ClassicSnake& NewDirection(directions newDir);
	bool CheckSnakeCollision(const SnakeNode& myNode) const;
	SnakeNode& GenerateNewFruit();
	bool CheckFruit();
	size_t getSizeSnake();

};

}
