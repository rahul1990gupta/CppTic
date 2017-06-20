cmake_minimum_required(VERSION 3.7)
project(TicCpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/board.cpp
        src/board.h
        src/cell.cpp
        src/cell.h
        src/constant.cpp
        src/constant.h
        src/game.cpp
        src/game.h
        )

add_executable(TicCpp ${SOURCE_FILES})