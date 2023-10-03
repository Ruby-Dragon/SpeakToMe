cmake_minimum_required(VERSION 3.27)
project(SpeakToMe)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(SpeakToMe
        main.cpp
        AI.cpp
        AI.h
        Dialogue.cpp
        Dialogue.h
        Answer.cpp
        Answer.h)

target_link_libraries(SpeakToMe ${CURSES_LIBRARIES})

add_custom_command(TARGET SpeakToMe POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/Dialogue
        ${PROJECT_BINARY_DIR}/Dialogue
        COMMENT "Copying Dialogue Files"
)