cmake_minimum_required(VERSION 3.13)
project(lab3_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3_1 main.cpp IPlayer.h Field.cpp Field.h GameMechanics.cpp GameMechanics.h ConsolePlayer.cpp ConsolePlayer.h Game.cpp Game.h)