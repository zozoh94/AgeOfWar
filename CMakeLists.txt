cmake_minimum_required(VERSION 2.6)
project(ageofwar)

add_executable(ageofwar main.cpp)

install(TARGETS ageofwar RUNTIME DESTINATION bin)
