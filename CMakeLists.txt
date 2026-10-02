cmake_minimum_required(VERSION 3.31)
project(EpsilonMath LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(EpsilonMath ${SOURCE_FILES})
target_include_directories(EpsilonMath PRIVATE src/third_party)
