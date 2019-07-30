/*
	SysDep.h
Author: Logan "CodeWeaver" Hall
2019-07-23

This is the namespace for "system dependent" code. Ideally, the program can
rely on these functions to interface with the target platform. At best,
to "port" the program to any device, you only need to implement these functions
with platform-specific code; on the flipside, it should be assured that a
"clean" port is impossible on systems that cannot fully implement them.
Building for a target device is as simple as including the respective `.cpp`
which implements these functions for the device.

SysDep provisions for audio, graphics, input, and various system utilities.

This is not meant to discourage developers from using macros to supply
system-specific code. This namespace is meant to centralize the code that "must"
be ported, while platform-specific macros are discretionary (for e.g. platform-
exclusive features).
*/


namespace SysDep {
	/* Utilities */
	// `int main()` is considered "system-dependent", so don't forget to supply that too!
	static const float ticksPerFrame;	// 60 ticks/second
}
