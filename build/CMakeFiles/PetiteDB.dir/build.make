# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /home/aichaos/miniconda3/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/aichaos/miniconda3/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aichaos/mylab/demodb/petite_DB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aichaos/mylab/demodb/petite_DB/build

# Include any dependencies generated for this target.
include CMakeFiles/PetiteDB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PetiteDB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PetiteDB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PetiteDB.dir/flags.make

CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o: CMakeFiles/PetiteDB.dir/flags.make
CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o: /home/aichaos/mylab/demodb/petite_DB/src/SqlToAst/SqlToAst.cpp
CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o: CMakeFiles/PetiteDB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aichaos/mylab/demodb/petite_DB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o -MF CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o.d -o CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o -c /home/aichaos/mylab/demodb/petite_DB/src/SqlToAst/SqlToAst.cpp

CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aichaos/mylab/demodb/petite_DB/src/SqlToAst/SqlToAst.cpp > CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.i

CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aichaos/mylab/demodb/petite_DB/src/SqlToAst/SqlToAst.cpp -o CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.s

CMakeFiles/PetiteDB.dir/src/petite.cpp.o: CMakeFiles/PetiteDB.dir/flags.make
CMakeFiles/PetiteDB.dir/src/petite.cpp.o: /home/aichaos/mylab/demodb/petite_DB/src/petite.cpp
CMakeFiles/PetiteDB.dir/src/petite.cpp.o: CMakeFiles/PetiteDB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aichaos/mylab/demodb/petite_DB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PetiteDB.dir/src/petite.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PetiteDB.dir/src/petite.cpp.o -MF CMakeFiles/PetiteDB.dir/src/petite.cpp.o.d -o CMakeFiles/PetiteDB.dir/src/petite.cpp.o -c /home/aichaos/mylab/demodb/petite_DB/src/petite.cpp

CMakeFiles/PetiteDB.dir/src/petite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PetiteDB.dir/src/petite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aichaos/mylab/demodb/petite_DB/src/petite.cpp > CMakeFiles/PetiteDB.dir/src/petite.cpp.i

CMakeFiles/PetiteDB.dir/src/petite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PetiteDB.dir/src/petite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aichaos/mylab/demodb/petite_DB/src/petite.cpp -o CMakeFiles/PetiteDB.dir/src/petite.cpp.s

# Object files for target PetiteDB
PetiteDB_OBJECTS = \
"CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o" \
"CMakeFiles/PetiteDB.dir/src/petite.cpp.o"

# External object files for target PetiteDB
PetiteDB_EXTERNAL_OBJECTS =

PetiteDB: CMakeFiles/PetiteDB.dir/src/SqlToAst/SqlToAst.cpp.o
PetiteDB: CMakeFiles/PetiteDB.dir/src/petite.cpp.o
PetiteDB: CMakeFiles/PetiteDB.dir/build.make
PetiteDB: CMakeFiles/PetiteDB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/aichaos/mylab/demodb/petite_DB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PetiteDB"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PetiteDB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PetiteDB.dir/build: PetiteDB
.PHONY : CMakeFiles/PetiteDB.dir/build

CMakeFiles/PetiteDB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PetiteDB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PetiteDB.dir/clean

CMakeFiles/PetiteDB.dir/depend:
	cd /home/aichaos/mylab/demodb/petite_DB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aichaos/mylab/demodb/petite_DB /home/aichaos/mylab/demodb/petite_DB /home/aichaos/mylab/demodb/petite_DB/build /home/aichaos/mylab/demodb/petite_DB/build /home/aichaos/mylab/demodb/petite_DB/build/CMakeFiles/PetiteDB.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PetiteDB.dir/depend

