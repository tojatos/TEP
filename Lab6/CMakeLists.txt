cmake_minimum_required(VERSION 3.5)

project(Lab6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Lab6)
set(SOURCES
    main.cpp
    )
set(HEADERS
    nodedynamic.h
    treedynamic.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
