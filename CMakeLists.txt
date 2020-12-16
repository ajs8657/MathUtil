# CMakeList.txt: CMake project

# Minimum CMake Version
cmake_minimum_required (VERSION 3.8)

# Project Name
project("MathUtil")

# Create a list of source files
set(SRC_DIR "src")
file(GLOB_RECURSE SRC "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.h")

# Add the source files to this project's binary
add_library(${PROJECT_NAME} ${SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Make sure the compiler can find include files for our library
# when other libraries or executables link to this one
target_include_directories(${PROJECT_NAME} PUBLIC ${SRC_DIR})
