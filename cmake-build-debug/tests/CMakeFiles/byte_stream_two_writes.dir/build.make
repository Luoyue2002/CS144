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
include tests/CMakeFiles/byte_stream_two_writes.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/byte_stream_two_writes.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/byte_stream_two_writes.dir/flags.make

tests/CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.o: tests/CMakeFiles/byte_stream_two_writes.dir/flags.make
tests/CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.o: ../tests/byte_stream_two_writes.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.o"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.o -c /mnt/g/cs144_lab/cs144_computer__network/tests/byte_stream_two_writes.cc

tests/CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.i"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/cs144_lab/cs144_computer__network/tests/byte_stream_two_writes.cc > CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.i

tests/CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.s"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/cs144_lab/cs144_computer__network/tests/byte_stream_two_writes.cc -o CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.s

# Object files for target byte_stream_two_writes
byte_stream_two_writes_OBJECTS = \
"CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.o"

# External object files for target byte_stream_two_writes
byte_stream_two_writes_EXTERNAL_OBJECTS =

tests/byte_stream_two_writes: tests/CMakeFiles/byte_stream_two_writes.dir/byte_stream_two_writes.cc.o
tests/byte_stream_two_writes: tests/CMakeFiles/byte_stream_two_writes.dir/build.make
tests/byte_stream_two_writes: tests/libspongechecks.a
tests/byte_stream_two_writes: libsponge/libsponge.a
tests/byte_stream_two_writes: tests/CMakeFiles/byte_stream_two_writes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable byte_stream_two_writes"
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/byte_stream_two_writes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/byte_stream_two_writes.dir/build: tests/byte_stream_two_writes

.PHONY : tests/CMakeFiles/byte_stream_two_writes.dir/build

tests/CMakeFiles/byte_stream_two_writes.dir/clean:
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/byte_stream_two_writes.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/byte_stream_two_writes.dir/clean

tests/CMakeFiles/byte_stream_two_writes.dir/depend:
	cd /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/cs144_lab/cs144_computer__network /mnt/g/cs144_lab/cs144_computer__network/tests /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/tests /mnt/g/cs144_lab/cs144_computer__network/cmake-build-debug/tests/CMakeFiles/byte_stream_two_writes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/byte_stream_two_writes.dir/depend

