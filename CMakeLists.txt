cmake_minimum_required(VERSION 3.0)
project(ADA)

set(CMAKE_CXX_STANDARD 11)

add_executable(ADA Grafo.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(ADA sfml-graphics sfml-audio)