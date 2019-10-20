cmake_minimum_required(VERSION 3.5)

project(Labytest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Labytest)
set(SOURCES
    main.cpp
    )
set(HEADERS
    constants.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
