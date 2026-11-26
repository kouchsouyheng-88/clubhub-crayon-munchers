cmake_minimum_required(VERSION 3.28)
project(ClubHub VERSION 0.4.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# Reuse 1: GoogleTest (BSD-3-Clause), unit-test framework.
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
# MSVC: link GoogleTest with the same C runtime as our code
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Reuse 2: rapidcsv (BSD-3-Clause), header-only CSV reader.
FetchContent_Declare(rapidcsv
  GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
  GIT_TAG        v9.07
  GIT_SHALLOW    TRUE)

FetchContent_MakeAvailable(googletest rapidcsv)

add_library(clubhub_core
  src/banner.cpp
  src/event.cpp
  src/event_csv.cpp
  src/Student.cpp
  src/ConsoleOutputTest.cpp)
target_include_directories(clubhub_core PUBLIC include)
target_compile_definitions(clubhub_core
  PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}")
target_link_libraries(clubhub_core PUBLIC rapidcsv)

if(MSVC)
  target_compile_options(clubhub_core PRIVATE /W4)
else()
  target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(clubhub src/cli/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)

enable_testing()
include(GoogleTest)

add_executable(csv_smoke_test tests/csv_smoke_test.cpp)
target_link_libraries(csv_smoke_test PRIVATE rapidcsv GTest::gtest_main)
gtest_discover_tests(csv_smoke_test
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(clubhub_tests
  tests/StudentPrivacyTest.cpp
  tests/ConsoleOutputTest.cpp)
target_link_libraries(clubhub_tests PRIVATE clubhub_core GTest::gtest_main)
gtest_discover_tests(clubhub_tests
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})