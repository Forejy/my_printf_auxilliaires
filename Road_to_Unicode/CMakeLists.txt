cmake_minimum_required(VERSION 3.9)
project(Road_to_Unicode C)

set(CMAKE_C_STANDARD 90)

add_executable(Road_to_Unicode Sources/main.c Sources/errors.c
        Sources/Functions.c Sources/Convert_base.c Includes/Functions.h Sources/test_functions_with_va_arg.c Includes/test_functions.h Sources/numbers_functions/numbers_functions_octal.c Includes/numbers_functions/numbers_functions_octal.h Sources/create_and_initialize_t_flag.c Includes/create_and_initialize_t_flag.h
        Includes/errors.h)