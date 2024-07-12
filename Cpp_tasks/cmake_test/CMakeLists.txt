cmake_minimum_required(VERSION 3.2)
project(CMTesting)

set(SRC_FILES 
    main.cpp
    src/calc.cpp)
message("SRC FILES ARE : ${SRC_FILES}")
add_executable(myExc ${SRC_FILES})
target_include_directories(myExc PUBLIC include/)