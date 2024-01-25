# CMakeLists.txt

# Check if the build directory is the same as the source directory
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds are not allowed. Please create a build directory and run CMake from there.")
endif()

# Set a default build type if not provided by the user
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
endif()

cmake_minimum_required(VERSION 3.16...3.22)

set (PROJECT_NAME testing)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C)

set (SOURCES 
    src/main.c
    src/adt_list.c)

add_executable(${PROJECT_NAME} ${SOURCES})