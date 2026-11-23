make_minimum_required(VERSION 3.14)
project(gui VERSION 1.0 LANGUAGES CXX)


add_library(Gui STATIC
    src/Gui.cpp
	src/Gui.h
)

add_executabe(Test main.cpp)