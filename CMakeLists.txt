cmake_minimum_required(VERSION 3.12)
project(pet)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(server
    server/src/server.cpp
    server/src/session.cpp
    server/main.cpp
)

target_include_directories(server PRIVATE server/include)
target_link_libraries(server ${Boost_LIBRARIES})

add_executable(client
    # client/main.cpp
    client/src/client.cpp
)

target_include_directories(client PRIVATE client/include)
target_link_libraries(client ${Boost_LIBRARIES})
