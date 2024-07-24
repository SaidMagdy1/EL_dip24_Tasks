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


configure_file(defaultConfig.h.in defaultConfig.h)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_executable(myExc ${SRC_FILES})
target_include_directories(myExc PUBLIC include/ lib/ build/)
target_link_libraries(myExc PUBLIC base_lib)


if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
    message(STATUS "file is here ")
else()
    message(FATAL_ERROR "file doesnt exist")
endif()


if(TARGET base_lib)
    message(STATUS "target is here ")
else()
    message(FATAL_ERROR "target doesnt exist")
endif()

if(DEBUG)
    message(DEBUGINFO " : author is Saeed Magdy")
endif()

set(VAR 5)
set(myVAR 10 CACHE STRING "our string")  # this also can be donr by option(myVar "comment" value)
while(VAR)
    message("VAR = ${VAR}")
    math(EXPR VAR "${VAR} - 1")
endwhile()
#after While Var become 0

function(countDown arg1)  #U parse it like ptr take it in the first time as it is so double ${} look like derefrencing
    message("arg = ${arg1}")
    message("arg_value = ${${arg1}}")
endfunction(countDown arg1)

countDown(VAR)

