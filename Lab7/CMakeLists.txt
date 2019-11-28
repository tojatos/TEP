cmake_minimum_required(VERSION 3.5)

project(Lab7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Lab7)
set(SOURCES
    main.cpp
    )
set(HEADERS
    constants.h
    mysmartpointer.h
    refcounter.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
