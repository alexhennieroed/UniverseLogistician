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
string game_loop(queue<string>* game_q, mutex* game_q_mutex);