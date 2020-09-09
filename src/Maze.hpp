/*
	Maze.hpp
Author: Logan "CodeWeaver" Hall
2019-07-29


*/

#pragma once
#include "Coord.hpp"
#include "Directions.hpp"
#include "Entity.hpp"


class Maze {
public:
	/* Constructors / Destructor */
	Maze(const char* filename);
	~Maze() {}

	/* Methods */
	void tick();	// Process game state for this tick


private:
	/* Data */
	Tile tiles[];
	Entity* entities[];
};
