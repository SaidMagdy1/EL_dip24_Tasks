cmake_minimum_required(VERSION 3.2)
project(CMTesting)

set(SRC_FILES 
    main.cpp
    src/calc.cpp)
message("SRC FILES ARE : ${SRC_FILES}")

if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
    message(STATUS "file is here ")
else()
    message(FATAL_ERROR "file doesnt exist")
endif()
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_executable(myExc ${SRC_FILES})
target_include_directories(myExc PUBLIC include/ lib/)
target_link_libraries(myExc PUBLIC base_lib)