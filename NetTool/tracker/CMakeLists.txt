
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include(../QtENV.cmake)

include_directories(
    ./
)

add_executable(tracker
    main.cpp
    connection.h
    connection.cpp
    tracker.cpp
    tracker.h
    fwd_def.h
)

target_link_libraries(tracker ${REQUIRED_LIBS_QUALIFIED})
