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
CMAKE_SOURCE_DIR = /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/build

# Include any dependencies generated for this target.
include CMakeFiles/div_pairs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/div_pairs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/div_pairs.dir/flags.make

CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o: CMakeFiles/div_pairs.dir/flags.make
CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o: ../divisible_sum_pairs.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o -c /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/divisible_sum_pairs.cpp

CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/divisible_sum_pairs.cpp > CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.i

CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/divisible_sum_pairs.cpp -o CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.s

CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o.requires:
.PHONY : CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o.requires

CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o.provides: CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o.requires
	$(MAKE) -f CMakeFiles/div_pairs.dir/build.make CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o.provides.build
.PHONY : CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o.provides

CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o.provides.build: CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o

# Object files for target div_pairs
div_pairs_OBJECTS = \
"CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o"

# External object files for target div_pairs
div_pairs_EXTERNAL_OBJECTS =

div_pairs: CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o
div_pairs: CMakeFiles/div_pairs.dir/build.make
div_pairs: CMakeFiles/div_pairs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable div_pairs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/div_pairs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/div_pairs.dir/build: div_pairs
.PHONY : CMakeFiles/div_pairs.dir/build

CMakeFiles/div_pairs.dir/requires: CMakeFiles/div_pairs.dir/divisible_sum_pairs.cpp.o.requires
.PHONY : CMakeFiles/div_pairs.dir/requires

CMakeFiles/div_pairs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/div_pairs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/div_pairs.dir/clean

CMakeFiles/div_pairs.dir/depend:
	cd /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/build /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/build /home/k3rb3ros/projects/Codeing_Practice/divisible_sum_pairs/build/CMakeFiles/div_pairs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/div_pairs.dir/depend

