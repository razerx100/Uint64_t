cmake_minimum_required(VERSION 3.21)

project(Uint64Lib
    LANGUAGES CXX
)

if(ADD_HEADERS_TO_PROJECT)
    file(GLOB_RECURSE Uint64Lib_SRC includes/*.hpp)

    add_library(${PROJECT_NAME} INTERFACE ${Uint64Lib_SRC})
else()
    add_library(${PROJECT_NAME} INTERFACE)
endif()

target_include_directories(${PROJECT_NAME} INTERFACE includes/)
