# CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(clubhub VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library: all code except main(); later labs link tests to it
add_library(clubhub_core src/banner.cpp src/event.cpp src/event_csv.cpp src/Student.cpp src/ConsoleOutputTest.cpp)
target_include_directories(clubhub_core PUBLIC include)
target_compile_definitions(clubhub_core
    PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}")
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Executable: the command-line front end
add_executable(clubhub src/cli/main.cpp)
target_include_directories(clubhub PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(clubhub PRIVATE clubhub_core)

# Tests (GoogleTest is downloaded by CMake)
include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip)
# Windows/MSVC: use the same runtime library as the project
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(clubhub_tests
    tests/StudentPrivacyTest.cpp
    tests/ConsoleOutputTest.cpp)
target_link_libraries(clubhub_tests PRIVATE clubhub_core GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(clubhub_tests)
