cmake_minimum_required(VERSION 3.0)

project(httpdevelopers)

include_directories(${PROJECT_SOURCE_DIR}/includes)

add_executable(httpdevelopers main.cpp "includes/zen/framework/front.hpp")

install(TARGETS httpdevelopers RUNTIME DESTINATION bin)
