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
CMAKE_SOURCE_DIR = /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/build

# Include any dependencies generated for this target.
include CMakeFiles/MaximumSubArray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MaximumSubArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MaximumSubArray.dir/flags.make

CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o: CMakeFiles/MaximumSubArray.dir/flags.make
CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o: ../maximum_subarray.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o -c /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/maximum_subarray.cpp

CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/maximum_subarray.cpp > CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.i

CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/maximum_subarray.cpp -o CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.s

CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o.requires:
.PHONY : CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o.requires

CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o.provides: CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o.requires
	$(MAKE) -f CMakeFiles/MaximumSubArray.dir/build.make CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o.provides.build
.PHONY : CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o.provides

CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o.provides.build: CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o

# Object files for target MaximumSubArray
MaximumSubArray_OBJECTS = \
"CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o"

# External object files for target MaximumSubArray
MaximumSubArray_EXTERNAL_OBJECTS =

MaximumSubArray: CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o
MaximumSubArray: CMakeFiles/MaximumSubArray.dir/build.make
MaximumSubArray: CMakeFiles/MaximumSubArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable MaximumSubArray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MaximumSubArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MaximumSubArray.dir/build: MaximumSubArray
.PHONY : CMakeFiles/MaximumSubArray.dir/build

CMakeFiles/MaximumSubArray.dir/requires: CMakeFiles/MaximumSubArray.dir/maximum_subarray.cpp.o.requires
.PHONY : CMakeFiles/MaximumSubArray.dir/requires

CMakeFiles/MaximumSubArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MaximumSubArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MaximumSubArray.dir/clean

CMakeFiles/MaximumSubArray.dir/depend:
	cd /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/build /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/build /home/k3rb3ros/projects/Codeing_Practice/maximum_subarray/build/CMakeFiles/MaximumSubArray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MaximumSubArray.dir/depend
