# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Danie\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Danie\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Danie\Documents\GitHub\HAKIM_GAME

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Danie\Documents\GitHub\HAKIM_GAME\cmake-build-debug

# Utility rule file for simde.

# Include any custom commands dependencies for this target.
include _deps/box2d-build/extern/simde/CMakeFiles/simde.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/box2d-build/extern/simde/CMakeFiles/simde.dir/progress.make

simde: _deps/box2d-build/extern/simde/CMakeFiles/simde.dir/build.make
.PHONY : simde

# Rule to build all files generated by this target.
_deps/box2d-build/extern/simde/CMakeFiles/simde.dir/build: simde
.PHONY : _deps/box2d-build/extern/simde/CMakeFiles/simde.dir/build

_deps/box2d-build/extern/simde/CMakeFiles/simde.dir/clean:
	cd /d C:\Users\Danie\Documents\GitHub\HAKIM_GAME\cmake-build-debug\_deps\box2d-build\extern\simde && $(CMAKE_COMMAND) -P CMakeFiles\simde.dir\cmake_clean.cmake
.PHONY : _deps/box2d-build/extern/simde/CMakeFiles/simde.dir/clean

_deps/box2d-build/extern/simde/CMakeFiles/simde.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Danie\Documents\GitHub\HAKIM_GAME C:\Users\Danie\Documents\GitHub\HAKIM_GAME\cmake-build-debug\_deps\box2d-src\extern\simde C:\Users\Danie\Documents\GitHub\HAKIM_GAME\cmake-build-debug C:\Users\Danie\Documents\GitHub\HAKIM_GAME\cmake-build-debug\_deps\box2d-build\extern\simde C:\Users\Danie\Documents\GitHub\HAKIM_GAME\cmake-build-debug\_deps\box2d-build\extern\simde\CMakeFiles\simde.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/box2d-build/extern/simde/CMakeFiles/simde.dir/depend

