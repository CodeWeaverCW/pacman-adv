/*
	Entity.h
Author: Logan "CodeWeaver" Hall
2019-07-23

This is the top-level class for objects that may exist in the maze. This includes
Pac-Man, the ghosts, fruit, and powerups. This does *not* include dots, which are
maze data.
*/

#include "Coord.h"
#include "Maze.h"


class Entity {
public:
	/* Constructors / Destructor */
	Entity();
	~Entity() = {};


	/* Methods */
	// `distance()` uses tile coordinates [0..255], not to be confused with `Coord` (sixteenth-pixel precision)
	inline static uint16_t distance(Entity& one, Entity& two) = { return distance(one.x, one.y, two.x, two.y); }
	inline static uint16_t distance(Tile_Coord x, Tile_Coord y, Entity& entity) = { return distance(x, y, entity.x, entity.y); }
	static uint16_t distance(Tile_Coord x1, Tile_Coord y1, Tile_Coord x2, Tile_Coord y2);


	/* Properties */
	// Center this entity on the specified tile
	void centerToTile(Tile_Coord x, Tile_Coord y, Tile_Coord z);
	// Speed
	inline void setSpeedFactor(float percent) = { speed = (uint8_t)(base_speed * percent); }

protected:
	// Direction
	using Maze::Direction;
	inline bool isFacing(Direction dir) = { return direction & dir; }


private:
	/* Data */
	/* Position */
	Coord x;
	Coord y;
	Coord z;

	/* Speed
	Speed is measured in sixteenth-pixels per tick.
	Movement needs to be calculated for several ticks in advance
	on systems that run less than 60 FPS.
	*/
	uint8_t speed;
	static const uint8_t base_speed = 20;	// 75 pixels/second, at 60 ticks/second

	/* Direction
	The direction facing is represented by four bitflags, in order of preference:
		up, left, down, right
	For example, a direction of 0b0100 means the entity is moving left.
	A direction of e.g. 0b1001 (up, right) is possible, such as when Pac-Man is cornering.

	Direction constants (bitmasks) are defined in the Maze class, as a tile's possible directions
	are listed in the same format.
	*/
	uint8_t direction;
}
