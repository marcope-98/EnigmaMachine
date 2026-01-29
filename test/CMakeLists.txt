include(FetchContent)
set(FETCHCONTENT_QUITE FALSE CACHE INTERNAL "")
FetchContent_Declare(
    googletest
    GIT_REPOSITORY    https://github.com/google/googletest.git
    GIT_TAG           v1.17.x
    GIT_PROGRESS      ON
    GIT_SHALLOW       1
)
set(BUILD_GMOCK   OFF CACHE INTERNAL "")
set(INSTALL_GTEST OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(googletest)

add_executable(enigma_machine_tests
  ${CMAKE_CURRENT_SOURCE_DIR}/src/enigma_m4_test.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(enigma_machine_tests gtest)