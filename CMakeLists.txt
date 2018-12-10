cmake_minimum_required(VERSION 3.12)
project(TwoChannelAdapter)

set(CMAKE_CXX_STANDARD 14)

set(TANGO_INCLUDE_DIR "/usr/include/tango")
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${TANGO_INCLUDE_DIR})

find_library(TANGO_LIB tango)
find_library(OMNIDYNAMIC4_LIB omniDynamic4)
find_library(COS4_LIB COS4)
find_library(OMNIORB4_LIB omniORB4)
find_library(OMNITHREAD_LIB omnithread)
find_library(LOG4TANGO_LIB log4tango)
find_library(ZMQ_LIB zmq)

find_library(LD_LIB ld)
find_library(PTHREAD_LIB pthread)
find_library(STDCPP_LIB stdc++)

add_executable(TwoChannelAdapter    main.cpp
                                    TwoChannelAdapterStateMachine.cpp
                                    TwoChannelAdapterClass.cpp
                                    TwoChannelAdapter.cpp
                                    ClassFactory.cpp)

target_link_libraries(TwoChannelAdapter ${TANGO_LIB}
                                        ${OMNIDYNAMIC4_LIB}
                                        ${COS4_LIB}
                                        ${OMNIORB4_LIB}
                                        ${OMNITHREAD_LIB}
                                        ${LOG4TANGO_LIB}
                                        ${ZMQ_LIB})
