# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jhartway/repos/c-projects/particle-system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jhartway/repos/c-projects/particle-system

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jhartway/repos/c-projects/particle-system/CMakeFiles /home/jhartway/repos/c-projects/particle-system//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jhartway/repos/c-projects/particle-system/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named TermParticle

# Build rule for target.
TermParticle: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 TermParticle
.PHONY : TermParticle

# fast build rule for target.
TermParticle/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/build
.PHONY : TermParticle/fast

src/drawlib.o: src/drawlib.c.o
.PHONY : src/drawlib.o

# target to build an object file
src/drawlib.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/drawlib.c.o
.PHONY : src/drawlib.c.o

src/drawlib.i: src/drawlib.c.i
.PHONY : src/drawlib.i

# target to preprocess a source file
src/drawlib.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/drawlib.c.i
.PHONY : src/drawlib.c.i

src/drawlib.s: src/drawlib.c.s
.PHONY : src/drawlib.s

# target to generate assembly for a file
src/drawlib.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/drawlib.c.s
.PHONY : src/drawlib.c.s

src/ellipse.o: src/ellipse.c.o
.PHONY : src/ellipse.o

# target to build an object file
src/ellipse.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/ellipse.c.o
.PHONY : src/ellipse.c.o

src/ellipse.i: src/ellipse.c.i
.PHONY : src/ellipse.i

# target to preprocess a source file
src/ellipse.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/ellipse.c.i
.PHONY : src/ellipse.c.i

src/ellipse.s: src/ellipse.c.s
.PHONY : src/ellipse.s

# target to generate assembly for a file
src/ellipse.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/ellipse.c.s
.PHONY : src/ellipse.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/main.c.s
.PHONY : src/main.c.s

src/physicslib.o: src/physicslib.c.o
.PHONY : src/physicslib.o

# target to build an object file
src/physicslib.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/physicslib.c.o
.PHONY : src/physicslib.c.o

src/physicslib.i: src/physicslib.c.i
.PHONY : src/physicslib.i

# target to preprocess a source file
src/physicslib.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/physicslib.c.i
.PHONY : src/physicslib.c.i

src/physicslib.s: src/physicslib.c.s
.PHONY : src/physicslib.s

# target to generate assembly for a file
src/physicslib.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/physicslib.c.s
.PHONY : src/physicslib.c.s

src/primatives.o: src/primatives.c.o
.PHONY : src/primatives.o

# target to build an object file
src/primatives.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/primatives.c.o
.PHONY : src/primatives.c.o

src/primatives.i: src/primatives.c.i
.PHONY : src/primatives.i

# target to preprocess a source file
src/primatives.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/primatives.c.i
.PHONY : src/primatives.c.i

src/primatives.s: src/primatives.c.s
.PHONY : src/primatives.s

# target to generate assembly for a file
src/primatives.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/primatives.c.s
.PHONY : src/primatives.c.s

src/rectangle.o: src/rectangle.c.o
.PHONY : src/rectangle.o

# target to build an object file
src/rectangle.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/rectangle.c.o
.PHONY : src/rectangle.c.o

src/rectangle.i: src/rectangle.c.i
.PHONY : src/rectangle.i

# target to preprocess a source file
src/rectangle.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/rectangle.c.i
.PHONY : src/rectangle.c.i

src/rectangle.s: src/rectangle.c.s
.PHONY : src/rectangle.s

# target to generate assembly for a file
src/rectangle.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/rectangle.c.s
.PHONY : src/rectangle.c.s

src/screen.o: src/screen.c.o
.PHONY : src/screen.o

# target to build an object file
src/screen.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/screen.c.o
.PHONY : src/screen.c.o

src/screen.i: src/screen.c.i
.PHONY : src/screen.i

# target to preprocess a source file
src/screen.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/screen.c.i
.PHONY : src/screen.c.i

src/screen.s: src/screen.c.s
.PHONY : src/screen.s

# target to generate assembly for a file
src/screen.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TermParticle.dir/build.make CMakeFiles/TermParticle.dir/src/screen.c.s
.PHONY : src/screen.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... TermParticle"
	@echo "... src/drawlib.o"
	@echo "... src/drawlib.i"
	@echo "... src/drawlib.s"
	@echo "... src/ellipse.o"
	@echo "... src/ellipse.i"
	@echo "... src/ellipse.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/physicslib.o"
	@echo "... src/physicslib.i"
	@echo "... src/physicslib.s"
	@echo "... src/primatives.o"
	@echo "... src/primatives.i"
	@echo "... src/primatives.s"
	@echo "... src/rectangle.o"
	@echo "... src/rectangle.i"
	@echo "... src/rectangle.s"
	@echo "... src/screen.o"
	@echo "... src/screen.i"
	@echo "... src/screen.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

