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
CMAKE_SOURCE_DIR = /home/k3rb3ros/projects/Codeing_Practice/reverse_string

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/k3rb3ros/projects/Codeing_Practice/reverse_string/build

# Include any dependencies generated for this target.
include CMakeFiles/ReverseString.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ReverseString.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReverseString.dir/flags.make

CMakeFiles/ReverseString.dir/reverse_string.cpp.o: CMakeFiles/ReverseString.dir/flags.make
CMakeFiles/ReverseString.dir/reverse_string.cpp.o: ../reverse_string.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/k3rb3ros/projects/Codeing_Practice/reverse_string/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ReverseString.dir/reverse_string.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ReverseString.dir/reverse_string.cpp.o -c /home/k3rb3ros/projects/Codeing_Practice/reverse_string/reverse_string.cpp

CMakeFiles/ReverseString.dir/reverse_string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReverseString.dir/reverse_string.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/k3rb3ros/projects/Codeing_Practice/reverse_string/reverse_string.cpp > CMakeFiles/ReverseString.dir/reverse_string.cpp.i

CMakeFiles/ReverseString.dir/reverse_string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReverseString.dir/reverse_string.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/k3rb3ros/projects/Codeing_Practice/reverse_string/reverse_string.cpp -o CMakeFiles/ReverseString.dir/reverse_string.cpp.s

CMakeFiles/ReverseString.dir/reverse_string.cpp.o.requires:
.PHONY : CMakeFiles/ReverseString.dir/reverse_string.cpp.o.requires

CMakeFiles/ReverseString.dir/reverse_string.cpp.o.provides: CMakeFiles/ReverseString.dir/reverse_string.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReverseString.dir/build.make CMakeFiles/ReverseString.dir/reverse_string.cpp.o.provides.build
.PHONY : CMakeFiles/ReverseString.dir/reverse_string.cpp.o.provides

CMakeFiles/ReverseString.dir/reverse_string.cpp.o.provides.build: CMakeFiles/ReverseString.dir/reverse_string.cpp.o

# Object files for target ReverseString
ReverseString_OBJECTS = \
"CMakeFiles/ReverseString.dir/reverse_string.cpp.o"

# External object files for target ReverseString
ReverseString_EXTERNAL_OBJECTS =

ReverseString: CMakeFiles/ReverseString.dir/reverse_string.cpp.o
ReverseString: CMakeFiles/ReverseString.dir/build.make
ReverseString: CMakeFiles/ReverseString.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ReverseString"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReverseString.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReverseString.dir/build: ReverseString
.PHONY : CMakeFiles/ReverseString.dir/build

CMakeFiles/ReverseString.dir/requires: CMakeFiles/ReverseString.dir/reverse_string.cpp.o.requires
.PHONY : CMakeFiles/ReverseString.dir/requires

CMakeFiles/ReverseString.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReverseString.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReverseString.dir/clean

CMakeFiles/ReverseString.dir/depend:
	cd /home/k3rb3ros/projects/Codeing_Practice/reverse_string/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/k3rb3ros/projects/Codeing_Practice/reverse_string /home/k3rb3ros/projects/Codeing_Practice/reverse_string /home/k3rb3ros/projects/Codeing_Practice/reverse_string/build /home/k3rb3ros/projects/Codeing_Practice/reverse_string/build /home/k3rb3ros/projects/Codeing_Practice/reverse_string/build/CMakeFiles/ReverseString.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReverseString.dir/depend

