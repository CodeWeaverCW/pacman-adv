/*
	Entity.cpp
Author: Logan "CodeWeaver" Hall
2019-07-29
*/

#include "Entity.hpp"
#include "Coord.hpp"


static uint16_t Entity::distance(Tile_Coord x1, Tile_Coord y1, Tile_Coord x2, Tile_Coord y2) {
	uint16_t x = x1-x2;
	x *= x;
	uint16_t y = y1-y2;
	y *= y;
	return x+y;
}

void Entity::centerToTile(Tile_Coord x, Tile_Coord y, Tile_Coord z) {
	this.x = Coords::get(x, 3, 7);
	this.y = Coords::get(y, 4, 0);
	this.z = z;
}
