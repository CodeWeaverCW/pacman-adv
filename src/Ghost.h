/*
	Ghost.h
Author: Logan "CodeWeaver" Hall
2019-08-12

This is the top-level class for Ghosts. Each different ghost gets its own
derivative class (e.g. Blinky, Pinky, Inky, & Clyde). Although these will be
singleton objects in most cases (i.e. there's only one Blinky, one Inky, etc),
a class hierarchy is appropriate so that:
	1) ghosts' states can be constructed and destructed per-maze
	2) ghosts have a common interface defined by `Ghosts.h`
*/

#include "Coord.h"
#include "Directions.h"
#include "Entity.h"

#define MAX_WAVES 7


enum TargetMode {
	SCATTER = 0;
	CHASE = 1;
};

class Ghost : public Entity {
public:
	/* Constructors / Destructor */
	Ghost();	// Called when Maze is initialized
	~Ghost() = {}


	/* Methods */
	virtual void init();	// Called at the beginning of each round & life
	// This function is allowed to set the dot counters, ghost speeds, and wavetable for each round
	friend void Mode::init_ghosts();


	/* Data */
protected:
	/* Ghost house counters */
	uint8_t napping;	// Dot counter until this ghost may leave ghost house (decrements with each dot eaten)
	static uint16_t inactivity_timer;	// Tick counter -- length of time without eating any dots
	static const uint16_t inactivity_limit = 240;	// Period of inactivity until another ghost is allowed to exit

	// Preferred-order linked-list for ghost house exiting
	Ghost* subordinate;	// Next ghost allowed to leave ghost house, if this ghost is already out


	/* Tile targeting */
	// Scatter mode tile target; needs to be set by derived constructor
	const Position scatter_target;
	// Pointer to target Position in Chase mode; computed internally each tick if `nullptr`
	// Usually set by constructor to Pac-Man's position
	Position* chase_target = nullptr;
	// Location of ghost house door
	Position eaten_target;

	/* Target mode data
	Scatter and Chase modes switch off in waves
	(Fright and Eaten states are handled separately)
	*/
	TargetMode targetMode;

	static uint16_t wavetable[MAX_WAVES];	// Set of durations for scatter & chase waves, set by `Mode`
	int8_t wave = 0;	// Which "wave" are we on?
	uint16_t wave_timer;	// Ticks remaining until increment wave


	/* Special states */
	uint16_t fright = 0;	// Number of ticks of fright remaining (not frightened when 0)
	bool eaten = false;	// Going back to ghost house?
}
