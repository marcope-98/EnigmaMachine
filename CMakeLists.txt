cmake_minimum_required(VERSION 3.15)
project(Enigma)

set(CMAKE_CXX_STANDARD 14)

add_executable(Enigma main.cpp)
target_include_directories(Enigma PRIVATE include)
target_sources(Enigma PRIVATE
        src/Alphabet.cpp
        src/Rotor.cpp
        src/Reflector.cpp
        src/Machine.cpp
        src/Logger.cpp
        )