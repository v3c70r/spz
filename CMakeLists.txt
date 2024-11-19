# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)
project(spz)

if(MSVC)
    add_compile_options(/fp:strict)
else()
    add_compile_options(-ffp-contract=off)
endif()

set(CMAKE_CXX_STANDARD 20)
add_library(spz 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cc/load-spz.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cc/splat-c-types.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cc/splat-types.cc)

add_executable(spz_app ${CMAKE_CURRENT_SOURCE_DIR}/app/main.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/zlib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/cc)

target_link_libraries(spz PRIVATE zlibstatic)
target_link_libraries(spz_app PRIVATE spz)

