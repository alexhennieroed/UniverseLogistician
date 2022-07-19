/*
* UniverseLogistician Utility Function Header File
* @version 0.0.1
*/

// Include OS specific global libraries
#ifdef _WIN32 || _WIN64 // If Windows, winsock
#include <winsock.h>
#else					// If Unix, unix socket
#include <sys/socket.h>
#include <sys/types.h>
#endif

// Include global libraries
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

// Definitions
#define SERVER_PORT 54321

// Define namespaces
using namespace std;

// Structures
struct Connection // Defines a connection to another host
{
	string uid;
	string address;
};

// Prototypes
int send_data(string data);
int recv_data(char* buffer);