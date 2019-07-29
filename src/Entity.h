/*
	Entity.h
Author: Logan "CodeWeaver" Hall
2019-07-23

This is the top-level class for objects that may exist in the maze. This includes
Pac-Man, the ghosts, fruit, and powerups. This does *not* include dots, which are
maze data.
*/

#include "Maze.h"


class Entity {
public:
	/* Constructors / Destructor */
	Entity();
	~Entity() = {};


	/* Methods */
	static uint8_t distance(Entity& one, Entity& two);
	static uint8_t distance(uint8_t x, uint8_t y, Entity& entity);
	static uint8_t distance(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);


	/* Properties */
	// Get tile coordinate
	inline uint8_t xTile(void);
	inline uint8_t yTile(void);
	inline uint8_t zTile(void);
	// Get pixel coordinate
	inline uint16_t xPixel(void);
	inline uint16_t yPixel(void);
	inline uint16_t zPixel(void);
	// Center this entity on the specified tile
	inline void setOnTile(uint8_t x, uint8_t y, uint8_t z);
	// Place this entity on an exact pixel location
	inline void setOnPixel(uint16_t x, uint16_t y, uint16_t z);

	// Speed
	inline void setSpeedFactor(float percent);

protected:
	// Direction
	using Maze::Direction;
	inline bool facing(Direction dir);


private:
	/* Data */
	/* Position
	Coordinates are precise to a sixteenth of a pixel. In other words,
	the coordinate system is in a 12.4 fixed-point notation.

	Use protected methods to extract appropriate data.
	*/
	uint16_t x;
	uint16_t y;
	uint16_t z;

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
