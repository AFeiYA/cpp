cmake_minimum_required(VERSION 3.16)
project(QtFbx LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
)

qt_add_executable(QtFbx ${PROJECT_SOURCES})

target_link_libraries(QtFbx
    PUBLIC
        Qt::Core
)
