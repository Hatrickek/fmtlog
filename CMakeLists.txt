cmake_minimum_required(VERSION 3.15)

project(fmtlog CXX)

if(MSVC)
    add_compile_options(/std:c++latest)
endif()

if(NOT MSVC AND NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -O3 -std=c++17)
    #add_compile_options(-Wall -Ofast -std=c++2a -DNDEBUG -march=skylake -flto -fno-exceptions -fno-rtti -fno-unwind-tables -fno-asynchronous-unwind-tables -DFMTLOG_NO_CHECK_LEVEL=1)
    #SET(CMAKE_AR  "gcc-ar")
    #SET(CMAKE_RANLIB  "gcc-ranlib")
    link_libraries(pthread)
endif()

if(NOT TARGET fmt::fmt)
	find_package(fmt CONFIG REQUIRED)
endif()

link_directories(.)

add_library(fmtlog-static fmtlog.cc)
target_link_libraries(fmtlog-static fmt)
install(TARGETS fmtlog-static)

target_include_directories(fmtlog-static PUBLIC .)


