cmake_minimum_required(VERSION 3.5)

project(PersonConsole LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(PersonConsole
  main.cpp
  personprinter.cpp
)
target_link_libraries(PersonConsole Qt5::Core)
