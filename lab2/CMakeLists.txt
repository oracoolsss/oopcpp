cmake_minimum_required(VERSION 3.13)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp actions/worker.h actions/readfile.cpp actions/readfile.h actions/writefile.cpp actions/writefile.h actions/replace.cpp actions/replace.h actions/sort.cpp actions/sort.h actions/grep.cpp actions/grep.h actions/workWithString.cpp actions/workWithString.h parser.cpp parser.h actionFactory.cpp actionFactory.h workFlow.cpp workFlow.h IActionMaker.h ActionMaker.h)