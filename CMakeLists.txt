cmake_minimum_required(VERSION 3.20)

project(
    huffzip
    VERSION 0.1.0
    DESCRIPTION "C++20 Huffman file compressor and decompressor"
    LANGUAGES CXX
)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)
option(HUFFZIP_BUILD_TESTS "Build the huffzip GoogleTest suite" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(huffzip_enable_warnings target_name)
    target_compile_options(
        ${target_name}
        PRIVATE
            $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
            $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wconversion -Wshadow>
    )
endfunction()

function(huffzip_enable_sanitizers target_name)
    if(NOT ENABLE_SANITIZERS)
        return()
    endif()

    if(MSVC)
        message(WARNING "ENABLE_SANITIZERS is intended for Clang/GCC builds in this project.")
        return()
    endif()

    target_compile_options(${target_name} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(${target_name} PRIVATE -fsanitize=address,undefined)
endfunction()

add_library(
    huffzip_core
    src/bit_reader.cpp
    src/bit_writer.cpp
    src/compressor.cpp
    src/decompressor.cpp
    src/file_format.cpp
    src/frequency_table.cpp
    src/huffman_code.cpp
    src/huffman_tree.cpp
)

target_include_directories(huffzip_core PUBLIC ${PROJECT_SOURCE_DIR}/include)
huffzip_enable_warnings(huffzip_core)
huffzip_enable_sanitizers(huffzip_core)

add_executable(huffzip src/main.cpp)
target_link_libraries(huffzip PRIVATE huffzip_core)
huffzip_enable_warnings(huffzip)
huffzip_enable_sanitizers(huffzip)

include(CTest)

if(BUILD_TESTING AND HUFFZIP_BUILD_TESTS)
    find_package(GTest QUIET)

    if(NOT GTest_FOUND)
        include(FetchContent)
        set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
        FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
        )
        FetchContent_MakeAvailable(googletest)
    endif()

    add_executable(
        huffzip_tests
        tests/test_bit_reader.cpp
        tests/test_bit_writer.cpp
        tests/test_frequency_table.cpp
        tests/test_huffman_tree.cpp
        tests/test_malformed.cpp
        tests/test_roundtrip.cpp
        tests/test_main.cpp
    )

    target_link_libraries(huffzip_tests PRIVATE huffzip_core GTest::gtest)
    huffzip_enable_warnings(huffzip_tests)
    huffzip_enable_sanitizers(huffzip_tests)

    include(GoogleTest)
    gtest_discover_tests(huffzip_tests)
endif()
