# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/g/cs144_lab/cs144_computer__network

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug

# Include any dependencies generated for this target.
include apps/CMakeFiles/tcp_udp.dir/depend.make

# Include the progress variables for this target.
include apps/CMakeFiles/tcp_udp.dir/progress.make

# Include the compile flags for this target's objects.
include apps/CMakeFiles/tcp_udp.dir/flags.make

apps/CMakeFiles/tcp_udp.dir/tcp_udp.cc.o: apps/CMakeFiles/tcp_udp.dir/flags.make
apps/CMakeFiles/tcp_udp.dir/tcp_udp.cc.o: ../apps/tcp_udp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/CMakeFiles/tcp_udp.dir/tcp_udp.cc.o"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tcp_udp.dir/tcp_udp.cc.o -c /mnt/g/cs144_lab/cs144_computer__network/apps/tcp_udp.cc

apps/CMakeFiles/tcp_udp.dir/tcp_udp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_udp.dir/tcp_udp.cc.i"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/cs144_lab/cs144_computer__network/apps/tcp_udp.cc > CMakeFiles/tcp_udp.dir/tcp_udp.cc.i

apps/CMakeFiles/tcp_udp.dir/tcp_udp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_udp.dir/tcp_udp.cc.s"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/cs144_lab/cs144_computer__network/apps/tcp_udp.cc -o CMakeFiles/tcp_udp.dir/tcp_udp.cc.s

# Object files for target tcp_udp
tcp_udp_OBJECTS = \
"CMakeFiles/tcp_udp.dir/tcp_udp.cc.o"

# External object files for target tcp_udp
tcp_udp_EXTERNAL_OBJECTS =

apps/tcp_udp: apps/CMakeFiles/tcp_udp.dir/tcp_udp.cc.o
apps/tcp_udp: apps/CMakeFiles/tcp_udp.dir/build.make
apps/tcp_udp: apps/libstream_copy.a
apps/tcp_udp: libsponge/libsponge.a
apps/tcp_udp: /usr/lib/x86_64-linux-gnu/libpthread.so
apps/tcp_udp: apps/CMakeFiles/tcp_udp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tcp_udp"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcp_udp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/CMakeFiles/tcp_udp.dir/build: apps/tcp_udp

.PHONY : apps/CMakeFiles/tcp_udp.dir/build

apps/CMakeFiles/tcp_udp.dir/clean:
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && $(CMAKE_COMMAND) -P CMakeFiles/tcp_udp.dir/cmake_clean.cmake
.PHONY : apps/CMakeFiles/tcp_udp.dir/clean

apps/CMakeFiles/tcp_udp.dir/depend:
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/cs144_lab/cs144_computer__network /mnt/g/cs144_lab/cs144_computer__network/apps /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps/CMakeFiles/tcp_udp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/CMakeFiles/tcp_udp.dir/depend

