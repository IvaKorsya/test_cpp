cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

add_library(candle SHARED
    "candle.cpp"
)

target_include_directories(candle PUBLIC "${PROJECT_SOURCE_DIR}")

add_executable(main "main.cpp")
target_link_libraries(main candle)
