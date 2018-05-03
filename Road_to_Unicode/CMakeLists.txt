cmake_minimum_required(VERSION 3.9)
project(Road_to_Unicode C)

set(CMAKE_C_STANDARD 90)

add_executable(Road_to_Unicode Sources/main.c Sources/Functions.c Sources/Convert_base.c Includes/Functions.h)