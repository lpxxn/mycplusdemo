cmake_minimum_required(VERSION 3.17)
#set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_CXX_COMPILER "g++")
project(http_request VERSION 0.0.1)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
check_cxx_compiler_flag(-std=c++17 HAVE_FLAG_STD_CXX17)
if(HAVE_FLAG_STD_CXX17)
    message(STATUS "support 17")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

elseif(COMPILER_SUPPORTS_CXX11)
    message(STATUS "11")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    message(STATUS "cx${COMPILER_SUPPORTS_CXX0X}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

add_subdirectory(src)

# 指定源文件
#set(src_file
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
#        )

# 创建可执行程序项目
#add_executable(http_request ${src_file} )


# 指定头文件路径
#target_include_directories(http_request PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
# 指定lib文件路径
#target_link_libraries(http_request PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# -------------------------------------------------------------------------------------
# 下面开始引入第三方库
# -------------------------------------------------------------------------------------
# set cmake file'dir： to/path/serial_port/cmake/
## -------------------------------------------------------------------------------------
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
#message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
# cpr.camake,
# include(cpr)	# 填写文件名

# 项目中使用 cpr
#target_link_libraries(http_request PRIVATE cpr::cpr)
# -------------------------------------------------------------------------------------
# 简单的则使用 CMake 的 FetchContent 模块下载使用。但这样的缺点是每次重新生成工程时，都需要下载一遍依赖并编译
#
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Include Conan-generated file
#conan_basic_setup(TARGETS) # Introduce Conan-generated targets
#
#target_link_libraries(${PROJECT_NAME} CONAN_PKG::cpr)
