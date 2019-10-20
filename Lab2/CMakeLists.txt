cmake_minimum_required(VERSION 3.5)

project(Lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Lab2)
set(SOURCES
    main.cpp
    table.cpp
    )
set(HEADERS
    constants.h
    table.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
