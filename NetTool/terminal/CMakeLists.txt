
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include(../QtENV.cmake)

include_directories(.)

add_executable(terminal
    terminal.cpp
    terminal.h
    main.cpp
)

target_link_libraries(terminal ${REQUIRED_LIBS_QUALIFIED})
