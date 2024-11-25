cmake_minimum_required(VERSION 3.10)
project(TermParticle C)

# Specify C17 standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ./bin/)
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_BUILD_TYPE Debug)

# Find the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} ./include/)

# Add the executable target
file(GLOB SOURCES "./src/*.c")
add_executable(TermParticle ${SOURCES})  # Replace 'main.c' with your source files

# Link the ncurses library to the target
target_link_libraries(TermParticle ${CURSES_LIBRARIES} m)
