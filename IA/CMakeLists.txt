cmake_minimum_required(VERSION 3.16)

project(IA VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick Sql Concurrent PrintSupport)

qt_add_executable(appIA
    main.cpp
    database.h database.cpp
    studentmodel.h studentmodel.cpp
    studentlist.h studentlist.cpp
    teachermodel.h teachermodel.cpp
    teacherlist.h teacherlist.cpp
    subjectmodel.h subjectmodel.cpp
    subjectlist.h subjectlist.cpp
    global.h global.cpp
)

qt_add_qml_module(appIA
    URI IA
    VERSION 1.0
    QML_FILES main.qml Login.qml MainMenu.qml SettingsMenu.qml AddUser.qml ViewStudents.qml ViewTeachers.qml ViewSubjects.qml AddStudent.qml EditStudent.qml AddTeacher.qml EditTeacher.qml AddSubject.qml EditSubject.qml YTextField.qml YButton.qml YCheckBox.qml YStudentView.qml YTeacherView.qml YSubjectView.qml YComboBox.qml ViewSingleBatch.qml ViewSingleStudent.qml ViewSingleTeacher.qml StudentLocator.qml
)

set_target_properties(appIA PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appIA
    PRIVATE Qt6::Quick Qt6::Sql Qt6::Concurrent Qt6::PrintSupport)

install(TARGETS appIA
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
