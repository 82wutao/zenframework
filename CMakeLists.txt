cmake_minimum_required(VERSION 3.0)

project(httpdevelopers)

include_directories(${PROJECT_SOURCE_DIR}/includes)

add_executable(httpdevelopers main.cpp)

install(TARGETS httpdevelopers RUNTIME DESTINATION bin)
