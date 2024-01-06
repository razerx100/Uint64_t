cmake_minimum_required(VERSION 3.21)

project(Uint64_t
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(PROJECT_IS_TOP_LEVEL)
    file(GLOB_RECURSE SRC includes/*.hpp)

    add_library(${PROJECT_NAME} INTERFACE ${SRC})
else()
    add_library(${PROJECT_NAME} INTERFACE)
endif()

target_include_directories(${PROJECT_NAME} INTERFACE includes/)