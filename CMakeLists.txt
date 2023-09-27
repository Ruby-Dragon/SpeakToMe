cmake_minimum_required(VERSION 3.27)
project(speaktome C)

set(CMAKE_C_STANDARD 17)

add_executable(speaktome main.c
        GameState.c
        GameState.h)
