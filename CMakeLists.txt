cmake_minimum_required(VERSION 3.22)
project(CppSnippetsRepo)

# Set C++ standard globally
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Get all subdirectories
file(GLOB children RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)

set(EXCLUDED_DIRS "build" "testing-utils" ".git" ".github")

foreach(child ${children})
    if( IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${child}
        AND EXISTS ${CMAKE_SOURCE_DIR}/${child}/CMakeLists.txt
        AND NOT child IN_LIST EXCLUDED_DIRS)
        message(STATUS "Adding subdirectory: ${child}")
        add_subdirectory(${child})
    endif()
endforeach()