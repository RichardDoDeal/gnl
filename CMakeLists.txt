cmake_minimum_required(VERSION 3.12)
project(get_next_line C)

set(CMAKE_C_STANDARD 99)

include_directories(~/.brew/include)

add_executable(get_next_line
        src/get_next_line.c
        src/get_next_line_utils.c
        main.c)