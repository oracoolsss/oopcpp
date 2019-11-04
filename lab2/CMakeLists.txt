cmake_minimum_required(VERSION 3.13)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp worker.h readfile.cpp readfile.h writefile.cpp writefile.h replace.cpp replace.h)