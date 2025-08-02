/*
* UniverseLogistician Utility Functions File
* @version 0.0.1
*/

#include <algorithm>
#include <ctime>
#include "src/util.hpp"

// Global variables
queue<string> game_q = queue<string>();
mutex game_q_mutex;
queue<string> log_q = queue<string>();
mutex log_q_mutex;

// Miscellaneous utility functions 

/*
* Compares two strings ignoring the case
* Converts the strings to lowercase and uses string::compare()
* @param str_a The first string to compare
* @param str_b The second string to compare
* @return 0 if the strings are equivalent, -1 or 1 otherwise
*/
int strcomp_caseinsen(string str_a, string str_b) {
	transform(str_a.begin(), str_a.end(), str_a.begin(),
		[](unsigned char c) { return tolower(c); });
	transform(str_b.begin(), str_b.end(), str_b.begin(),
		[](unsigned char c) { return tolower(c); });
	return str_a.compare(str_b);
}

/*
* Logs input info to the console and to the
*/
void log_info(string info) {
	// Get the current time and format it for logging purposes
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%F %T", timeinfo);

	// Add to log queue and print to console
	string data = "[" + string(buffer) + "] " + info;
	log_q_mutex.lock();
	log_q.push(data);
	log_q_mutex.unlock();
	print_info(data);
	return;
}

void print_info(string info) {
	cout << "\r" << info << "\n> ";
}

// Networking Abstraction Functions

/*
* Establish a connection with another host
*/
int open_conn(string address) {
	//TODO: Start with TCP, move to UDP
	return 0;
}

/*
* Close a connection with another host
*/
int clse_conn(string address) {
	//TODO
	return 0;
}

/*
* Send UDP data to another host
*/
int send_data(string data) {
	//TODO
	return 0;
}

/*
* Receive UDP data from another host
*/
int recv_data(char* buffer) {
	//TODO
	return 0;
}