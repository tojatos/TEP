cmake_minimum_required(VERSION 3.5)

project(Lab4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Lab4)
set(SOURCES
    main.cpp
    filelasterror.cpp
    filethrowex.cpp
    fileerrcode.cpp
    )
set(HEADERS
    constants.h
    filelasterror.h
    filethrowex.h
    fileerrcode.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
