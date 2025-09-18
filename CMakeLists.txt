cmake_minimum_required(VERSION 4.0)
project(LogikaAndAlgoritma)

set(SOURCE_CODE
    src/main.cpp
    src/samplelogic.cpp
    src/samplelogic.hpp
)

include_directories(
    src/
)

add_executable(${PROJECT_NAME} ${SOURCE_CODE})