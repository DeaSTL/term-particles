cmake_minimum_required(VERSION 3.10)
project(TermParticle C)

# Specify C17 standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
SET(EXECUTABLE_OUTPUT_PATH ./bin/)

# Find the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add the executable target
add_executable(TermParticle ./src/main.c)  # Replace 'main.c' with your source files

# Link the ncurses library to the target
target_link_libraries(TermParticle ${CURSES_LIBRARIES} m)
