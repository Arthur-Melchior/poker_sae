cmake_minimum_required(VERSION 4.0)
project(poker)

set(CMAKE_CXX_STANDARD 20)

add_executable(poker main.cpp
        card.h
        combo_finder.h
        card.cpp
        combo_finder.cpp
        player.h
        deck.h
        deck.cpp
)
