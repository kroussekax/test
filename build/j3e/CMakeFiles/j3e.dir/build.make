# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dave/Documents/c++/J3C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dave/Documents/c++/J3C/build

# Include any dependencies generated for this target.
include j3e/CMakeFiles/j3e.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include j3e/CMakeFiles/j3e.dir/compiler_depend.make

# Include the progress variables for this target.
include j3e/CMakeFiles/j3e.dir/progress.make

# Include the compile flags for this target's objects.
include j3e/CMakeFiles/j3e.dir/flags.make

j3e/CMakeFiles/j3e.dir/codegen:
.PHONY : j3e/CMakeFiles/j3e.dir/codegen

j3e/CMakeFiles/j3e.dir/src/globals.cpp.o: j3e/CMakeFiles/j3e.dir/flags.make
j3e/CMakeFiles/j3e.dir/src/globals.cpp.o: /home/dave/Documents/c++/J3C/j3e/src/globals.cpp
j3e/CMakeFiles/j3e.dir/src/globals.cpp.o: j3e/CMakeFiles/j3e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object j3e/CMakeFiles/j3e.dir/src/globals.cpp.o"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT j3e/CMakeFiles/j3e.dir/src/globals.cpp.o -MF CMakeFiles/j3e.dir/src/globals.cpp.o.d -o CMakeFiles/j3e.dir/src/globals.cpp.o -c /home/dave/Documents/c++/J3C/j3e/src/globals.cpp

j3e/CMakeFiles/j3e.dir/src/globals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/j3e.dir/src/globals.cpp.i"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dave/Documents/c++/J3C/j3e/src/globals.cpp > CMakeFiles/j3e.dir/src/globals.cpp.i

j3e/CMakeFiles/j3e.dir/src/globals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/j3e.dir/src/globals.cpp.s"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dave/Documents/c++/J3C/j3e/src/globals.cpp -o CMakeFiles/j3e.dir/src/globals.cpp.s

j3e/CMakeFiles/j3e.dir/src/j3e.cpp.o: j3e/CMakeFiles/j3e.dir/flags.make
j3e/CMakeFiles/j3e.dir/src/j3e.cpp.o: /home/dave/Documents/c++/J3C/j3e/src/j3e.cpp
j3e/CMakeFiles/j3e.dir/src/j3e.cpp.o: j3e/CMakeFiles/j3e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object j3e/CMakeFiles/j3e.dir/src/j3e.cpp.o"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT j3e/CMakeFiles/j3e.dir/src/j3e.cpp.o -MF CMakeFiles/j3e.dir/src/j3e.cpp.o.d -o CMakeFiles/j3e.dir/src/j3e.cpp.o -c /home/dave/Documents/c++/J3C/j3e/src/j3e.cpp

j3e/CMakeFiles/j3e.dir/src/j3e.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/j3e.dir/src/j3e.cpp.i"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dave/Documents/c++/J3C/j3e/src/j3e.cpp > CMakeFiles/j3e.dir/src/j3e.cpp.i

j3e/CMakeFiles/j3e.dir/src/j3e.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/j3e.dir/src/j3e.cpp.s"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dave/Documents/c++/J3C/j3e/src/j3e.cpp -o CMakeFiles/j3e.dir/src/j3e.cpp.s

j3e/CMakeFiles/j3e.dir/src/level.cpp.o: j3e/CMakeFiles/j3e.dir/flags.make
j3e/CMakeFiles/j3e.dir/src/level.cpp.o: /home/dave/Documents/c++/J3C/j3e/src/level.cpp
j3e/CMakeFiles/j3e.dir/src/level.cpp.o: j3e/CMakeFiles/j3e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object j3e/CMakeFiles/j3e.dir/src/level.cpp.o"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT j3e/CMakeFiles/j3e.dir/src/level.cpp.o -MF CMakeFiles/j3e.dir/src/level.cpp.o.d -o CMakeFiles/j3e.dir/src/level.cpp.o -c /home/dave/Documents/c++/J3C/j3e/src/level.cpp

j3e/CMakeFiles/j3e.dir/src/level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/j3e.dir/src/level.cpp.i"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dave/Documents/c++/J3C/j3e/src/level.cpp > CMakeFiles/j3e.dir/src/level.cpp.i

j3e/CMakeFiles/j3e.dir/src/level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/j3e.dir/src/level.cpp.s"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dave/Documents/c++/J3C/j3e/src/level.cpp -o CMakeFiles/j3e.dir/src/level.cpp.s

j3e/CMakeFiles/j3e.dir/src/mesh.cpp.o: j3e/CMakeFiles/j3e.dir/flags.make
j3e/CMakeFiles/j3e.dir/src/mesh.cpp.o: /home/dave/Documents/c++/J3C/j3e/src/mesh.cpp
j3e/CMakeFiles/j3e.dir/src/mesh.cpp.o: j3e/CMakeFiles/j3e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object j3e/CMakeFiles/j3e.dir/src/mesh.cpp.o"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT j3e/CMakeFiles/j3e.dir/src/mesh.cpp.o -MF CMakeFiles/j3e.dir/src/mesh.cpp.o.d -o CMakeFiles/j3e.dir/src/mesh.cpp.o -c /home/dave/Documents/c++/J3C/j3e/src/mesh.cpp

j3e/CMakeFiles/j3e.dir/src/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/j3e.dir/src/mesh.cpp.i"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dave/Documents/c++/J3C/j3e/src/mesh.cpp > CMakeFiles/j3e.dir/src/mesh.cpp.i

j3e/CMakeFiles/j3e.dir/src/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/j3e.dir/src/mesh.cpp.s"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dave/Documents/c++/J3C/j3e/src/mesh.cpp -o CMakeFiles/j3e.dir/src/mesh.cpp.s

j3e/CMakeFiles/j3e.dir/src/shader.cpp.o: j3e/CMakeFiles/j3e.dir/flags.make
j3e/CMakeFiles/j3e.dir/src/shader.cpp.o: /home/dave/Documents/c++/J3C/j3e/src/shader.cpp
j3e/CMakeFiles/j3e.dir/src/shader.cpp.o: j3e/CMakeFiles/j3e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object j3e/CMakeFiles/j3e.dir/src/shader.cpp.o"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT j3e/CMakeFiles/j3e.dir/src/shader.cpp.o -MF CMakeFiles/j3e.dir/src/shader.cpp.o.d -o CMakeFiles/j3e.dir/src/shader.cpp.o -c /home/dave/Documents/c++/J3C/j3e/src/shader.cpp

j3e/CMakeFiles/j3e.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/j3e.dir/src/shader.cpp.i"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dave/Documents/c++/J3C/j3e/src/shader.cpp > CMakeFiles/j3e.dir/src/shader.cpp.i

j3e/CMakeFiles/j3e.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/j3e.dir/src/shader.cpp.s"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dave/Documents/c++/J3C/j3e/src/shader.cpp -o CMakeFiles/j3e.dir/src/shader.cpp.s

j3e/CMakeFiles/j3e.dir/src/stb.cpp.o: j3e/CMakeFiles/j3e.dir/flags.make
j3e/CMakeFiles/j3e.dir/src/stb.cpp.o: /home/dave/Documents/c++/J3C/j3e/src/stb.cpp
j3e/CMakeFiles/j3e.dir/src/stb.cpp.o: j3e/CMakeFiles/j3e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object j3e/CMakeFiles/j3e.dir/src/stb.cpp.o"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT j3e/CMakeFiles/j3e.dir/src/stb.cpp.o -MF CMakeFiles/j3e.dir/src/stb.cpp.o.d -o CMakeFiles/j3e.dir/src/stb.cpp.o -c /home/dave/Documents/c++/J3C/j3e/src/stb.cpp

j3e/CMakeFiles/j3e.dir/src/stb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/j3e.dir/src/stb.cpp.i"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dave/Documents/c++/J3C/j3e/src/stb.cpp > CMakeFiles/j3e.dir/src/stb.cpp.i

j3e/CMakeFiles/j3e.dir/src/stb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/j3e.dir/src/stb.cpp.s"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dave/Documents/c++/J3C/j3e/src/stb.cpp -o CMakeFiles/j3e.dir/src/stb.cpp.s

j3e/CMakeFiles/j3e.dir/src/texture.cpp.o: j3e/CMakeFiles/j3e.dir/flags.make
j3e/CMakeFiles/j3e.dir/src/texture.cpp.o: /home/dave/Documents/c++/J3C/j3e/src/texture.cpp
j3e/CMakeFiles/j3e.dir/src/texture.cpp.o: j3e/CMakeFiles/j3e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object j3e/CMakeFiles/j3e.dir/src/texture.cpp.o"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT j3e/CMakeFiles/j3e.dir/src/texture.cpp.o -MF CMakeFiles/j3e.dir/src/texture.cpp.o.d -o CMakeFiles/j3e.dir/src/texture.cpp.o -c /home/dave/Documents/c++/J3C/j3e/src/texture.cpp

j3e/CMakeFiles/j3e.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/j3e.dir/src/texture.cpp.i"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dave/Documents/c++/J3C/j3e/src/texture.cpp > CMakeFiles/j3e.dir/src/texture.cpp.i

j3e/CMakeFiles/j3e.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/j3e.dir/src/texture.cpp.s"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dave/Documents/c++/J3C/j3e/src/texture.cpp -o CMakeFiles/j3e.dir/src/texture.cpp.s

j3e/CMakeFiles/j3e.dir/src/window.cpp.o: j3e/CMakeFiles/j3e.dir/flags.make
j3e/CMakeFiles/j3e.dir/src/window.cpp.o: /home/dave/Documents/c++/J3C/j3e/src/window.cpp
j3e/CMakeFiles/j3e.dir/src/window.cpp.o: j3e/CMakeFiles/j3e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object j3e/CMakeFiles/j3e.dir/src/window.cpp.o"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT j3e/CMakeFiles/j3e.dir/src/window.cpp.o -MF CMakeFiles/j3e.dir/src/window.cpp.o.d -o CMakeFiles/j3e.dir/src/window.cpp.o -c /home/dave/Documents/c++/J3C/j3e/src/window.cpp

j3e/CMakeFiles/j3e.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/j3e.dir/src/window.cpp.i"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dave/Documents/c++/J3C/j3e/src/window.cpp > CMakeFiles/j3e.dir/src/window.cpp.i

j3e/CMakeFiles/j3e.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/j3e.dir/src/window.cpp.s"
	cd /home/dave/Documents/c++/J3C/build/j3e && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dave/Documents/c++/J3C/j3e/src/window.cpp -o CMakeFiles/j3e.dir/src/window.cpp.s

# Object files for target j3e
j3e_OBJECTS = \
"CMakeFiles/j3e.dir/src/globals.cpp.o" \
"CMakeFiles/j3e.dir/src/j3e.cpp.o" \
"CMakeFiles/j3e.dir/src/level.cpp.o" \
"CMakeFiles/j3e.dir/src/mesh.cpp.o" \
"CMakeFiles/j3e.dir/src/shader.cpp.o" \
"CMakeFiles/j3e.dir/src/stb.cpp.o" \
"CMakeFiles/j3e.dir/src/texture.cpp.o" \
"CMakeFiles/j3e.dir/src/window.cpp.o"

# External object files for target j3e
j3e_EXTERNAL_OBJECTS =

j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/src/globals.cpp.o
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/src/j3e.cpp.o
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/src/level.cpp.o
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/src/mesh.cpp.o
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/src/shader.cpp.o
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/src/stb.cpp.o
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/src/texture.cpp.o
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/src/window.cpp.o
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/build.make
j3e/libj3e.a: j3e/CMakeFiles/j3e.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dave/Documents/c++/J3C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libj3e.a"
	cd /home/dave/Documents/c++/J3C/build/j3e && $(CMAKE_COMMAND) -P CMakeFiles/j3e.dir/cmake_clean_target.cmake
	cd /home/dave/Documents/c++/J3C/build/j3e && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/j3e.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
j3e/CMakeFiles/j3e.dir/build: j3e/libj3e.a
.PHONY : j3e/CMakeFiles/j3e.dir/build

j3e/CMakeFiles/j3e.dir/clean:
	cd /home/dave/Documents/c++/J3C/build/j3e && $(CMAKE_COMMAND) -P CMakeFiles/j3e.dir/cmake_clean.cmake
.PHONY : j3e/CMakeFiles/j3e.dir/clean

j3e/CMakeFiles/j3e.dir/depend:
	cd /home/dave/Documents/c++/J3C/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dave/Documents/c++/J3C /home/dave/Documents/c++/J3C/j3e /home/dave/Documents/c++/J3C/build /home/dave/Documents/c++/J3C/build/j3e /home/dave/Documents/c++/J3C/build/j3e/CMakeFiles/j3e.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : j3e/CMakeFiles/j3e.dir/depend

