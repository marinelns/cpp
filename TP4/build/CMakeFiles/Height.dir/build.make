# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build

# Include any dependencies generated for this target.
include CMakeFiles/Height.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Height.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Height.dir/flags.make

CMakeFiles/Height.dir/tests/mainHeight.cpp.o: CMakeFiles/Height.dir/flags.make
CMakeFiles/Height.dir/tests/mainHeight.cpp.o: ../tests/mainHeight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Height.dir/tests/mainHeight.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Height.dir/tests/mainHeight.cpp.o -c /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/tests/mainHeight.cpp

CMakeFiles/Height.dir/tests/mainHeight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Height.dir/tests/mainHeight.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/tests/mainHeight.cpp > CMakeFiles/Height.dir/tests/mainHeight.cpp.i

CMakeFiles/Height.dir/tests/mainHeight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Height.dir/tests/mainHeight.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/tests/mainHeight.cpp -o CMakeFiles/Height.dir/tests/mainHeight.cpp.s

# Object files for target Height
Height_OBJECTS = \
"CMakeFiles/Height.dir/tests/mainHeight.cpp.o"

# External object files for target Height
Height_EXTERNAL_OBJECTS =

Height: CMakeFiles/Height.dir/tests/mainHeight.cpp.o
Height: CMakeFiles/Height.dir/build.make
Height: src/liblibOcean.a
Height: CMakeFiles/Height.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Height"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Height.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Height.dir/build: Height

.PHONY : CMakeFiles/Height.dir/build

CMakeFiles/Height.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Height.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Height.dir/clean

CMakeFiles/Height.dir/depend:
	cd /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4 /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4 /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build/CMakeFiles/Height.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Height.dir/depend

