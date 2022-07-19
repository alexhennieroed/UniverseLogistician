# UL/src CMake file

# define util library
target_sources(util
	PRIVATE util.cpp
	PUBLIC FILE_SET HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}
	FILES util.hpp)

#define game library
target_sources(game
	PRIVATE game.cpp
	PUBLIC FILE_SET HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}
	FILES game.hpp)