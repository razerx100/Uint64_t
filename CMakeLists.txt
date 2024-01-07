cmake_minimum_required(VERSION 3.21)

project(Uint64_t
    LANGUAGES CXX
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "-std=c++20")
else()
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(PROJECT_IS_TOP_LEVEL)
    set(ADD_HEADERS_TO_PROJECT TRUE)
endif()

add_subdirectory(library)

if(ADD_TEST)
    add_subdirectory(test)
endif()
