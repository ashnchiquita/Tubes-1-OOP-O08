# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alishalistya/VSCode/Tubes-1-OOP-O08

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alishalistya/VSCode/Tubes-1-OOP-O08

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.25.3/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.25.3/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/alishalistya/VSCode/Tubes-1-OOP-O08/CMakeFiles /Users/alishalistya/VSCode/Tubes-1-OOP-O08//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/alishalistya/VSCode/Tubes-1-OOP-O08/CMakeFiles 0
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
# Target rules for targets named Tubes-1-OOP-O08

# Build rule for target.
Tubes-1-OOP-O08: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Tubes-1-OOP-O08
.PHONY : Tubes-1-OOP-O08

# fast build rule for target.
Tubes-1-OOP-O08/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/build
.PHONY : Tubes-1-OOP-O08/fast

src/command/ability_command/ability_command.o: src/command/ability_command/ability_command.cpp.o
.PHONY : src/command/ability_command/ability_command.o

# target to build an object file
src/command/ability_command/ability_command.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/ability_command.cpp.o
.PHONY : src/command/ability_command/ability_command.cpp.o

src/command/ability_command/ability_command.i: src/command/ability_command/ability_command.cpp.i
.PHONY : src/command/ability_command/ability_command.i

# target to preprocess a source file
src/command/ability_command/ability_command.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/ability_command.cpp.i
.PHONY : src/command/ability_command/ability_command.cpp.i

src/command/ability_command/ability_command.s: src/command/ability_command/ability_command.cpp.s
.PHONY : src/command/ability_command/ability_command.s

# target to generate assembly for a file
src/command/ability_command/ability_command.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/ability_command.cpp.s
.PHONY : src/command/ability_command/ability_command.cpp.s

src/command/ability_command/abilityless.o: src/command/ability_command/abilityless.cpp.o
.PHONY : src/command/ability_command/abilityless.o

# target to build an object file
src/command/ability_command/abilityless.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/abilityless.cpp.o
.PHONY : src/command/ability_command/abilityless.cpp.o

src/command/ability_command/abilityless.i: src/command/ability_command/abilityless.cpp.i
.PHONY : src/command/ability_command/abilityless.i

# target to preprocess a source file
src/command/ability_command/abilityless.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/abilityless.cpp.i
.PHONY : src/command/ability_command/abilityless.cpp.i

src/command/ability_command/abilityless.s: src/command/ability_command/abilityless.cpp.s
.PHONY : src/command/ability_command/abilityless.s

# target to generate assembly for a file
src/command/ability_command/abilityless.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/abilityless.cpp.s
.PHONY : src/command/ability_command/abilityless.cpp.s

src/command/ability_command/quadruple.o: src/command/ability_command/quadruple.cpp.o
.PHONY : src/command/ability_command/quadruple.o

# target to build an object file
src/command/ability_command/quadruple.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/quadruple.cpp.o
.PHONY : src/command/ability_command/quadruple.cpp.o

src/command/ability_command/quadruple.i: src/command/ability_command/quadruple.cpp.i
.PHONY : src/command/ability_command/quadruple.i

# target to preprocess a source file
src/command/ability_command/quadruple.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/quadruple.cpp.i
.PHONY : src/command/ability_command/quadruple.cpp.i

src/command/ability_command/quadruple.s: src/command/ability_command/quadruple.cpp.s
.PHONY : src/command/ability_command/quadruple.s

# target to generate assembly for a file
src/command/ability_command/quadruple.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/quadruple.cpp.s
.PHONY : src/command/ability_command/quadruple.cpp.s

src/command/ability_command/quarter.o: src/command/ability_command/quarter.cpp.o
.PHONY : src/command/ability_command/quarter.o

# target to build an object file
src/command/ability_command/quarter.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/quarter.cpp.o
.PHONY : src/command/ability_command/quarter.cpp.o

src/command/ability_command/quarter.i: src/command/ability_command/quarter.cpp.i
.PHONY : src/command/ability_command/quarter.i

# target to preprocess a source file
src/command/ability_command/quarter.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/quarter.cpp.i
.PHONY : src/command/ability_command/quarter.cpp.i

src/command/ability_command/quarter.s: src/command/ability_command/quarter.cpp.s
.PHONY : src/command/ability_command/quarter.s

# target to generate assembly for a file
src/command/ability_command/quarter.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/quarter.cpp.s
.PHONY : src/command/ability_command/quarter.cpp.s

src/command/ability_command/reroll.o: src/command/ability_command/reroll.cpp.o
.PHONY : src/command/ability_command/reroll.o

# target to build an object file
src/command/ability_command/reroll.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/reroll.cpp.o
.PHONY : src/command/ability_command/reroll.cpp.o

src/command/ability_command/reroll.i: src/command/ability_command/reroll.cpp.i
.PHONY : src/command/ability_command/reroll.i

# target to preprocess a source file
src/command/ability_command/reroll.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/reroll.cpp.i
.PHONY : src/command/ability_command/reroll.cpp.i

src/command/ability_command/reroll.s: src/command/ability_command/reroll.cpp.s
.PHONY : src/command/ability_command/reroll.s

# target to generate assembly for a file
src/command/ability_command/reroll.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/reroll.cpp.s
.PHONY : src/command/ability_command/reroll.cpp.s

src/command/ability_command/reverse_direction.o: src/command/ability_command/reverse_direction.cpp.o
.PHONY : src/command/ability_command/reverse_direction.o

# target to build an object file
src/command/ability_command/reverse_direction.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/reverse_direction.cpp.o
.PHONY : src/command/ability_command/reverse_direction.cpp.o

src/command/ability_command/reverse_direction.i: src/command/ability_command/reverse_direction.cpp.i
.PHONY : src/command/ability_command/reverse_direction.i

# target to preprocess a source file
src/command/ability_command/reverse_direction.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/reverse_direction.cpp.i
.PHONY : src/command/ability_command/reverse_direction.cpp.i

src/command/ability_command/reverse_direction.s: src/command/ability_command/reverse_direction.cpp.s
.PHONY : src/command/ability_command/reverse_direction.s

# target to generate assembly for a file
src/command/ability_command/reverse_direction.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/reverse_direction.cpp.s
.PHONY : src/command/ability_command/reverse_direction.cpp.s

src/command/ability_command/swap_card.o: src/command/ability_command/swap_card.cpp.o
.PHONY : src/command/ability_command/swap_card.o

# target to build an object file
src/command/ability_command/swap_card.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/swap_card.cpp.o
.PHONY : src/command/ability_command/swap_card.cpp.o

src/command/ability_command/swap_card.i: src/command/ability_command/swap_card.cpp.i
.PHONY : src/command/ability_command/swap_card.i

# target to preprocess a source file
src/command/ability_command/swap_card.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/swap_card.cpp.i
.PHONY : src/command/ability_command/swap_card.cpp.i

src/command/ability_command/swap_card.s: src/command/ability_command/swap_card.cpp.s
.PHONY : src/command/ability_command/swap_card.s

# target to generate assembly for a file
src/command/ability_command/swap_card.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/swap_card.cpp.s
.PHONY : src/command/ability_command/swap_card.cpp.s

src/command/ability_command/switch_card.o: src/command/ability_command/switch_card.cpp.o
.PHONY : src/command/ability_command/switch_card.o

# target to build an object file
src/command/ability_command/switch_card.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/switch_card.cpp.o
.PHONY : src/command/ability_command/switch_card.cpp.o

src/command/ability_command/switch_card.i: src/command/ability_command/switch_card.cpp.i
.PHONY : src/command/ability_command/switch_card.i

# target to preprocess a source file
src/command/ability_command/switch_card.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/switch_card.cpp.i
.PHONY : src/command/ability_command/switch_card.cpp.i

src/command/ability_command/switch_card.s: src/command/ability_command/switch_card.cpp.s
.PHONY : src/command/ability_command/switch_card.s

# target to generate assembly for a file
src/command/ability_command/switch_card.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/ability_command/switch_card.cpp.s
.PHONY : src/command/ability_command/switch_card.cpp.s

src/command/basic_command/basic_command.o: src/command/basic_command/basic_command.cpp.o
.PHONY : src/command/basic_command/basic_command.o

# target to build an object file
src/command/basic_command/basic_command.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/basic_command.cpp.o
.PHONY : src/command/basic_command/basic_command.cpp.o

src/command/basic_command/basic_command.i: src/command/basic_command/basic_command.cpp.i
.PHONY : src/command/basic_command/basic_command.i

# target to preprocess a source file
src/command/basic_command/basic_command.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/basic_command.cpp.i
.PHONY : src/command/basic_command/basic_command.cpp.i

src/command/basic_command/basic_command.s: src/command/basic_command/basic_command.cpp.s
.PHONY : src/command/basic_command/basic_command.s

# target to generate assembly for a file
src/command/basic_command/basic_command.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/basic_command.cpp.s
.PHONY : src/command/basic_command/basic_command.cpp.s

src/command/basic_command/double.o: src/command/basic_command/double.cpp.o
.PHONY : src/command/basic_command/double.o

# target to build an object file
src/command/basic_command/double.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/double.cpp.o
.PHONY : src/command/basic_command/double.cpp.o

src/command/basic_command/double.i: src/command/basic_command/double.cpp.i
.PHONY : src/command/basic_command/double.i

# target to preprocess a source file
src/command/basic_command/double.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/double.cpp.i
.PHONY : src/command/basic_command/double.cpp.i

src/command/basic_command/double.s: src/command/basic_command/double.cpp.s
.PHONY : src/command/basic_command/double.s

# target to generate assembly for a file
src/command/basic_command/double.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/double.cpp.s
.PHONY : src/command/basic_command/double.cpp.s

src/command/basic_command/half.o: src/command/basic_command/half.cpp.o
.PHONY : src/command/basic_command/half.o

# target to build an object file
src/command/basic_command/half.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/half.cpp.o
.PHONY : src/command/basic_command/half.cpp.o

src/command/basic_command/half.i: src/command/basic_command/half.cpp.i
.PHONY : src/command/basic_command/half.i

# target to preprocess a source file
src/command/basic_command/half.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/half.cpp.i
.PHONY : src/command/basic_command/half.cpp.i

src/command/basic_command/half.s: src/command/basic_command/half.cpp.s
.PHONY : src/command/basic_command/half.s

# target to generate assembly for a file
src/command/basic_command/half.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/half.cpp.s
.PHONY : src/command/basic_command/half.cpp.s

src/command/basic_command/help.o: src/command/basic_command/help.cpp.o
.PHONY : src/command/basic_command/help.o

# target to build an object file
src/command/basic_command/help.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/help.cpp.o
.PHONY : src/command/basic_command/help.cpp.o

src/command/basic_command/help.i: src/command/basic_command/help.cpp.i
.PHONY : src/command/basic_command/help.i

# target to preprocess a source file
src/command/basic_command/help.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/help.cpp.i
.PHONY : src/command/basic_command/help.cpp.i

src/command/basic_command/help.s: src/command/basic_command/help.cpp.s
.PHONY : src/command/basic_command/help.s

# target to generate assembly for a file
src/command/basic_command/help.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/help.cpp.s
.PHONY : src/command/basic_command/help.cpp.s

src/command/basic_command/next.o: src/command/basic_command/next.cpp.o
.PHONY : src/command/basic_command/next.o

# target to build an object file
src/command/basic_command/next.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/next.cpp.o
.PHONY : src/command/basic_command/next.cpp.o

src/command/basic_command/next.i: src/command/basic_command/next.cpp.i
.PHONY : src/command/basic_command/next.i

# target to preprocess a source file
src/command/basic_command/next.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/next.cpp.i
.PHONY : src/command/basic_command/next.cpp.i

src/command/basic_command/next.s: src/command/basic_command/next.cpp.s
.PHONY : src/command/basic_command/next.s

# target to generate assembly for a file
src/command/basic_command/next.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/basic_command/next.cpp.s
.PHONY : src/command/basic_command/next.cpp.s

src/command/command.o: src/command/command.cpp.o
.PHONY : src/command/command.o

# target to build an object file
src/command/command.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/command.cpp.o
.PHONY : src/command/command.cpp.o

src/command/command.i: src/command/command.cpp.i
.PHONY : src/command/command.i

# target to preprocess a source file
src/command/command.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/command.cpp.i
.PHONY : src/command/command.cpp.i

src/command/command.s: src/command/command.cpp.s
.PHONY : src/command/command.s

# target to generate assembly for a file
src/command/command.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/command/command.cpp.s
.PHONY : src/command/command.cpp.s

src/game/game_cangkul.o: src/game/game_cangkul.cpp.o
.PHONY : src/game/game_cangkul.o

# target to build an object file
src/game/game_cangkul.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/game/game_cangkul.cpp.o
.PHONY : src/game/game_cangkul.cpp.o

src/game/game_cangkul.i: src/game/game_cangkul.cpp.i
.PHONY : src/game/game_cangkul.i

# target to preprocess a source file
src/game/game_cangkul.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/game/game_cangkul.cpp.i
.PHONY : src/game/game_cangkul.cpp.i

src/game/game_cangkul.s: src/game/game_cangkul.cpp.s
.PHONY : src/game/game_cangkul.s

# target to generate assembly for a file
src/game/game_cangkul.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/game/game_cangkul.cpp.s
.PHONY : src/game/game_cangkul.cpp.s

src/game/game_poker.o: src/game/game_poker.cpp.o
.PHONY : src/game/game_poker.o

# target to build an object file
src/game/game_poker.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/game/game_poker.cpp.o
.PHONY : src/game/game_poker.cpp.o

src/game/game_poker.i: src/game/game_poker.cpp.i
.PHONY : src/game/game_poker.i

# target to preprocess a source file
src/game/game_poker.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/game/game_poker.cpp.i
.PHONY : src/game/game_poker.cpp.i

src/game/game_poker.s: src/game/game_poker.cpp.s
.PHONY : src/game/game_poker.s

# target to generate assembly for a file
src/game/game_poker.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/game/game_poker.cpp.s
.PHONY : src/game/game_poker.cpp.s

src/input_handler/file_handler.o: src/input_handler/file_handler.cpp.o
.PHONY : src/input_handler/file_handler.o

# target to build an object file
src/input_handler/file_handler.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/input_handler/file_handler.cpp.o
.PHONY : src/input_handler/file_handler.cpp.o

src/input_handler/file_handler.i: src/input_handler/file_handler.cpp.i
.PHONY : src/input_handler/file_handler.i

# target to preprocess a source file
src/input_handler/file_handler.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/input_handler/file_handler.cpp.i
.PHONY : src/input_handler/file_handler.cpp.i

src/input_handler/file_handler.s: src/input_handler/file_handler.cpp.s
.PHONY : src/input_handler/file_handler.s

# target to generate assembly for a file
src/input_handler/file_handler.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/input_handler/file_handler.cpp.s
.PHONY : src/input_handler/file_handler.cpp.s

src/inventory_holder/deck.o: src/inventory_holder/deck.cpp.o
.PHONY : src/inventory_holder/deck.o

# target to build an object file
src/inventory_holder/deck.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/deck.cpp.o
.PHONY : src/inventory_holder/deck.cpp.o

src/inventory_holder/deck.i: src/inventory_holder/deck.cpp.i
.PHONY : src/inventory_holder/deck.i

# target to preprocess a source file
src/inventory_holder/deck.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/deck.cpp.i
.PHONY : src/inventory_holder/deck.cpp.i

src/inventory_holder/deck.s: src/inventory_holder/deck.cpp.s
.PHONY : src/inventory_holder/deck.s

# target to generate assembly for a file
src/inventory_holder/deck.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/deck.cpp.s
.PHONY : src/inventory_holder/deck.cpp.s

src/inventory_holder/player_cangkul.o: src/inventory_holder/player_cangkul.cpp.o
.PHONY : src/inventory_holder/player_cangkul.o

# target to build an object file
src/inventory_holder/player_cangkul.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/player_cangkul.cpp.o
.PHONY : src/inventory_holder/player_cangkul.cpp.o

src/inventory_holder/player_cangkul.i: src/inventory_holder/player_cangkul.cpp.i
.PHONY : src/inventory_holder/player_cangkul.i

# target to preprocess a source file
src/inventory_holder/player_cangkul.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/player_cangkul.cpp.i
.PHONY : src/inventory_holder/player_cangkul.cpp.i

src/inventory_holder/player_cangkul.s: src/inventory_holder/player_cangkul.cpp.s
.PHONY : src/inventory_holder/player_cangkul.s

# target to generate assembly for a file
src/inventory_holder/player_cangkul.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/player_cangkul.cpp.s
.PHONY : src/inventory_holder/player_cangkul.cpp.s

src/inventory_holder/player_poker.o: src/inventory_holder/player_poker.cpp.o
.PHONY : src/inventory_holder/player_poker.o

# target to build an object file
src/inventory_holder/player_poker.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/player_poker.cpp.o
.PHONY : src/inventory_holder/player_poker.cpp.o

src/inventory_holder/player_poker.i: src/inventory_holder/player_poker.cpp.i
.PHONY : src/inventory_holder/player_poker.i

# target to preprocess a source file
src/inventory_holder/player_poker.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/player_poker.cpp.i
.PHONY : src/inventory_holder/player_poker.cpp.i

src/inventory_holder/player_poker.s: src/inventory_holder/player_poker.cpp.s
.PHONY : src/inventory_holder/player_poker.s

# target to generate assembly for a file
src/inventory_holder/player_poker.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/player_poker.cpp.s
.PHONY : src/inventory_holder/player_poker.cpp.s

src/inventory_holder/table_card.o: src/inventory_holder/table_card.cpp.o
.PHONY : src/inventory_holder/table_card.o

# target to build an object file
src/inventory_holder/table_card.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/table_card.cpp.o
.PHONY : src/inventory_holder/table_card.cpp.o

src/inventory_holder/table_card.i: src/inventory_holder/table_card.cpp.i
.PHONY : src/inventory_holder/table_card.i

# target to preprocess a source file
src/inventory_holder/table_card.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/table_card.cpp.i
.PHONY : src/inventory_holder/table_card.cpp.i

src/inventory_holder/table_card.s: src/inventory_holder/table_card.cpp.s
.PHONY : src/inventory_holder/table_card.s

# target to generate assembly for a file
src/inventory_holder/table_card.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/inventory_holder/table_card.cpp.s
.PHONY : src/inventory_holder/table_card.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/runner/runner.o: src/runner/runner.cpp.o
.PHONY : src/runner/runner.o

# target to build an object file
src/runner/runner.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/runner/runner.cpp.o
.PHONY : src/runner/runner.cpp.o

src/runner/runner.i: src/runner/runner.cpp.i
.PHONY : src/runner/runner.i

# target to preprocess a source file
src/runner/runner.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/runner/runner.cpp.i
.PHONY : src/runner/runner.cpp.i

src/runner/runner.s: src/runner/runner.cpp.s
.PHONY : src/runner/runner.s

# target to generate assembly for a file
src/runner/runner.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/runner/runner.cpp.s
.PHONY : src/runner/runner.cpp.s

src/valuables/ability_card.o: src/valuables/ability_card.cpp.o
.PHONY : src/valuables/ability_card.o

# target to build an object file
src/valuables/ability_card.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/ability_card.cpp.o
.PHONY : src/valuables/ability_card.cpp.o

src/valuables/ability_card.i: src/valuables/ability_card.cpp.i
.PHONY : src/valuables/ability_card.i

# target to preprocess a source file
src/valuables/ability_card.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/ability_card.cpp.i
.PHONY : src/valuables/ability_card.cpp.i

src/valuables/ability_card.s: src/valuables/ability_card.cpp.s
.PHONY : src/valuables/ability_card.s

# target to generate assembly for a file
src/valuables/ability_card.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/ability_card.cpp.s
.PHONY : src/valuables/ability_card.cpp.s

src/valuables/card.o: src/valuables/card.cpp.o
.PHONY : src/valuables/card.o

# target to build an object file
src/valuables/card.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/card.cpp.o
.PHONY : src/valuables/card.cpp.o

src/valuables/card.i: src/valuables/card.cpp.i
.PHONY : src/valuables/card.i

# target to preprocess a source file
src/valuables/card.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/card.cpp.i
.PHONY : src/valuables/card.cpp.i

src/valuables/card.s: src/valuables/card.cpp.s
.PHONY : src/valuables/card.s

# target to generate assembly for a file
src/valuables/card.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/card.cpp.s
.PHONY : src/valuables/card.cpp.s

src/valuables/combine.o: src/valuables/combine.cpp.o
.PHONY : src/valuables/combine.o

# target to build an object file
src/valuables/combine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/combine.cpp.o
.PHONY : src/valuables/combine.cpp.o

src/valuables/combine.i: src/valuables/combine.cpp.i
.PHONY : src/valuables/combine.i

# target to preprocess a source file
src/valuables/combine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/combine.cpp.i
.PHONY : src/valuables/combine.cpp.i

src/valuables/combine.s: src/valuables/combine.cpp.s
.PHONY : src/valuables/combine.s

# target to generate assembly for a file
src/valuables/combine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/combine.cpp.s
.PHONY : src/valuables/combine.cpp.s

src/valuables/combo.o: src/valuables/combo.cpp.o
.PHONY : src/valuables/combo.o

# target to build an object file
src/valuables/combo.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/combo.cpp.o
.PHONY : src/valuables/combo.cpp.o

src/valuables/combo.i: src/valuables/combo.cpp.i
.PHONY : src/valuables/combo.i

# target to preprocess a source file
src/valuables/combo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/combo.cpp.i
.PHONY : src/valuables/combo.cpp.i

src/valuables/combo.s: src/valuables/combo.cpp.s
.PHONY : src/valuables/combo.s

# target to generate assembly for a file
src/valuables/combo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tubes-1-OOP-O08.dir/build.make CMakeFiles/Tubes-1-OOP-O08.dir/src/valuables/combo.cpp.s
.PHONY : src/valuables/combo.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Tubes-1-OOP-O08"
	@echo "... src/command/ability_command/ability_command.o"
	@echo "... src/command/ability_command/ability_command.i"
	@echo "... src/command/ability_command/ability_command.s"
	@echo "... src/command/ability_command/abilityless.o"
	@echo "... src/command/ability_command/abilityless.i"
	@echo "... src/command/ability_command/abilityless.s"
	@echo "... src/command/ability_command/quadruple.o"
	@echo "... src/command/ability_command/quadruple.i"
	@echo "... src/command/ability_command/quadruple.s"
	@echo "... src/command/ability_command/quarter.o"
	@echo "... src/command/ability_command/quarter.i"
	@echo "... src/command/ability_command/quarter.s"
	@echo "... src/command/ability_command/reroll.o"
	@echo "... src/command/ability_command/reroll.i"
	@echo "... src/command/ability_command/reroll.s"
	@echo "... src/command/ability_command/reverse_direction.o"
	@echo "... src/command/ability_command/reverse_direction.i"
	@echo "... src/command/ability_command/reverse_direction.s"
	@echo "... src/command/ability_command/swap_card.o"
	@echo "... src/command/ability_command/swap_card.i"
	@echo "... src/command/ability_command/swap_card.s"
	@echo "... src/command/ability_command/switch_card.o"
	@echo "... src/command/ability_command/switch_card.i"
	@echo "... src/command/ability_command/switch_card.s"
	@echo "... src/command/basic_command/basic_command.o"
	@echo "... src/command/basic_command/basic_command.i"
	@echo "... src/command/basic_command/basic_command.s"
	@echo "... src/command/basic_command/double.o"
	@echo "... src/command/basic_command/double.i"
	@echo "... src/command/basic_command/double.s"
	@echo "... src/command/basic_command/half.o"
	@echo "... src/command/basic_command/half.i"
	@echo "... src/command/basic_command/half.s"
	@echo "... src/command/basic_command/help.o"
	@echo "... src/command/basic_command/help.i"
	@echo "... src/command/basic_command/help.s"
	@echo "... src/command/basic_command/next.o"
	@echo "... src/command/basic_command/next.i"
	@echo "... src/command/basic_command/next.s"
	@echo "... src/command/command.o"
	@echo "... src/command/command.i"
	@echo "... src/command/command.s"
	@echo "... src/game/game_cangkul.o"
	@echo "... src/game/game_cangkul.i"
	@echo "... src/game/game_cangkul.s"
	@echo "... src/game/game_poker.o"
	@echo "... src/game/game_poker.i"
	@echo "... src/game/game_poker.s"
	@echo "... src/input_handler/file_handler.o"
	@echo "... src/input_handler/file_handler.i"
	@echo "... src/input_handler/file_handler.s"
	@echo "... src/inventory_holder/deck.o"
	@echo "... src/inventory_holder/deck.i"
	@echo "... src/inventory_holder/deck.s"
	@echo "... src/inventory_holder/player_cangkul.o"
	@echo "... src/inventory_holder/player_cangkul.i"
	@echo "... src/inventory_holder/player_cangkul.s"
	@echo "... src/inventory_holder/player_poker.o"
	@echo "... src/inventory_holder/player_poker.i"
	@echo "... src/inventory_holder/player_poker.s"
	@echo "... src/inventory_holder/table_card.o"
	@echo "... src/inventory_holder/table_card.i"
	@echo "... src/inventory_holder/table_card.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/runner/runner.o"
	@echo "... src/runner/runner.i"
	@echo "... src/runner/runner.s"
	@echo "... src/valuables/ability_card.o"
	@echo "... src/valuables/ability_card.i"
	@echo "... src/valuables/ability_card.s"
	@echo "... src/valuables/card.o"
	@echo "... src/valuables/card.i"
	@echo "... src/valuables/card.s"
	@echo "... src/valuables/combine.o"
	@echo "... src/valuables/combine.i"
	@echo "... src/valuables/combine.s"
	@echo "... src/valuables/combo.o"
	@echo "... src/valuables/combo.i"
	@echo "... src/valuables/combo.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

