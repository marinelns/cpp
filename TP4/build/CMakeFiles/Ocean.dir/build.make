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
include CMakeFiles/Ocean.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ocean.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ocean.dir/flags.make

CMakeFiles/Ocean.dir/src/main.cxx.o: CMakeFiles/Ocean.dir/flags.make
CMakeFiles/Ocean.dir/src/main.cxx.o: ../src/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ocean.dir/src/main.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ocean.dir/src/main.cxx.o -c /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/src/main.cxx

CMakeFiles/Ocean.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ocean.dir/src/main.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/src/main.cxx > CMakeFiles/Ocean.dir/src/main.cxx.i

CMakeFiles/Ocean.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ocean.dir/src/main.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/src/main.cxx -o CMakeFiles/Ocean.dir/src/main.cxx.s

# Object files for target Ocean
Ocean_OBJECTS = \
"CMakeFiles/Ocean.dir/src/main.cxx.o"

# External object files for target Ocean
Ocean_EXTERNAL_OBJECTS =

Ocean: CMakeFiles/Ocean.dir/src/main.cxx.o
Ocean: CMakeFiles/Ocean.dir/build.make
Ocean: src/liblibOcean.a
Ocean: CMakeFiles/Ocean.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ocean"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ocean.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ocean.dir/build: Ocean

.PHONY : CMakeFiles/Ocean.dir/build

CMakeFiles/Ocean.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ocean.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ocean.dir/clean

CMakeFiles/Ocean.dir/depend:
	cd /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4 /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4 /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build /Users/marinelannes/Documents/IMAG/2A/C++/cpp/TP4/build/CMakeFiles/Ocean.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ocean.dir/depend

