cmake_minimum_required(VERSION 3.0)

project(httpdevelopers)

add_executable(httpdevelopers main.cpp)

install(TARGETS httpdevelopers RUNTIME DESTINATION bin)
