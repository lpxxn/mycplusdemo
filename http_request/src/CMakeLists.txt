message(STATUS "PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}")
message(STATUS "PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # 二进制文件的输出目录


#file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
#set(SOURCES ${SOURCES})
#message(STATUS "SOURCES ${SOURCES}")

#if(LINUX)
#    set(EXTERNAL_LIBS ...)
#endif ()
#if (APPLE)
#    set(EXTERNAL_LIBS ...)
#endif()
# target_link_libraries 要在 add_executable 之后，link_libraries 要在 add_executable 之前
#link_libraries(/Users/li/Developer/cplus_workspace/http_request/lib/restclient-cpp/librestclient-cpp.1.dylib)
link_directories(${PROJECT_SOURCE_DIR}/lib/restclient-cpp)
link_directories(${PROJECT_SOURCE_DIR}/lib/yaml-cpp)
link_directories(${PROJECT_SOURCE_DIR}/lib/spdlog)
add_executable(http_request main.cpp utils/log.cpp)

#include_directories(/Users/li/Developer/cplus_workspace/http_request/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

#target_link_libraries(http_request ${PROJECT_SOURCE_DIR}/lib/restclient-cpp/librestclient-cpp.dylib)
# 或者是这样，要把link_directories放到add_executable前面
# 这种是动态的
target_link_libraries(http_request restclient-cpp)
target_link_libraries(http_request yaml-cpp.a)
target_link_libraries(http_request spdlog.a)
## 明确指定动态库
#target_link_libraries(http_request librestclient-cpp.dylib)

# 静态，但这个库有问题
# target_link_libraries(http_request librestclient-cpp.a)

# Find and link library
#指定路径寻找库，比如：在当前目录下寻找libmylib.so动态库。
#find_library(my_lib libmylib.so ./)
#find_library(MYCUSTOMLIB librestclient-cpp.1.dylib ${PROJECT_BINARY_DIR}/bin)
