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
CMAKE_SOURCE_DIR = /home/simteamq/Desktop/SEAL/pcl_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simteamq/Desktop/SEAL/pcl_test/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simteamq/Desktop/SEAL/pcl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /home/simteamq/Desktop/SEAL/pcl_test/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simteamq/Desktop/SEAL/pcl_test/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simteamq/Desktop/SEAL/pcl_test/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

CMakeFiles/main.dir/src/interactive_icp.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/interactive_icp.cpp.o: ../src/interactive_icp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simteamq/Desktop/SEAL/pcl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/interactive_icp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/interactive_icp.cpp.o -c /home/simteamq/Desktop/SEAL/pcl_test/src/interactive_icp.cpp

CMakeFiles/main.dir/src/interactive_icp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/interactive_icp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simteamq/Desktop/SEAL/pcl_test/src/interactive_icp.cpp > CMakeFiles/main.dir/src/interactive_icp.cpp.i

CMakeFiles/main.dir/src/interactive_icp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/interactive_icp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simteamq/Desktop/SEAL/pcl_test/src/interactive_icp.cpp -o CMakeFiles/main.dir/src/interactive_icp.cpp.s

CMakeFiles/main.dir/src/pcl_test.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/pcl_test.cpp.o: ../src/pcl_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simteamq/Desktop/SEAL/pcl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/pcl_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/pcl_test.cpp.o -c /home/simteamq/Desktop/SEAL/pcl_test/src/pcl_test.cpp

CMakeFiles/main.dir/src/pcl_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/pcl_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simteamq/Desktop/SEAL/pcl_test/src/pcl_test.cpp > CMakeFiles/main.dir/src/pcl_test.cpp.i

CMakeFiles/main.dir/src/pcl_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/pcl_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simteamq/Desktop/SEAL/pcl_test/src/pcl_test.cpp -o CMakeFiles/main.dir/src/pcl_test.cpp.s

CMakeFiles/main.dir/src/csv_functions.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/csv_functions.cpp.o: ../src/csv_functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simteamq/Desktop/SEAL/pcl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/csv_functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/csv_functions.cpp.o -c /home/simteamq/Desktop/SEAL/pcl_test/src/csv_functions.cpp

CMakeFiles/main.dir/src/csv_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/csv_functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simteamq/Desktop/SEAL/pcl_test/src/csv_functions.cpp > CMakeFiles/main.dir/src/csv_functions.cpp.i

CMakeFiles/main.dir/src/csv_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/csv_functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simteamq/Desktop/SEAL/pcl_test/src/csv_functions.cpp -o CMakeFiles/main.dir/src/csv_functions.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/src/interactive_icp.cpp.o" \
"CMakeFiles/main.dir/src/pcl_test.cpp.o" \
"CMakeFiles/main.dir/src/csv_functions.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/src/interactive_icp.cpp.o
main: CMakeFiles/main.dir/src/pcl_test.cpp.o
main: CMakeFiles/main.dir/src/csv_functions.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/lib/x86_64-linux-gnu/libpcl_apps.so
main: /usr/lib/x86_64-linux-gnu/libpcl_outofcore.so
main: /usr/lib/x86_64-linux-gnu/libpcl_people.so
main: /usr/lib/x86_64-linux-gnu/libboost_system.so
main: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
main: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
main: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
main: /usr/lib/x86_64-linux-gnu/libboost_regex.so
main: /usr/lib/x86_64-linux-gnu/libqhull.so
main: /usr/lib/libOpenNI.so
main: /usr/lib/libOpenNI2.so
main: /usr/lib/x86_64-linux-gnu/libvtkChartsCore-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkInfovisCore-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libfreetype.so
main: /usr/lib/x86_64-linux-gnu/libz.so
main: /usr/lib/x86_64-linux-gnu/libjpeg.so
main: /usr/lib/x86_64-linux-gnu/libpng.so
main: /usr/lib/x86_64-linux-gnu/libtiff.so
main: /usr/lib/x86_64-linux-gnu/libexpat.so
main: /usr/lib/x86_64-linux-gnu/libvtkIOGeometry-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkIOLegacy-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkIOPLY-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkRenderingLOD-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkViewsContext2D-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkViewsCore-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkRenderingContextOpenGL2-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkRenderingOpenGL2-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libflann_cpp.so
main: /usr/lib/x86_64-linux-gnu/libpcl_surface.so
main: /usr/lib/x86_64-linux-gnu/libpcl_keypoints.so
main: /usr/lib/x86_64-linux-gnu/libpcl_tracking.so
main: /usr/lib/x86_64-linux-gnu/libpcl_recognition.so
main: /usr/lib/x86_64-linux-gnu/libpcl_registration.so
main: /usr/lib/x86_64-linux-gnu/libpcl_stereo.so
main: /usr/lib/x86_64-linux-gnu/libpcl_segmentation.so
main: /usr/lib/x86_64-linux-gnu/libpcl_features.so
main: /usr/lib/x86_64-linux-gnu/libpcl_filters.so
main: /usr/lib/x86_64-linux-gnu/libpcl_sample_consensus.so
main: /usr/lib/x86_64-linux-gnu/libpcl_ml.so
main: /usr/lib/x86_64-linux-gnu/libpcl_visualization.so
main: /usr/lib/x86_64-linux-gnu/libpcl_search.so
main: /usr/lib/x86_64-linux-gnu/libpcl_kdtree.so
main: /usr/lib/x86_64-linux-gnu/libpcl_io.so
main: /usr/lib/x86_64-linux-gnu/libpcl_octree.so
main: /usr/lib/x86_64-linux-gnu/libpcl_common.so
main: /usr/lib/x86_64-linux-gnu/libvtkInteractionWidgets-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkFiltersModeling-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkInteractionStyle-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkFiltersExtraction-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkFiltersStatistics-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkImagingFourier-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkalglib-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkFiltersHybrid-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkImagingGeneral-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkImagingSources-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkImagingHybrid-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkRenderingAnnotation-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkImagingColor-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkRenderingVolume-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkIOXML-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkIOXMLParser-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkIOCore-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkRenderingContext2D-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkRenderingFreeType-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libfreetype.so
main: /usr/lib/x86_64-linux-gnu/libvtkImagingCore-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkRenderingCore-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonColor-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeometry-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkFiltersSources-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeneral-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonComputationalGeometry-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkFiltersCore-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkIOImage-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonExecutionModel-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonDataModel-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonTransforms-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonMisc-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonMath-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonSystem-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkCommonCore-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtksys-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkDICOMParser-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libvtkmetaio-7.1.so.7.1p.1
main: /usr/lib/x86_64-linux-gnu/libz.so
main: /usr/lib/x86_64-linux-gnu/libGLEW.so
main: /usr/lib/x86_64-linux-gnu/libSM.so
main: /usr/lib/x86_64-linux-gnu/libICE.so
main: /usr/lib/x86_64-linux-gnu/libX11.so
main: /usr/lib/x86_64-linux-gnu/libXext.so
main: /usr/lib/x86_64-linux-gnu/libXt.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/simteamq/Desktop/SEAL/pcl_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/simteamq/Desktop/SEAL/pcl_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simteamq/Desktop/SEAL/pcl_test /home/simteamq/Desktop/SEAL/pcl_test /home/simteamq/Desktop/SEAL/pcl_test/build /home/simteamq/Desktop/SEAL/pcl_test/build /home/simteamq/Desktop/SEAL/pcl_test/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

