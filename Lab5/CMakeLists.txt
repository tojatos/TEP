cmake_minimum_required(VERSION 3.5)

project(Lab5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Lab5)
set(SOURCES
    main.cpp
    nodestatic.cpp
    )
set(HEADERS
    constants.h
    nodestatic.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
