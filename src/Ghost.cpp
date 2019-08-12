/*
	Ghost.cpp
Author: Logan "CodeWeaver" Hall
2019-08-12

Any mutual code between all ghosts.
*/

#include "Ghost.h"


/*
Derived classes' constructors *must* define the three
target positions declared in `Ghost`.
*/
Ghost() {
	init();
}

/*
Derived classes *must* call the base init() and override.
Bare minimum tasks:
	1) Set ghost's spawn position.
	2) Set `napping` period (# of dots until free to leave ghost house)
	3) Set `subordinate` ghost for preferential ordering (e.g. Blinky should select Pinky as direct subordinate)
*/
virtual void Ghost::init() {
	targetMode = SCATTER;
	wave = 0;
	wave_timer = wavetable[wave];
	fright = 0;
	eaten = false;
}
