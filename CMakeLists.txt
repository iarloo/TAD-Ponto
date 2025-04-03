cmake_minimum_required(VERSION 3.30)
project(TAD_Ponto C)

set(CMAKE_C_STANDARD 11)

add_executable(TAD_Ponto main.c
        Ponto.h
        Ponto.c)


target_link_libraries(TAD_Ponto m)