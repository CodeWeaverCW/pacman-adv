/*
	Directions.h
Author: Logan "CodeWeaver" Hall
2019-08-12

This header is the authority on how the four directions are to be represented.
Entities have one field which represents the direction(s) they're facing.
Each tile of a Maze has a byte which specifies the directions valid for ghosts,
and for Pac-Man.

A directional node has four bits, one for each cardinal direction. From the
most-significant bit to the least, the directions are {up, left, down, right}.
	1000	up
	0100	left
	0010	down
	0001	right
For Maze tiles, a '1' bit is a valid direction to travel down (and a '0' leads
to a wall). For Entities, the '1' bit denotes where they are facing; they can
have two '1' bits in the case of diagonal movement.
*/


// Cardinals
#define DIRECTION_UP	8
#define DIRECTION_LEFT	4
#define DIRECTION_DOWN	2
#define DIRECTION_RIGHT	1
// Diagonals
#define DIRECTION_NW	12
#define DIRECTION_NE	9
#define DIRECTION_SW	6
#define DIRECTION_SE	3

typedef uint8_t Directions;
