cmake_minimum_required(VERSION 3.10)  # 最低CMake版本要求
project(CMakeDemo)                    # 项目名称

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)

# 添加头文件路径
include_directories(include)

# 将src目录下的所有源文件加入项目
file(GLOB SOURCES "src/*.cpp")

# 创建可执行文件
add_executable(CMakeDemo ${SOURCES})
