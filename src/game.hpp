/*
* UniverseLogistician Game Logic Header File
* @version 0.0.1
*/

#include "src/util.hpp"

// Definitions
#define START_MESSAGE "STRT"
#define SAVE_MESSAGE "SAVE"
#define LOAD_MESSAGE "LOAD"
#define EXIT_MESSAGE "EXIT"

// Prototypes
int initialize_game();
int save_game();
int load_game();
int cleanup_game();
int game_loop();