/*
	Coord.h
Author: Logan "CodeWeaver" Hall
2019-07-28

This type represents the coordinate system, used to position objects within a
level. Coordinates are precise to a sixteenth of a pixel, because this is the
granularity required to represent the possible speed of Pac-Man and the ghosts.

There are effectively three kinds of coordinates that can be extracted from a
`Coord`, by truncating more bits:
	1) A raw `Coord` has sixteenth-pixel precision. This is good for
	tracking exact movement.
	2) By truncating 4 bits, you have the exact pixel. This is important
	to graphics routines.
	3) By truncating 3 more bits, you have the tile coordinate. This is
	instrumental to most game logic. Each tile is 8x8 pixels. Tile
	coordinates are constrained to be one byte wide, which means the
	topmost bit will also be truncated, leaving 8 bits.

This type exists to abstract the exact precision away and allow different
routines to examine their respective coordinate systems.
*/


typedef uint16_t Coord;
typedef uint16_t Pixel_Coord;
typedef uint8_t Tile_Coord;

namespace Coords {
	inline Pixel_Coord pixel(Coord c) { return c>>4; }
	inline Tile_Coord tile(Coord c) { return c>>7; }
}
