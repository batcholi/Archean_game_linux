// DO NOT EDIT THIS FILE
/* 
	MODDING GUIDE (C/C++)

	1. Get yourself an official VENDOR name on the official website
	
	2. Come up with a name for your mod that is all lowercase with a maximum of 12 alphanumeric characters, starting with a letter
	
	For the following, replace words in square brackets [] with your information without the brackets

	4. Create a directory [path_to_game]/modules/[MYVENDOR]_[mymod]/

	5. Create a file [mymod].c in that directory that will contain the source code for your mod
	
		Example source code in [mymod].c:
			
			
			#include "../ARCHEAN_Build.h" // add this line once at the very beginning of your source code
			
			ARCHEAN_FUNCTION( Load ) {
				//...
			}


	6. Compile your mod with the following command: gcc -shared -o [MYVENDOR]_[mymod].ARCHEAN_Build.[dll|so] [mymod].c
	
	7. Add [MYVENDOR]_[mymod] to the list of enabled mods in Archean-data/mods.txt
	
	8. Enjoy your mod!
	
	NOTE:
		You may otherwise use a more complex project tree with your favorite libraries and compile C or C++ with your favorite dev tools,
		as long as you use the macros from the example above and that you get a .dll or .so file with this output filepath in the end:
		[path_to_game]/modules/[MYVENDOR]_[mymod]/[MYVENDOR]_[mymod].ARCHEAN_Build.[dll|so]
*/

#ifndef _ARCHEAN_BUILD_H
#define _ARCHEAN_BUILD_H

#define ARCHEAN_BUILD_VERSION 0

#ifdef XENON_GAME // Only defined within the game's source code. Do NOT define XENON_GAME in your mod.
	#include "ARCHEAN_Build.hh"
#else
	#define ARCHEAN_BUILD_DEFINE(...) 
	#ifdef __cplusplus
		extern "C" int _ARCHEAN_BUILD_VERSION() {return ARCHEAN_BUILD_VERSION;}
		#define ARCHEAN_FUNCTION(F) extern "C" void F (struct F ## _PARAMS * Params_)
	#else
		int _ARCHEAN_BUILD_VERSION() {return ARCHEAN_BUILD_VERSION;}
		#define ARCHEAN_FUNCTION(F) void F (struct F ## _PARAMS * Params_)
	#endif
	#define PARAM (*Params_)
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////


struct Load_PARAMS {
};


ARCHEAN_BUILD_DEFINE( Load )


#endif
