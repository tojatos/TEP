cmake_minimum_required(VERSION 3.5)

project(Lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Lab1)
set(SOURCES
    main.cpp
    )
set(HEADERS
    constants.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
