cmake_minimum_required(VERSION 3.21)
project(Hi_Lo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hi_Lo src/main.cpp src/HiLo.cpp src/HiLo.h src/Card.cpp src/Card.h src/HistoryLogger.cpp src/HistoryLogger.h)
