cmake_minimum_required(VERSION 3.2)
project(CMTesting VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
message("OUR Cpp STANDARD : ${CMAKE_CXX_STANDARD}")
set(SRC_FILES 
    main.cpp
    src/calc.cpp)
message("SRC FILES ARE : ${SRC_FILES}")
message("OUR Generator : ${CMAKE_GENERATOR}")

if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
    message(STATUS "file is here ")
else()
    message(FATAL_ERROR "file doesnt exist")
endif()

if(TARGET base_lib)
    message(STATUS "target is here ")
else()
    message(FATAL_ERROR "file doesnt exist")
endif()

configure_file(defaultConfig.h.in defaultConfig.h)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_executable(myExc ${SRC_FILES})
target_include_directories(myExc PUBLIC include/ lib/)
target_link_libraries(myExc PUBLIC base_lib)