# UniverseLogistician top-level CMake file
cmake_minimum_required(VERSION 3.23)

# set project information
project(UniverseLogistician VERSION 0.0.1)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "./out/lib/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "./out/lib/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./out/bin/")


# define libraries
add_library(util)
target_include_directories(util PRIVATE "${PROJECT_SOURCE_DIR}")
add_library(game)
target_include_directories(game PRIVATE "${PROJECT_SOURCE_DIR}")
add_subdirectory(src)

# define server app
add_executable(UL_Server "apps/server.cpp")
target_link_libraries(UL_Server PRIVATE util game)

# define client app
add_executable(UL_Client "apps/client.cpp")
target_link_libraries(UL_Client PRIVATE util game)