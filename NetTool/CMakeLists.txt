cmake_minimum_required(VERSION 3.14)

project(nettool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#-DCMAKE_EXPORT_COMPILE_COMMANDS=on
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)


add_subdirectory(tracker)

#add_subdirectory(terminal)


include(GNUInstallDirs)
install(TARGETS Server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
