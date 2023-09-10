import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Page {
    id: root
    title: "Student Locator"
    height: parent.height
    width: parent.width

    property var window

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Column {
        spacing: 20
        anchors.centerIn: parent

        YTextField {
            id: name
            placeholder: "Student Name"
            setFocus: true
            width: 200

            onTextChanged: loadStudents(text)
        }

        ScrollView {
            id: scrollView
            width: 215
            height: 300
            anchors.leftMargin: 15;

            Column {
                id: student_list
                spacing: 5
                anchors.fill: parent

                signal checked(var id);

                onChecked: (id) => {
                    popup.open()
                    var location = window.database.getStudentLocation(id)

                    if (location.length > 5) {
                        popup_reg.text = location[0]
                        popup_grade.text = location[1]
                        popup_timings.text = location[3]
                        popup_name.text = location[2]
                        popup_subject.text = location[4]
                        popup_teacher.text = location[5]
                        popup_location.text = location[6]

                        popup_location.font.pixelSize = 40
                        popup.height = 400
                    } else if (location.length === 5) {
                        popup_reg.text = location[0]
                        popup_grade.text = location[1]
                        popup_timings.text = location[3]
                        popup_name.text = location[2]
                        popup_location.text = location[4]

                        popup_subject.visible = false
                        popup_teacher.visible = false

                        popup_location.font.pixelSize = 40
                        popup.height = 310
                    } else {
                        popup_reg.text = location[0]
                        popup_grade.text = location[1]
                        popup_name.text = location[2]
                        popup_location.text = location[3]

                        popup_subject.visible = false
                        popup_teacher.visible = false
                        popup_timings.visible = false

                        popup_location.font.pixelSize = 28
                        popup.height = 290
                        popup_reg.width = 155
                        popup_grade.width = 155
                    }
                }
            }
        }
    }

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 400
        height: 400
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        property string titleText: "Student"
        property string informationText: ""
        property string location: ""

        Rectangle {
            anchors.fill: parent
            color: "white"

            Text {
                text: popup.titleText
                font.pixelSize: 20
                font.weight: Font.Bold
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 20

                Rectangle {
                    width: parent.width
                    height: 3
                    color: "#047AD0"
                    anchors.bottom: parent.bottom
                }
            }

            Column {
                anchors.top: parent.top
                anchors.topMargin: 80
                anchors.horizontalCenter: parent.horizontalCenter

                spacing: 20

                Row {
                    spacing: 10
                    width: 320
                    anchors.horizontalCenter: parent.horizontalCenter

                    YTextField {
                        id: popup_reg
                        placeholder: "Registration No."
                        enabled: false
                        width: 125
                    }

                    YTextField {
                        id: popup_grade
                        placeholder: "Grade"
                        enabled: false
                        width: 50
                    }

                    YTextField {
                        id: popup_timings
                        width: 125
                        enabled: false
                        placeholder: "Timings"
                    }
                }

                YTextField {
                    id: popup_name
                    placeholder: "Name"
                    width: 320
                    enabled: false
                }

                YTextField {
                    id: popup_subject
                    placeholder: "Subject"
                    width: 320
                    enabled: false
                }

                YTextField {
                    id: popup_teacher
                    placeholder: "Teacher"
                    width: 320
                    enabled: false
                }

                Text {
                    id: popup_location
                    font.pixelSize: 25
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.weight: Font.Bold;
                }
            }

            YButton {
                height: 40
                width: 80
                text: "Close"
                color: "#047AD0"
                textColor: "white"
                font.weight: Font.Medium
                font.pixelSize: 14
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20

                onClicked: popup.close()
            }
        }

        onClosed: {
            popup_reg.visible = true
            popup_grade.visible = true
            popup_timings.visible = true
            popup_name.visible = true
            popup_subject.visible = true
            popup_teacher.visible = true
            popup_location.visible = true

            popup_location.font.pixelSize = 25

            popup_reg.width = 125
            popup_grade.width = 50
            popup_timings.width = 125
        }
    }

    function loadStudents(query) {
        var children = student_list.children.length
        for (var i = 0; i < children; i++) {
            student_list.children[i].destroy();
        }

        var students = window.database.getStudents(query)
        for (var student = 0; student < students.length; student ++) {
            var student_option = Qt.createQmlObject(`
                import QtQuick
                import QtQuick.Controls

                YButton {
                    property int id: ` + students[student] + `

                    text: '` + window.database.getStudent(students[student])[6] + `'
                    width: 200
                    radius: 10

                    onClicked: parent.checked(` + students[student] + `)
                }
                `,
                student_list,
                "yButton"
            );
        }
    }
}
