project(yaml_demo)
message(STATUS "PROJECT_NAME ${PROJECT_NAME}")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # 二进制文件的输出目录

link_directories(${PROJECT_SOURCE_DIR}/lib/yaml-cpp)
add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} yaml-cpp.a)
