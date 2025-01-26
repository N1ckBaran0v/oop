cmake_minimum_required(VERSION 3.5)

project(lab3_cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab3_cpp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Geometry/Dot.h Geometry/Dot.cpp
        Geometry/Segment.h Geometry/Segment.cpp
        Geometry/TransformMatrix.h Geometry/TransformMatrix.cpp
        Geometry/Vector.h Geometry/Vector.cpp
        SceneObject/Camera.h SceneObject/Camera.cpp
        SceneObject/Composite.h SceneObject/Composite.cpp
        SceneObject/FrameModel.h SceneObject/FrameModel.cpp
        SceneObject/Invisible.h SceneObject/Invisible.cpp
        SceneObject/SceneObject.h SceneObject/SceneObject.cpp
        SceneObject/Visible.h SceneObject/Visible.cpp
        SceneVisitor/SceneVisitor.h
        Scene/Scene.h Scene/Scene.cpp
        Manager/BaseManager.h
        ManagerVisitor/ManagerVisitor.h
        Manager/SceneManager.h Manager/SceneManager.cpp

        Concepts/Implementation.h
        SceneObjectCreator/SceneObjectCreator.h
        SceneObjectCreator/TemplateSceneObjectCreator.h
        SceneObjectCreator/FrameModelBuilder.h
        SceneObjectCreator/FrameModelLoader.h SceneObjectCreator/FrameModelLoader.cpp
        SceneObjectCreator/FrameModelBaseCreator.h SceneObjectCreator/FrameModelBaseCreator.cpp
        SceneObjectCreator/FrameModelLoadCreator.h SceneObjectCreator/FrameModelLoadCreator.cpp
        SceneObjectCreator/LoadSolution.h SceneObjectCreator/LoadSolution.cpp
        Manager/LoadManager.h Manager/LoadManager.cpp
        Manager/TransformManager.h Manager/TransformManager.cpp
        WindowAdapter/WindowAdapter.h
        WindowAdapter/QtAdapter.h WindowAdapter/QtAdapter.cpp
        SceneVisitor/DrawVisitor.h SceneVisitor/DrawVisitor.cpp
        Manager/DrawManager.h Manager/DrawManager.cpp
        Command/Command.h
        Command/SceneCommand.h
        Command/SceneObjectCommand.h
        Command/DrawSceneCommand.h Command/DrawSceneCommand.cpp
        Command/QtDrawSceneCommand.h Command/QtDrawSceneCommand.cpp
        Command/ClearSceneCommand.h Command/ClearSceneCommand.cpp
        Facade/Facade.h
        Command/MoveCommand.h Command/MoveCommand.cpp
        Command/RotateCommand.h Command/RotateCommand.cpp
        Command/ScaleCommand.h Command/ScaleCommand.cpp
        Command/AddObjectCommand.h Command/AddObjectCommand.cpp
        Command/RemoveObjectCommand.h Command/RemoveObjectCommand.cpp
        Command/AddToCompositeCommand.h Command/AddToCompositeCommand.cpp
        Command/RemoveFromCompositeCommand.h Command/RemoveFromCompositeCommand.cpp
        ManagerCreator/SceneManagerCreator.h
        ManagerCreator/LoadManagerCreator.h
        ManagerCreator/TransformManagerCreator.h
        ManagerCreator/DrawManagerCreator.h
        ManagerCreator/DrawManagerCreator.cpp
        ManagerCreator/LoadManagerCreator.cpp
        ManagerCreator/SceneManagerCreator.cpp
        ManagerCreator/TransformManagerCreator.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET lab3_cpp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(lab3_cpp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(lab3_cpp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(lab3_cpp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab3_cpp)
endif()
set_target_properties(lab3_cpp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab3_cpp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab3_cpp)
endif()
