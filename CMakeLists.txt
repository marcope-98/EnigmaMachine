cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(enigma_machine VERSION 0.0.1 LANGUAGES C CXX)

# list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)

# enmach library target
set(ENMACH_LIBRARY_NAME enmach)
add_library(${ENMACH_LIBRARY_NAME}
  INTERFACE
  include/enmach/common.hpp
  include/enmach/types.hpp
  include/enmach/utils.hpp
  include/enmach/EnigmaMachine.hpp
  include/enmach/Reflector.hpp
  include/enmach/Rotor.hpp
)

add_library(${ENMACH_LIBRARY_NAME}::${ENMACH_LIBRARY_NAME} ALIAS ${ENMACH_LIBRARY_NAME})
target_include_directories(${ENMACH_LIBRARY_NAME}
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>

  # PRIVATE
  # ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(${ENMACH_LIBRARY_NAME}
  INTERFACE
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
  -Wall -Wextra -Werror -Wpedantic -Wconversion -O2>
)

# main executable target
add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME}
  PRIVATE
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
  -Wall -Wextra -Werror -Wpedantic -Wconversion -O2>
)

target_link_libraries(${PROJECT_NAME} enmach::enmach)
