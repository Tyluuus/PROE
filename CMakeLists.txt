cmake_minimum_required(VERSION 3.7)
project(PROE)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Edytor.cpp
        Edytor.h
        Figura.cpp
        Figura.h
        Kolo.cpp
        Kolo.h
        main.cpp
        Obiekt.cpp
        Obiekt.h
        Prostokat.cpp
        Prostokat.h
        Tablica.cpp
        Tablica.h
        Wyjatek.cpp
        Wyjatek.h)

add_executable(PROE ${SOURCE_FILES})