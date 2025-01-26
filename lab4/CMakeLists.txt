cmake_minimum_required(VERSION 3.16)

project(app.exe VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR}/interface)
include_directories(${CMAKE_SOURCE_DIR}/model)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(app.exe
    lift/lift.cpp
    lift/doors.cpp
    lift/cabin.cpp
    lift/controller.cpp
    lift/button.cpp
    interface/mainwindow.cpp
    interface/main.cpp
)
target_include_directories(app.exe PRIVATE ${CMAKE_SOURCE_DIR}/interface)
target_include_directories(app.exe PRIVATE ${CMAKE_SOURCE_DIR}/model)
target_link_libraries(app.exe PRIVATE Qt6::Core)
target_link_libraries(app.exe PRIVATE Qt6::Widgets)
