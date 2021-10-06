CMAKE_MINIMUM_REQUIRED(VERSION 3.4.0)
project(test_rpc)

## Compile as C++11, supported in ROS Kinetic and newer
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

add_compile_options(-DNDEBUG)

add_compile_options(-Wall -Wextra -Wpedantic)


add_definitions(-DNO_LOG)



set(RPC_INCLUDE "${PROJECT_SOURCE_DIR}/rpc-install/include")
set(RPC_LIB_PATH "${PROJECT_SOURCE_DIR}/rpc-install/lib")

include_directories(${RPC_INCLUDE})
link_directories(${RPC_LIB_PATH})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)

list(APPEND SERVER_TEST_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/server_test.cpp
)
add_executable(server_test  ${SERVER_TEST_SRCS})

target_link_libraries(server_test librpc.a)

#install(TARGETS vehicle_model
#        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/bin
#       )

install(TARGETS server_test
        DESTINATION my_bin
       )

######### test client:
list(APPEND CLIENT_TEST_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/client_test.cpp
)
add_executable(client_test   ${CLIENT_TEST_SRCS})

target_link_libraries(client_test librpc.a)

install(TARGETS client_test
        DESTINATION my_bin
       )
