# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhangbin/xlive/rtmppush/testak201/h264-push

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhangbin/xlive/rtmppush/testak201/h264-push/build

# Include any dependencies generated for this target.
include CMakeFiles/rtmp_h264_push.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rtmp_h264_push.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rtmp_h264_push.dir/flags.make

CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o: CMakeFiles/rtmp_h264_push.dir/flags.make
CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zhangbin/xlive/rtmppush/testak201/h264-push/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o -c /home/zhangbin/xlive/rtmppush/testak201/h264-push/src/main.cpp

CMakeFiles/rtmp_h264_push.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rtmp_h264_push.dir/src/main.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zhangbin/xlive/rtmppush/testak201/h264-push/src/main.cpp > CMakeFiles/rtmp_h264_push.dir/src/main.cpp.i

CMakeFiles/rtmp_h264_push.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rtmp_h264_push.dir/src/main.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zhangbin/xlive/rtmppush/testak201/h264-push/src/main.cpp -o CMakeFiles/rtmp_h264_push.dir/src/main.cpp.s

CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o.requires

CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o.provides: CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/rtmp_h264_push.dir/build.make CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o.provides

CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o.provides.build: CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o

CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o: CMakeFiles/rtmp_h264_push.dir/flags.make
CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o: ../src/RTMPStream.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zhangbin/xlive/rtmppush/testak201/h264-push/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o -c /home/zhangbin/xlive/rtmppush/testak201/h264-push/src/RTMPStream.cpp

CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zhangbin/xlive/rtmppush/testak201/h264-push/src/RTMPStream.cpp > CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.i

CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zhangbin/xlive/rtmppush/testak201/h264-push/src/RTMPStream.cpp -o CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.s

CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o.requires:
.PHONY : CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o.requires

CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o.provides: CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o.requires
	$(MAKE) -f CMakeFiles/rtmp_h264_push.dir/build.make CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o.provides.build
.PHONY : CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o.provides

CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o.provides.build: CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o

# Object files for target rtmp_h264_push
rtmp_h264_push_OBJECTS = \
"CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o" \
"CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o"

# External object files for target rtmp_h264_push
rtmp_h264_push_EXTERNAL_OBJECTS =

rtmp_h264_push: CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o
rtmp_h264_push: CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o
rtmp_h264_push: CMakeFiles/rtmp_h264_push.dir/build.make
rtmp_h264_push: CMakeFiles/rtmp_h264_push.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable rtmp_h264_push"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rtmp_h264_push.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rtmp_h264_push.dir/build: rtmp_h264_push
.PHONY : CMakeFiles/rtmp_h264_push.dir/build

CMakeFiles/rtmp_h264_push.dir/requires: CMakeFiles/rtmp_h264_push.dir/src/main.cpp.o.requires
CMakeFiles/rtmp_h264_push.dir/requires: CMakeFiles/rtmp_h264_push.dir/src/RTMPStream.cpp.o.requires
.PHONY : CMakeFiles/rtmp_h264_push.dir/requires

CMakeFiles/rtmp_h264_push.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rtmp_h264_push.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rtmp_h264_push.dir/clean

CMakeFiles/rtmp_h264_push.dir/depend:
	cd /home/zhangbin/xlive/rtmppush/testak201/h264-push/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangbin/xlive/rtmppush/testak201/h264-push /home/zhangbin/xlive/rtmppush/testak201/h264-push /home/zhangbin/xlive/rtmppush/testak201/h264-push/build /home/zhangbin/xlive/rtmppush/testak201/h264-push/build /home/zhangbin/xlive/rtmppush/testak201/h264-push/build/CMakeFiles/rtmp_h264_push.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rtmp_h264_push.dir/depend

