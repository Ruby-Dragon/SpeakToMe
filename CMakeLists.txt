cmake_minimum_required(VERSION 3.27)
project(SpeakToMe)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpeakToMe
        main.cpp
        AI.cpp
        AI.h
        Dialogue.cpp
        Dialogue.h)
