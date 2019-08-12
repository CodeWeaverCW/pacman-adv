/*
	Maze.h
Author: Logan "CodeWeaver" Hall
2019-07-29


*/

#include "Coord.h"
#include "Directions.h"
#include "Entity.h"


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
