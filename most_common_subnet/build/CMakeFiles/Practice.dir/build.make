# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/build

# Include any dependencies generated for this target.
include CMakeFiles/Practice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Practice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Practice.dir/flags.make

CMakeFiles/Practice.dir/most_common_subnet.cpp.o: CMakeFiles/Practice.dir/flags.make
CMakeFiles/Practice.dir/most_common_subnet.cpp.o: ../most_common_subnet.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Practice.dir/most_common_subnet.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Practice.dir/most_common_subnet.cpp.o -c /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/most_common_subnet.cpp

CMakeFiles/Practice.dir/most_common_subnet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Practice.dir/most_common_subnet.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/most_common_subnet.cpp > CMakeFiles/Practice.dir/most_common_subnet.cpp.i

CMakeFiles/Practice.dir/most_common_subnet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Practice.dir/most_common_subnet.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/most_common_subnet.cpp -o CMakeFiles/Practice.dir/most_common_subnet.cpp.s

CMakeFiles/Practice.dir/most_common_subnet.cpp.o.requires:
.PHONY : CMakeFiles/Practice.dir/most_common_subnet.cpp.o.requires

CMakeFiles/Practice.dir/most_common_subnet.cpp.o.provides: CMakeFiles/Practice.dir/most_common_subnet.cpp.o.requires
	$(MAKE) -f CMakeFiles/Practice.dir/build.make CMakeFiles/Practice.dir/most_common_subnet.cpp.o.provides.build
.PHONY : CMakeFiles/Practice.dir/most_common_subnet.cpp.o.provides

CMakeFiles/Practice.dir/most_common_subnet.cpp.o.provides.build: CMakeFiles/Practice.dir/most_common_subnet.cpp.o

# Object files for target Practice
Practice_OBJECTS = \
"CMakeFiles/Practice.dir/most_common_subnet.cpp.o"

# External object files for target Practice
Practice_EXTERNAL_OBJECTS =

Practice: CMakeFiles/Practice.dir/most_common_subnet.cpp.o
Practice: CMakeFiles/Practice.dir/build.make
Practice: CMakeFiles/Practice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Practice"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Practice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Practice.dir/build: Practice
.PHONY : CMakeFiles/Practice.dir/build

CMakeFiles/Practice.dir/requires: CMakeFiles/Practice.dir/most_common_subnet.cpp.o.requires
.PHONY : CMakeFiles/Practice.dir/requires

CMakeFiles/Practice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Practice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Practice.dir/clean

CMakeFiles/Practice.dir/depend:
	cd /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/build /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/build /home/k3rb3ros/projects/Codeing_Practice/most_common_subnet/build/CMakeFiles/Practice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Practice.dir/depend

