/*
* UniverseLogistician Client Application File
* @version 0.0.1
*/

// Include local libraries
#include "src/util.hpp"
#include "src/game.hpp"

// Global variables
int g_run;
mutex g_run_mutex;

/*
* Networking thread for managing incoming and outgoing messages
*/
void t_network() {
	int l_run = 1; // Local version of global
	// While the application is going, loop
	while (l_run) {
		this_thread::sleep_for(chrono::seconds(5));
		// At the end of the loop, set local running to global
		g_run_mutex.lock();
		l_run = g_run;
		g_run_mutex.unlock();
	}
	// Cleanup complete, close the thread
	return;
}

/*
* Game loop thread
*/
void t_game() {
	int l_run = 1; // Local version of global
	// While the application is going, loop
	while (l_run) {
		this_thread::sleep_for(chrono::seconds(5));
		// At the end of the loop, set local running to global
		g_run_mutex.lock();
		l_run = g_run;
		g_run_mutex.unlock();
	}
	// Cleanup complete, close the thread
	return;
}

/*
* Logging thread
*/
void t_logger() {
	int l_run = 1; // Local version of global
	while (l_run) {
		this_thread::sleep_for(chrono::seconds(5));
		// At the end of the loop, set local running to global
		g_run_mutex.lock();
		l_run = g_run;
		g_run_mutex.unlock();
	}
	// Cleanup complete, close the thread
	return;
}

/*
* Interface thread that manages user interaction with the program
*/
void t_interface() {
	int l_run = 1; // Local version of global

	cout << "Type [x] to exit.\n> ";
	string input;

	// While the application is going, loop
	while (l_run) {
		getline(cin, input);
		if (!input.compare("x") | !input.compare("X")) {
			cout << "Closing program..." << endl;
			g_run_mutex.lock();
			g_run = 0;
			g_run_mutex.unlock();
		}
		// At the end of the loop, set local running to global
		g_run_mutex.lock();
		l_run = g_run;
		g_run_mutex.unlock();
	}
	// Cleanup complete, close the thread
	return;
}

/*
* Program entry point
* @return 0 when complete
*/
int main() {
	cout << "Starting Universe Logistician..." << endl;
	// Initialize threads
	g_run = 1;
	thread logger(t_logger);
	thread iface(t_interface);
	thread network(t_network);
	thread game(t_game);
	
	// While still running, loop
	cout << "Client initialization complete!" << endl;
	int l_run = 1;
	while (l_run) {
		this_thread::sleep_for(chrono::seconds(5));
		// At the end of the loop, set local running to global
		g_run_mutex.lock();
		l_run = g_run;
		g_run_mutex.unlock();
	}
	
	// Cleanup and prepare to closeout
	iface.join();
	network.join();
	game.join();
	logger.join();
	cout << "Client cleanup complete!" << endl;
	
	// Close the program
	return 0;
}