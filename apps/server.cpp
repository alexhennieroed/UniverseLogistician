/*
* UniverseLogistician Server Application File
* @version 0.0.1
*/

// Include local libraries
#include "src/game.hpp"

// Global variables
int g_run; // Is it running running?
mutex g_run_mutex;
int g_close; // Can the logger close?
mutex g_close_mutex;

/*
* Networking thread for managing incoming and outgoing messages
*/
void t_network() {
	int l_run = 1; // Local version of global
	log_info("Starting networking...");
	// While the application is going, loop
	while (l_run) {
		this_thread::sleep_for(chrono::seconds(5));
		// At the end of the loop, set local running to global
		g_run_mutex.lock();
		l_run = g_run;
		g_run_mutex.unlock();
	}
	// Cleanup complete, close the thread
	log_info("Networking closed.");
	return;
}

/*
* Game loop thread
*/
void t_game() {
	int l_run = 1; // Local version of global
	log_info("Starting game...");
	// While the application is going, loop
	while (l_run) {
		this_thread::sleep_for(chrono::seconds(5));
		// At the end of the loop, set local running to global
		g_run_mutex.lock();
		l_run = g_run;
		g_run_mutex.unlock();
	}
	// Cleanup complete, close the thread
	log_info("Game closed.");
	return;
}

/*
* Logging thread
*/
void t_logger() {
	int l_run = 1; // Local version of global
	// Open the log file for writing
	ofstream logfile;
	logfile.open("runlog.log");
	// Loop while the game is running
	while (l_run) {
		// Each loop, clear out the logging queue
		while (!log_q.empty()) {
			log_q_mutex.lock();
			logfile << log_q.front() << endl;
			log_q.pop();
			log_q_mutex.unlock();
		}
		// At the end of the loop, set local running to global
		g_run_mutex.lock();
		l_run = g_run;
		g_run_mutex.unlock();
	}
	// Wait to clear loggin queue before closing thread
	int l_close = 0; // Local version of global
	while (!l_close) { // Wait until all other threads complete
		if (!log_q.empty()) { // Only pop from queue if it has data
			log_q_mutex.lock();
			logfile << log_q.front() << endl;
			log_q.pop();
			log_q_mutex.unlock();
		}
		// Set local to global
		g_close_mutex.lock();
		l_close = g_close;
		g_close_mutex.unlock();
	}
	// Cleanup complete, close the thread
	logfile.close();
	return;
}

/*
* Interface thread that manages user interaction with the program
*/
void t_interface() {
	int l_run = 1; // Local version of global

	print_info("Type help to see all commands. Type exit to quit.");
	string input;

	// While the application is going, loop
	while (l_run) {
		// Get the user input and check what they want to accomplish
		getline(cin, input);
		if (!strcomp_caseinsen(input, "exit")) { // Stop the server gracefully
			log_info("Closing server...");
			g_run_mutex.lock();
			g_run = 0;
			g_run_mutex.unlock();
		}
		else if (!strcomp_caseinsen(input, "help")) { // List all of the possible commandsS
			cout << "\rUniverse Logistician Server Commands\n"
				<< "help\t\t Display this list\n"
				<< "kick [user]\t Kick user from the server\n"
				<< "ban [user]\t Kick the user and add them to the blacklist\n"
				<< "exit\t\t Close the server\n> ";
		}
		else if (!strcomp_caseinsen(input.substr(0,5), "kick ")) {
			print_info("Kicking user " + input.substr(5));
			//TODO
		}
		else if (!strcomp_caseinsen(input.substr(0,4), "ban ")) {
			print_info("Banning user " + input.substr(4));
			//TODO
		}
		else { // If not in the list of commands, do nothing and tell the user
			print_info("Command not recognized. Type help to see valid commmands.");
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
	log_info("Starting Universe Logistician Server...");
	// Initialize threads
	g_run = 1;
	g_close = 0;
	thread logger(t_logger);
	thread iface(t_interface);
	thread network(t_network);
	thread game(t_game);

	// While still running, loop
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
	log_info("Server cleanup complete!");
	g_close_mutex.lock();
	g_close = 1;
	g_close_mutex.unlock();
	logger.join();

	// Close the program
	cout << "\b\b";
	return 0;
}