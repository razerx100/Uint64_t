cmake_minimum_required(VERSION 3.21)

project(Uint64_tTest
    LANGUAGES CXX
)

add_executable(
    ${PROJECT_NAME} src/Uint64Test.cxx
)

include(FetchContent)
include(CTest)

# Date : 07-Jan-2024
set(GOOGLE_TEST_COMMIT_ID f8d7d77c06936315286eb55f8de22cd23c188571 CACHE STRING "Supply the latest commit ID from the GitHub repository.")

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/${GOOGLE_TEST_COMMIT_ID}.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

enable_testing()

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /fp:fast /MP /EHa /Ot /W4 /Gy)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Uint64Lib GTest::gtest_main)

add_test(NAME Uint64_t_Test COMMAND ${PROJECT_NAME})
