cmake_minimum_required(VERSION 4.0)
project(LogikaAndAlgoritma)

set(SOURCE_CODE
    src/main.cpp
    src/samplelogic.cpp
    src/samplelogic.hpp
)

set(ALGORITMABENSIN
    src/algoritmabensin.cpp
    src/algoritmabensin.hpp
)

include_directories(
    src/
)

add_executable(${PROJECT_NAME} ${SOURCE_CODE})

add_executable(AlgoritmaBensin ${ALGORITMABENSIN})