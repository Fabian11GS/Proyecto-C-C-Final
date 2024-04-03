cmake_minimum_required(VERSION 3.27.8)  # CMake version check
project(Wifi)               # Create project "Wifi"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of the project root directory as a source file
set(
        SOURCE_FILES main.cpp
        equipo.cpp
        equipo.h
        propietario.h
        propietario.cpp
        gestorEquipos.h
        gestorEquipos.cpp
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(simple_example ${SOURCE_FILES})