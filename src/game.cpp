/*
* UniverseLogistician Game Logic File
* @version 0.0.1
*/

// Includes
#include "src/game.hpp"

// Enums
enum PlanetImprovementType {
	REFINERY, FACTORY, WAREHOUSE, MINE, WELL,
};

enum PlanetFeatureType {
	BUILDING_SITE, MINERAL_DEPOSIT, LIQUID_DEPOSIT,
};

// Classes
class PlanetImprovement {

};

class PlanetFeature {

};

class CelBody {

};

class Planet : public CelBody {

};

class Moon: public CelBody {

};

class CelSystem {
public:
    // Constructor
    CelSystem() {
        //TODO: Constructor
    }
    // Destructor
    ~CelSystem() {
        //TODO: Destructor
    }
private:
    int size;
    vector<CelBody> system_bodies;
};

class Universe {
public:
    // Constructor
    Universe() {
        //TODO: Constructor
        seed = rand();
    }
    // Destructor
    ~Universe() {
        //TODO: Destructor
    }
private:
    int seed;  // Universe generation seed
    int size;
    vector<CelSystem> universe_systems;
};

/*
* Initialize the game data
*/
int initialize_game() {
	//TODO: Initialize
	log_info("Game initialization complete!");
	return 0;
}

/*
* Save the game data
*/
int save_game() {
	//TODO: Save
	log_info("Game save complete!");
	return 0;
}

/*
* Load the game data
*/
int load_game() {
	//TODO: Load
	log_info("Game load complete!");
	return 0;
}

/*
* Cleanup the game data 
*/
int cleanup_game() {
	//TODO: Run cleanup process
	log_info("Game loop cleanup complete!");
	return 0;
}

/*
* Process the specified input
*/
void process_input() {
	//TODO: Process the input
	return;
}

/*
* Game loop function
* @return 0 on successful close
*/
int game_loop() {
	// The loop will be to check input, check conflicts, make changes
	process_input();
	return 0;
}