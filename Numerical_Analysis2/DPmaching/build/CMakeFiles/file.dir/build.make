# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /opt/cmake-3.20.2-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.20.2-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/riku/GIT/5S/Numerical_Analysis2/DPmaching

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/riku/GIT/5S/Numerical_Analysis2/DPmaching/build

# Include any dependencies generated for this target.
include CMakeFiles/file.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/file.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/file.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/file.dir/flags.make

CMakeFiles/file.dir/satosi.cpp.o: CMakeFiles/file.dir/flags.make
CMakeFiles/file.dir/satosi.cpp.o: ../satosi.cpp
CMakeFiles/file.dir/satosi.cpp.o: CMakeFiles/file.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riku/GIT/5S/Numerical_Analysis2/DPmaching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/file.dir/satosi.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/file.dir/satosi.cpp.o -MF CMakeFiles/file.dir/satosi.cpp.o.d -o CMakeFiles/file.dir/satosi.cpp.o -c /home/riku/GIT/5S/Numerical_Analysis2/DPmaching/satosi.cpp

CMakeFiles/file.dir/satosi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/file.dir/satosi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riku/GIT/5S/Numerical_Analysis2/DPmaching/satosi.cpp > CMakeFiles/file.dir/satosi.cpp.i

CMakeFiles/file.dir/satosi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/file.dir/satosi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riku/GIT/5S/Numerical_Analysis2/DPmaching/satosi.cpp -o CMakeFiles/file.dir/satosi.cpp.s

# Object files for target file
file_OBJECTS = \
"CMakeFiles/file.dir/satosi.cpp.o"

# External object files for target file
file_EXTERNAL_OBJECTS =

file: CMakeFiles/file.dir/satosi.cpp.o
file: CMakeFiles/file.dir/build.make
file: CMakeFiles/file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/riku/GIT/5S/Numerical_Analysis2/DPmaching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable file"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/file.dir/build: file
.PHONY : CMakeFiles/file.dir/build

CMakeFiles/file.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/file.dir/cmake_clean.cmake
.PHONY : CMakeFiles/file.dir/clean

CMakeFiles/file.dir/depend:
	cd /home/riku/GIT/5S/Numerical_Analysis2/DPmaching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/riku/GIT/5S/Numerical_Analysis2/DPmaching /home/riku/GIT/5S/Numerical_Analysis2/DPmaching /home/riku/GIT/5S/Numerical_Analysis2/DPmaching/build /home/riku/GIT/5S/Numerical_Analysis2/DPmaching/build /home/riku/GIT/5S/Numerical_Analysis2/DPmaching/build/CMakeFiles/file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/file.dir/depend
