cmake_minimum_required(VERSION 3.5)
project(counter-idf LANGUAGES CXX)

add_subdirectory(lib/Catch2)
add_executable(unit_tests)
target_link_libraries(unit_tests
    Catch2::Catch2WithMain
)