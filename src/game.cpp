/*
* UniverseLogistician Game Logic File
* @version 0.0.1
*/

// Includes
#include "src/game.hpp"

using namespace std;

/*
* Initialize the game data
*/
string initialize() {
	//TODO: Initialize
	return "Game initialization complete!";
}

/*
* Save the game data
*/
string save() {
	//TODO: Save
	return "Game save complete!";
}

/*
* Load the game data
*/
string load() {
	//TODO: Load
	return "Game load complete!";
}

/*
* Cleanup the game data 
*/
string cleanup() {
	//TODO: Run cleanup process
	return "Game loop cleanup complete!";
}

/*
* Game loop function
* @return 0 when closed
*/
string game_loop(queue<string>* game_q, mutex* game_q_mutex) {
	// Is the game required to exit?
	int do_exit = 0;
	string out_msg;

	// Parse the queue
	while (!game_q->empty() && !do_exit) {
		game_q_mutex->lock();
		string message = game_q->front();
		game_q->pop();
		game_q_mutex->unlock();
		// Process the message
		if (message == START_MESSAGE) {
			out_msg = initialize();
		} else if (message == SAVE_MESSAGE) {
			out_msg = save();
		} else if (message == LOAD_MESSAGE) {
			out_msg = load();
		} else if (message == EXIT_MESSAGE) {
			do_exit = 1;
			out_msg = cleanup();
		} else {
			// Handle unexpected input !! TODO: Actually handle the issue
			out_msg = "Unexpected input!";
		}
	}

	return out_msg;
}