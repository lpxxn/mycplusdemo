cmake_minimum_required(VERSION 3.8)
# name
project(my_cpp_demo)
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    message(STATUS "11")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    message(STATUS "cx${COMPILER_SUPPORTS_CXX0X}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
add_subdirectory(array_demo1)
add_subdirectory(construction)
add_subdirectory(static_value)
add_subdirectory(string_bad)
add_subdirectory(string_demo)
#add_executable(mycplusdemo
#        array_demo1/demo1/main.cpp
#        array_demo1/demo1/main2.cpp
#        construction/demo1/main.cpp
#        construction/demo1/main2.cpp
#        static_value/demo1/a.cpp
#        static_value/demo1/a.h
#        static_value/demo1/b.cpp
#        static_value/demo1/b.h
#        static_value/demo1/main.cpp
#        string_demo/demo1/main.cpp
#        string_bad/string_bad_1.cpp
#        string_bad/string_bad_1.h
#        string_bad/main.cpp
#        )
