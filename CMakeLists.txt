cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(candle SHARED
    "candle.cpp"
)

target_include_directories(candle PUBLIC "${PROJECT_SOURCE_DIR}")

add_executable(main "main.cpp")
target_link_libraries(main candle GTest::gtest_main)
