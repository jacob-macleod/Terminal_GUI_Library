cmake_minimum_required(VERSION 3.26)
project(GUI_Framework)

set(CMAKE_CXX_STANDARD 20)

add_executable(GUI_Framework main.cpp
        widgets/character.h
        widgets/screen.h
        screens/mainPage.h
        widgets/string.h)
