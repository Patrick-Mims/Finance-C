cmake_minimum_required(VERSION 3.29)

project(main)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(SRC "src")

# disable warnings
add_definitions(-w)

find_package(json-c CONFIG)

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    ${SRC}/datastructure.c
    ${SRC}/finsftp.c
    ${SRC}/http.c
    ${SRC}/list.c
    ${SRC}/main.c
    ${SRC}/memory.c
    ${SRC}/mysqlconn.c
    ${SRC}/thread.c

    # ${SRC}/parser.c
    # ${SRC}/stack.c
)

target_link_libraries(${PROJECT_NAME}
    -lcurl
    -ljson-c
    -lpthread
    -lssh2
    json-c::json-c
    mysqlclient
)
