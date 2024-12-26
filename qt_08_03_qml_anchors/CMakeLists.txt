cmake_minimum_required(VERSION 3.16)

project(qt_08_03_qml_anchors VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

set(CMAKE_AUTORCC ON)
qt_add_executable(appqt_08_03_qml_anchors
    main.cpp
)

qt_add_qml_module(appqt_08_03_qml_anchors
    URI qt_08_03_qml_anchors
    VERSION 1.0
    QML_FILES
        Main.qml
        RESOURCES res.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appqt_08_03_qml_anchors PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appqt_08_03_qml_anchors
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqt_08_03_qml_anchors
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appqt_08_03_qml_anchors
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
