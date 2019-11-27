cmake_minimum_required(VERSION 3.13)
project(testlab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(testlab2 main.cpp IActionMaker.h actions/IWorker.h actions/Grep.cpp actions/Grep.h ActionMaker.h ActionFactory.cpp ActionFactory.h actions/WorkWithString.cpp actions/WorkWithString.h actions/ReadFile.cpp actions/ReadFile.h actions/Replace.cpp actions/Replace.h actions/Sort.cpp actions/Sort.h actions/WriteFile.cpp actions/WriteFile.h Parser.cpp Parser.h WorkFlow.cpp WorkFlow.h actions/Dump.cpp actions/Dump.h)