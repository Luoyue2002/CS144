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
include apps/CMakeFiles/udp_tcpdump.dir/depend.make

# Include the progress variables for this target.
include apps/CMakeFiles/udp_tcpdump.dir/progress.make

# Include the compile flags for this target's objects.
include apps/CMakeFiles/udp_tcpdump.dir/flags.make

apps/CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.o: apps/CMakeFiles/udp_tcpdump.dir/flags.make
apps/CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.o: ../apps/udp_tcpdump.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.o"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.o -c /mnt/g/cs144_lab/cs144_computer__network/apps/udp_tcpdump.cc

apps/CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.i"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/cs144_lab/cs144_computer__network/apps/udp_tcpdump.cc > CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.i

apps/CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.s"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/cs144_lab/cs144_computer__network/apps/udp_tcpdump.cc -o CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.s

# Object files for target udp_tcpdump
udp_tcpdump_OBJECTS = \
"CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.o"

# External object files for target udp_tcpdump
udp_tcpdump_EXTERNAL_OBJECTS =

apps/udp_tcpdump: apps/CMakeFiles/udp_tcpdump.dir/udp_tcpdump.cc.o
apps/udp_tcpdump: apps/CMakeFiles/udp_tcpdump.dir/build.make
apps/udp_tcpdump: /usr/lib/x86_64-linux-gnu/libpcap.so
apps/udp_tcpdump: libsponge/libsponge.a
apps/udp_tcpdump: /usr/lib/x86_64-linux-gnu/libpthread.so
apps/udp_tcpdump: apps/CMakeFiles/udp_tcpdump.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable udp_tcpdump"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_tcpdump.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/CMakeFiles/udp_tcpdump.dir/build: apps/udp_tcpdump

.PHONY : apps/CMakeFiles/udp_tcpdump.dir/build

apps/CMakeFiles/udp_tcpdump.dir/clean:
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps && $(CMAKE_COMMAND) -P CMakeFiles/udp_tcpdump.dir/cmake_clean.cmake
.PHONY : apps/CMakeFiles/udp_tcpdump.dir/clean

apps/CMakeFiles/udp_tcpdump.dir/depend:
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/cs144_lab/cs144_computer__network /mnt/g/cs144_lab/cs144_computer__network/apps /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/apps/CMakeFiles/udp_tcpdump.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/CMakeFiles/udp_tcpdump.dir/depend

