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
CMAKE_SOURCE_DIR = /home/ciaran/ClionProjects/SSLChain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ciaran/ClionProjects/SSLChain/build

# Include any dependencies generated for this target.
include CMakeFiles/SSLChain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SSLChain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SSLChain.dir/flags.make

CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o: ../crypto/hmac_sha512.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o -c /home/ciaran/ClionProjects/SSLChain/crypto/hmac_sha512.cpp

CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/crypto/hmac_sha512.cpp > CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.i

CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/crypto/hmac_sha512.cpp -o CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.s

CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o.requires

CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o.provides: CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o.provides

CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o.provides.build: CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o

CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o: ../crypto/sha512.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o -c /home/ciaran/ClionProjects/SSLChain/crypto/sha512.cpp

CMakeFiles/SSLChain.dir/crypto/sha512.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/crypto/sha512.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/crypto/sha512.cpp > CMakeFiles/SSLChain.dir/crypto/sha512.cpp.i

CMakeFiles/SSLChain.dir/crypto/sha512.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/crypto/sha512.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/crypto/sha512.cpp -o CMakeFiles/SSLChain.dir/crypto/sha512.cpp.s

CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o.requires

CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o.provides: CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o.provides

CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o.provides.build: CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o

CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o: ../crypto/ripemd160.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o -c /home/ciaran/ClionProjects/SSLChain/crypto/ripemd160.cpp

CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/crypto/ripemd160.cpp > CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.i

CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/crypto/ripemd160.cpp -o CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.s

CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o.requires

CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o.provides: CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o.provides

CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o.provides.build: CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o

CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o: ../crypto/sha256.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o -c /home/ciaran/ClionProjects/SSLChain/crypto/sha256.cpp

CMakeFiles/SSLChain.dir/crypto/sha256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/crypto/sha256.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/crypto/sha256.cpp > CMakeFiles/SSLChain.dir/crypto/sha256.cpp.i

CMakeFiles/SSLChain.dir/crypto/sha256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/crypto/sha256.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/crypto/sha256.cpp -o CMakeFiles/SSLChain.dir/crypto/sha256.cpp.s

CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o.requires

CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o.provides: CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o.provides

CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o.provides.build: CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o

CMakeFiles/SSLChain.dir/hash.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/hash.cpp.o: ../hash.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/hash.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/hash.cpp.o -c /home/ciaran/ClionProjects/SSLChain/hash.cpp

CMakeFiles/SSLChain.dir/hash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/hash.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/hash.cpp > CMakeFiles/SSLChain.dir/hash.cpp.i

CMakeFiles/SSLChain.dir/hash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/hash.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/hash.cpp -o CMakeFiles/SSLChain.dir/hash.cpp.s

CMakeFiles/SSLChain.dir/hash.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/hash.cpp.o.requires

CMakeFiles/SSLChain.dir/hash.cpp.o.provides: CMakeFiles/SSLChain.dir/hash.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/hash.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/hash.cpp.o.provides

CMakeFiles/SSLChain.dir/hash.cpp.o.provides.build: CMakeFiles/SSLChain.dir/hash.cpp.o

CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o: ../eccryptoverify.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o -c /home/ciaran/ClionProjects/SSLChain/eccryptoverify.cpp

CMakeFiles/SSLChain.dir/eccryptoverify.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/eccryptoverify.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/eccryptoverify.cpp > CMakeFiles/SSLChain.dir/eccryptoverify.cpp.i

CMakeFiles/SSLChain.dir/eccryptoverify.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/eccryptoverify.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/eccryptoverify.cpp -o CMakeFiles/SSLChain.dir/eccryptoverify.cpp.s

CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o.requires

CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o.provides: CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o.provides

CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o.provides.build: CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o

CMakeFiles/SSLChain.dir/uint256.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/uint256.cpp.o: ../uint256.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/uint256.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/uint256.cpp.o -c /home/ciaran/ClionProjects/SSLChain/uint256.cpp

CMakeFiles/SSLChain.dir/uint256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/uint256.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/uint256.cpp > CMakeFiles/SSLChain.dir/uint256.cpp.i

CMakeFiles/SSLChain.dir/uint256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/uint256.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/uint256.cpp -o CMakeFiles/SSLChain.dir/uint256.cpp.s

CMakeFiles/SSLChain.dir/uint256.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/uint256.cpp.o.requires

CMakeFiles/SSLChain.dir/uint256.cpp.o.provides: CMakeFiles/SSLChain.dir/uint256.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/uint256.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/uint256.cpp.o.provides

CMakeFiles/SSLChain.dir/uint256.cpp.o.provides.build: CMakeFiles/SSLChain.dir/uint256.cpp.o

CMakeFiles/SSLChain.dir/main.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/main.cpp.o -c /home/ciaran/ClionProjects/SSLChain/main.cpp

CMakeFiles/SSLChain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/main.cpp > CMakeFiles/SSLChain.dir/main.cpp.i

CMakeFiles/SSLChain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/main.cpp -o CMakeFiles/SSLChain.dir/main.cpp.s

CMakeFiles/SSLChain.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/main.cpp.o.requires

CMakeFiles/SSLChain.dir/main.cpp.o.provides: CMakeFiles/SSLChain.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/main.cpp.o.provides

CMakeFiles/SSLChain.dir/main.cpp.o.provides.build: CMakeFiles/SSLChain.dir/main.cpp.o

CMakeFiles/SSLChain.dir/server.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/server.cpp.o: ../server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/server.cpp.o -c /home/ciaran/ClionProjects/SSLChain/server.cpp

CMakeFiles/SSLChain.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/server.cpp > CMakeFiles/SSLChain.dir/server.cpp.i

CMakeFiles/SSLChain.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/server.cpp -o CMakeFiles/SSLChain.dir/server.cpp.s

CMakeFiles/SSLChain.dir/server.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/server.cpp.o.requires

CMakeFiles/SSLChain.dir/server.cpp.o.provides: CMakeFiles/SSLChain.dir/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/server.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/server.cpp.o.provides

CMakeFiles/SSLChain.dir/server.cpp.o.provides.build: CMakeFiles/SSLChain.dir/server.cpp.o

CMakeFiles/SSLChain.dir/xcert.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/xcert.cpp.o: ../xcert.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/xcert.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/xcert.cpp.o -c /home/ciaran/ClionProjects/SSLChain/xcert.cpp

CMakeFiles/SSLChain.dir/xcert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/xcert.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/xcert.cpp > CMakeFiles/SSLChain.dir/xcert.cpp.i

CMakeFiles/SSLChain.dir/xcert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/xcert.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/xcert.cpp -o CMakeFiles/SSLChain.dir/xcert.cpp.s

CMakeFiles/SSLChain.dir/xcert.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/xcert.cpp.o.requires

CMakeFiles/SSLChain.dir/xcert.cpp.o.provides: CMakeFiles/SSLChain.dir/xcert.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/xcert.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/xcert.cpp.o.provides

CMakeFiles/SSLChain.dir/xcert.cpp.o.provides.build: CMakeFiles/SSLChain.dir/xcert.cpp.o

CMakeFiles/SSLChain.dir/pubkey.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/pubkey.cpp.o: ../pubkey.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/pubkey.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/pubkey.cpp.o -c /home/ciaran/ClionProjects/SSLChain/pubkey.cpp

CMakeFiles/SSLChain.dir/pubkey.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/pubkey.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/pubkey.cpp > CMakeFiles/SSLChain.dir/pubkey.cpp.i

CMakeFiles/SSLChain.dir/pubkey.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/pubkey.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/pubkey.cpp -o CMakeFiles/SSLChain.dir/pubkey.cpp.s

CMakeFiles/SSLChain.dir/pubkey.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/pubkey.cpp.o.requires

CMakeFiles/SSLChain.dir/pubkey.cpp.o.provides: CMakeFiles/SSLChain.dir/pubkey.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/pubkey.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/pubkey.cpp.o.provides

CMakeFiles/SSLChain.dir/pubkey.cpp.o.provides.build: CMakeFiles/SSLChain.dir/pubkey.cpp.o

CMakeFiles/SSLChain.dir/ecwrapper.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/ecwrapper.cpp.o: ../ecwrapper.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/ecwrapper.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/ecwrapper.cpp.o -c /home/ciaran/ClionProjects/SSLChain/ecwrapper.cpp

CMakeFiles/SSLChain.dir/ecwrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/ecwrapper.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/ecwrapper.cpp > CMakeFiles/SSLChain.dir/ecwrapper.cpp.i

CMakeFiles/SSLChain.dir/ecwrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/ecwrapper.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/ecwrapper.cpp -o CMakeFiles/SSLChain.dir/ecwrapper.cpp.s

CMakeFiles/SSLChain.dir/ecwrapper.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/ecwrapper.cpp.o.requires

CMakeFiles/SSLChain.dir/ecwrapper.cpp.o.provides: CMakeFiles/SSLChain.dir/ecwrapper.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/ecwrapper.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/ecwrapper.cpp.o.provides

CMakeFiles/SSLChain.dir/ecwrapper.cpp.o.provides.build: CMakeFiles/SSLChain.dir/ecwrapper.cpp.o

CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o: ../utilstrencodings.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o -c /home/ciaran/ClionProjects/SSLChain/utilstrencodings.cpp

CMakeFiles/SSLChain.dir/utilstrencodings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/utilstrencodings.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/utilstrencodings.cpp > CMakeFiles/SSLChain.dir/utilstrencodings.cpp.i

CMakeFiles/SSLChain.dir/utilstrencodings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/utilstrencodings.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/utilstrencodings.cpp -o CMakeFiles/SSLChain.dir/utilstrencodings.cpp.s

CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o.requires

CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o.provides: CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o.provides

CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o.provides.build: CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o

CMakeFiles/SSLChain.dir/primitives/certs.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/primitives/certs.cpp.o: ../primitives/certs.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/primitives/certs.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/primitives/certs.cpp.o -c /home/ciaran/ClionProjects/SSLChain/primitives/certs.cpp

CMakeFiles/SSLChain.dir/primitives/certs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/primitives/certs.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/primitives/certs.cpp > CMakeFiles/SSLChain.dir/primitives/certs.cpp.i

CMakeFiles/SSLChain.dir/primitives/certs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/primitives/certs.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/primitives/certs.cpp -o CMakeFiles/SSLChain.dir/primitives/certs.cpp.s

CMakeFiles/SSLChain.dir/primitives/certs.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/primitives/certs.cpp.o.requires

CMakeFiles/SSLChain.dir/primitives/certs.cpp.o.provides: CMakeFiles/SSLChain.dir/primitives/certs.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/primitives/certs.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/primitives/certs.cpp.o.provides

CMakeFiles/SSLChain.dir/primitives/certs.cpp.o.provides.build: CMakeFiles/SSLChain.dir/primitives/certs.cpp.o

CMakeFiles/SSLChain.dir/primitives/block.cpp.o: CMakeFiles/SSLChain.dir/flags.make
CMakeFiles/SSLChain.dir/primitives/block.cpp.o: ../primitives/block.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SSLChain.dir/primitives/block.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SSLChain.dir/primitives/block.cpp.o -c /home/ciaran/ClionProjects/SSLChain/primitives/block.cpp

CMakeFiles/SSLChain.dir/primitives/block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSLChain.dir/primitives/block.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ciaran/ClionProjects/SSLChain/primitives/block.cpp > CMakeFiles/SSLChain.dir/primitives/block.cpp.i

CMakeFiles/SSLChain.dir/primitives/block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSLChain.dir/primitives/block.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ciaran/ClionProjects/SSLChain/primitives/block.cpp -o CMakeFiles/SSLChain.dir/primitives/block.cpp.s

CMakeFiles/SSLChain.dir/primitives/block.cpp.o.requires:
.PHONY : CMakeFiles/SSLChain.dir/primitives/block.cpp.o.requires

CMakeFiles/SSLChain.dir/primitives/block.cpp.o.provides: CMakeFiles/SSLChain.dir/primitives/block.cpp.o.requires
	$(MAKE) -f CMakeFiles/SSLChain.dir/build.make CMakeFiles/SSLChain.dir/primitives/block.cpp.o.provides.build
.PHONY : CMakeFiles/SSLChain.dir/primitives/block.cpp.o.provides

CMakeFiles/SSLChain.dir/primitives/block.cpp.o.provides.build: CMakeFiles/SSLChain.dir/primitives/block.cpp.o

# Object files for target SSLChain
SSLChain_OBJECTS = \
"CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o" \
"CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o" \
"CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o" \
"CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o" \
"CMakeFiles/SSLChain.dir/hash.cpp.o" \
"CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o" \
"CMakeFiles/SSLChain.dir/uint256.cpp.o" \
"CMakeFiles/SSLChain.dir/main.cpp.o" \
"CMakeFiles/SSLChain.dir/server.cpp.o" \
"CMakeFiles/SSLChain.dir/xcert.cpp.o" \
"CMakeFiles/SSLChain.dir/pubkey.cpp.o" \
"CMakeFiles/SSLChain.dir/ecwrapper.cpp.o" \
"CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o" \
"CMakeFiles/SSLChain.dir/primitives/certs.cpp.o" \
"CMakeFiles/SSLChain.dir/primitives/block.cpp.o"

# External object files for target SSLChain
SSLChain_EXTERNAL_OBJECTS =

SSLChain: CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/hash.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/uint256.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/main.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/server.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/xcert.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/pubkey.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/ecwrapper.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/primitives/certs.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/primitives/block.cpp.o
SSLChain: CMakeFiles/SSLChain.dir/build.make
SSLChain: /usr/lib/x86_64-linux-gnu/libssl.so
SSLChain: /usr/lib/x86_64-linux-gnu/libcrypto.so
SSLChain: CMakeFiles/SSLChain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable SSLChain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SSLChain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SSLChain.dir/build: SSLChain
.PHONY : CMakeFiles/SSLChain.dir/build

CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/crypto/hmac_sha512.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/crypto/sha512.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/crypto/ripemd160.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/crypto/sha256.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/hash.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/eccryptoverify.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/uint256.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/main.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/server.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/xcert.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/pubkey.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/ecwrapper.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/utilstrencodings.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/primitives/certs.cpp.o.requires
CMakeFiles/SSLChain.dir/requires: CMakeFiles/SSLChain.dir/primitives/block.cpp.o.requires
.PHONY : CMakeFiles/SSLChain.dir/requires

CMakeFiles/SSLChain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SSLChain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SSLChain.dir/clean

CMakeFiles/SSLChain.dir/depend:
	cd /home/ciaran/ClionProjects/SSLChain/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ciaran/ClionProjects/SSLChain /home/ciaran/ClionProjects/SSLChain /home/ciaran/ClionProjects/SSLChain/build /home/ciaran/ClionProjects/SSLChain/build /home/ciaran/ClionProjects/SSLChain/build/CMakeFiles/SSLChain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SSLChain.dir/depend

