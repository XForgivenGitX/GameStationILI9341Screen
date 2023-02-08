#include <Inc/SnakeLogic.hpp>
using namespace snake;

coord_t random_generator::generate(coord_t max, coord_t min)
{
	std::uniform_int_distribution<coord_t> distance{ max , min };
	return distance(generator);
}

Coordinate& ClassicSnake::Promote(Coordinate& coord)
{
	switch (currentDir)
	{
	case directions::UP:	coord.Y -= 1; break;
	case directions::DOWN:	coord.Y += 1; break;
	case directions::LEFT:	coord.X -= 1; break;
	case directions::RIGHT:	coord.X += 1; break;
	}
	return coord;
}
Coordinate& ClassicSnake::CheckBoundaries(Coordinate& coord)
{
	if (coord.X == (upLeftField.X - 1)) coord.X = lowRightField.X;		//left
	else if (coord.X == (lowRightField.X + 1)) coord.X = upLeftField.X;	//right
	else if (coord.Y == (upLeftField.Y - 1)) coord.Y = lowRightField.Y;	//up
	else if (coord.Y == (lowRightField.Y + 1)) coord.Y = upLeftField.Y;	//down
	return coord;
}

ClassicSnake::ClassicSnake(Coordinate UpLeft_, Coordinate DownRight_, color_t ColorHead_, color_t ColorBody_,
		color_t ColorFruit_, color_t ColorBackGround_)
: upLeftField(UpLeft_), lowRightField(DownRight_), colorHead(ColorHead_), colorBody(ColorBody_),
  colorFruit(ColorFruit_), colorBackGround(ColorBackGround_), currentDir(defDirections)
{
	Coordinate tmpCoord = { ((DownRight_.X - UpLeft_.X) / 2) + UpLeft_.X,((DownRight_.Y - UpLeft_.Y) / 2) + UpLeft_.Y };//center field
	//////////////////////////////////////
	mySnake.push_front({ tmpCoord, ColorHead_ });
	Promote(tmpCoord);
	mySnake.push_front({ tmpCoord,  ColorBody_ });
	Promote(tmpCoord);
	mySnake.push_front({ tmpCoord, ColorBackGround_ });
	//////////////////////////////////////
	this->GenerateNewFruit().color = ColorFruit_;
}

ClassicSnake& ClassicSnake::Move()
{
	auto tail = (*++mySnake.begin()).Coord;
	mySnake.erase(++mySnake.begin());
	mySnake.front().Coord = tail;
	//////////////////////////////////
	tail = mySnake.back().Coord;
	Promote(mySnake.back().Coord);
	mySnake.emplace(--mySnake.end(), tail, colorBody);
	//////////////////////////////////
	CheckBoundaries(mySnake.back().Coord);
	return *this;
}

ClassicSnake& ClassicSnake::AddNodeToEnd()
{
	mySnake.emplace(++mySnake.begin(), Coordinate{ -1, -1 }, colorBody);
	return *this;
}

ClassicSnake& ClassicSnake::NewDirection(directions newDir)
{
	currentDir = newDir;
	return *this;
}

bool ClassicSnake::CheckSnakeCollision(const SnakeNode& myNode) const
{
	return std::count_if(++mySnake.begin(), --mySnake.end(), [&myNode](auto& rhs)
			{return (rhs.Coord.X == myNode.Coord.X) && (rhs.Coord.Y == myNode.Coord.Y); });
}

SnakeNode& ClassicSnake::GenerateNewFruit()
{
	fruitCoordinate.Coord.X = fruitGenerator.generate(upLeftField.X, lowRightField.X);
	fruitCoordinate.Coord.Y = fruitGenerator.generate(upLeftField.Y, lowRightField.Y);
	return this->fruitCoordinate;
}
bool ClassicSnake::CheckFruit()
{
	const SnakeNode& head = *mySnake.rbegin();
	if ((head.Coord.X == fruitCoordinate.Coord.X) && (head.Coord.Y == fruitCoordinate.Coord.Y))
		return true;
	else return false;
}
size_t ClassicSnake::getSizeSnake()
{
	return mySnake.size() - 1;
}
