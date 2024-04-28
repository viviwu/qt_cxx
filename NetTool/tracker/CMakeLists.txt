
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include(../QtENV.cmake)

include_directories(
    ./
)

add_executable(Server
        tracker.cpp
    connection.h
    connection.cpp
        server.cpp
        server.h
    fwd_def.h
)

target_link_libraries(Server ${REQUIRED_LIBS_QUALIFIED})
