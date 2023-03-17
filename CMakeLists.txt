project(cpp_array)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES sources/*.cpp)
file(GLOB HEADERS headers/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
