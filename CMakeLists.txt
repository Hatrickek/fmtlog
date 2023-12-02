cmake_minimum_required(VERSION 3.15)

project(fmtlog CXX)

if(MSVC)
    add_compile_options(/std:c++latest)
endif()

if(UNIX)
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


