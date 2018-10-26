cmake_minimum_required(VERSION 3.12)
project(TwoChannelAdapter)

set(CMAKE_CXX_STANDARD 14)

include_directories("/usr/include/tango" "./")

add_executable(TwoChannelAdapter main.cpp
                                 TwoChannelAdapter.cpp
                                 TwoChannelAdapterClass.cpp
                                 TwoChannelAdapterStateMachine.cpp)

target_link_libraries(TwoChannelAdapter tango
                                        log4tango
                                        omniORB4
                                        omniDynamic4
                                        omnithread)