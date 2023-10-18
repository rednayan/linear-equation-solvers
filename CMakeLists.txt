cmake_minimum_required(VERSION 3.0)
project(Gauss)

add_subdirectory(raylib)
add_executable(gauss main.c)
target_link_libraries(gauss PRIVATE raylib)
