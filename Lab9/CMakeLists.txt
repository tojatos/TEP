cmake_minimum_required(VERSION 3.5)

project(Lab9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME Lab9)
set(SOURCES
    main.cpp
    mscnproblem.cpp
    random.cpp
    randomsearch.cpp
    modrandomsearch.cpp
    diffevol.cpp
    diffindividual.cpp
    timer.cpp
    randomgreed.cpp
    )
set(HEADERS
    constants.h
    mscnproblem.h
    matrix.h
    table.h
    tablehelper.h
    mysmartpointer.h
    refcounter.h
    streamhelper.h
    matrixhelper.h
    random.h
    randomsearch.h
    modrandomsearch.h
    diffevol.h
    diffindividual.h
    diffhelper.h
    problem.h
    optimizer.h
    timer.h
    randomgreed.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
