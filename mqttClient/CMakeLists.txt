cmake_minimum_required(VERSION 3.21)
project(QtWindowsHost)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH C:/Qt/5.14.2/mingw73_64)
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/Sources/Headers
)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)
link_directories(./lib)
add_executable(QtWindowsHost
        Sources/main.cpp
        Sources/mainwindow.cpp Sources/Headers/mainwindow.h Sources/Forms/mainwindow.ui)
target_link_libraries(QtWindowsHost
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
        Qt5Qmqtt
        )

