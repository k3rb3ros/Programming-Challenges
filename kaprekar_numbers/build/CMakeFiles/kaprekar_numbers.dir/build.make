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
CMAKE_SOURCE_DIR = /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/build

# Include any dependencies generated for this target.
include CMakeFiles/kaprekar_numbers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kaprekar_numbers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kaprekar_numbers.dir/flags.make

CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o: CMakeFiles/kaprekar_numbers.dir/flags.make
CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o: ../kaprekar_numbers.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o -c /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/kaprekar_numbers.cpp

CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/kaprekar_numbers.cpp > CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.i

CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/kaprekar_numbers.cpp -o CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.s

CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o.requires:
.PHONY : CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o.requires

CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o.provides: CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o.requires
	$(MAKE) -f CMakeFiles/kaprekar_numbers.dir/build.make CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o.provides.build
.PHONY : CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o.provides

CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o.provides.build: CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o

# Object files for target kaprekar_numbers
kaprekar_numbers_OBJECTS = \
"CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o"

# External object files for target kaprekar_numbers
kaprekar_numbers_EXTERNAL_OBJECTS =

kaprekar_numbers: CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o
kaprekar_numbers: CMakeFiles/kaprekar_numbers.dir/build.make
kaprekar_numbers: CMakeFiles/kaprekar_numbers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable kaprekar_numbers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kaprekar_numbers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kaprekar_numbers.dir/build: kaprekar_numbers
.PHONY : CMakeFiles/kaprekar_numbers.dir/build

CMakeFiles/kaprekar_numbers.dir/requires: CMakeFiles/kaprekar_numbers.dir/kaprekar_numbers.cpp.o.requires
.PHONY : CMakeFiles/kaprekar_numbers.dir/requires

CMakeFiles/kaprekar_numbers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kaprekar_numbers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kaprekar_numbers.dir/clean

CMakeFiles/kaprekar_numbers.dir/depend:
	cd /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/build /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/build /home/k3rb3ros/projects/Codeing_Practice/kaprekar_numbers/build/CMakeFiles/kaprekar_numbers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kaprekar_numbers.dir/depend

