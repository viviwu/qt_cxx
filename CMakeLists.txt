cmake_minimum_required(VERSION 3.17)
project(qtcxx)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

add_executable(${PROJECT_NAME} main.cpp my_class.h QTNotificationCenter.cpp QTNotificationCenter.h MyObserver.h)

if("$ENV{PATH}" MATCHES "Qt")
    message("System PATH contains 'Qt'")
    message(STATUS "ENV_PATH:  $ENV{PATH}")
else()
    message("System PATH does not contain 'Qt'")
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.5.1_3/lib/cmake")
endif()

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
