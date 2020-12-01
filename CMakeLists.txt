# CMakeList.txt: CMake project
# include source and define project specific logic here

# Minimum CMake Version
cmake_minimum_required (VERSION 3.8)

# Project Name
project ("MathUtil")

# Create a list of source files
set(SRC_DIR "src")
file(GLOB_RECURSE SRC "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.h")

# Add the source files to this project's binary
add_library(MathUtil ${SRC})

# Make sure the compiler can find include files for our library
# when other libraries or executables link to Hello
target_include_directories (MathUtil PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
