cmake_minimum_required(VERSION 3.5)

project(Lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Lab3)
set(SOURCES
    main.cpp
    table.cpp
    helper.cpp
    )
set(HEADERS
    constants.h
    table.h
    helper.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
