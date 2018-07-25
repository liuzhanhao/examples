project(jasper)
cmake_minimum_required(VERSION 3.0.2)

# CMake Options
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -w")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")
endif()

find_package(Threads)

# External Dependencies
include(cmake/modules/glog.cmake)
include(cmake/modules/gflags.cmake)
include(cmake/modules/gtest.cmake)
include(cmake/modules/zeromq.cmake)

# External Includes
set(JASPER_EXTERNAL_INCLUDE ${GLOG_INCLUDE_DIR} ${GFLAGS_INCLUDE_DIR} ${ZMQ_INCLUDE_DIR})

# External Libraries
set(JASPER_EXTERNAL_LIB ${GLOG_LIBRARY} ${GFLAGS_LIBRARY} ${ZMQ_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})

add_subdirectory(src)
add_subdirectory(test)
