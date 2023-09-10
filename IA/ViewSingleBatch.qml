import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Page {
    id: root
    title: "View Batch"
    height: parent.height
    width: parent.width

    property var window
    property var subject: subject
    property var level: level
    property var block: block
    property var grade: grade
    property var teacher: teacher
    property var students: studentsList

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Column {
        spacing: 20
        anchors.centerIn: parent
        width: 300

        Row {
            spacing: 10

            YTextField {
                id: subject
                placeholder: "Subject"
                enabled: false
                width: 200
            }

            YTextField {
                id: level
                placeholder: "Level"
                enabled: false
                width: 90
            }
        }

        Row {
            spacing: 10


            YTextField {
                id: block
                placeholder: "Block"
                enabled: false
                width: 145
            }

            YTextField {
                id: grade
                placeholder: "Grade"
                enabled: false
                width: 145
            }
        }

        YButton {
            id: teacher
            width: 300
            text: "Teacher - "
            radius: 5

            property int id;

            onClicked: {
                window.stackView.push("ViewSingleTeacher.qml")
                var teacher = window.database.getTeacher(id)

                window.stackView.children[window.stackView.depth - 1].name.text = teacher[1];
                window.stackView.children[window.stackView.depth - 1].block1.text += window.database.getBatch(teacher[3])[1] === "" ? "Free" : window.database.getBatch(teacher[3])[1] + " " + window.database.getBatch(teacher[3])[2];
                window.stackView.children[window.stackView.depth - 1].block2.text += window.database.getBatch(teacher[4])[1] === "" ? "Free" : window.database.getBatch(teacher[4])[1] + " " + window.database.getBatch(teacher[4])[2];
                window.stackView.children[window.stackView.depth - 1].block3.text += window.database.getBatch(teacher[5])[1] === "" ? "Free" : window.database.getBatch(teacher[5])[1] + " " + window.database.getBatch(teacher[5])[2];
                window.stackView.children[window.stackView.depth - 1].block4.text += window.database.getBatch(teacher[6])[1] === "" ? "Free" : window.database.getBatch(teacher[6])[1] + " " + window.database.getBatch(teacher[6])[2];
                window.stackView.children[window.stackView.depth - 1].block5.text += window.database.getBatch(teacher[7])[1] === "" ? "Free" : window.database.getBatch(teacher[7])[1] + " " + window.database.getBatch(teacher[7])[2];
                window.stackView.children[window.stackView.depth - 1].block6.text += window.database.getBatch(teacher[8])[1] === "" ? "Free" : window.database.getBatch(teacher[8])[1] + " " + window.database.getBatch(teacher[8])[2];
                window.stackView.children[window.stackView.depth - 1].block7.text += window.database.getBatch(teacher[9])[1] === "" ? "Free" : window.database.getBatch(teacher[9])[1] + " " + window.database.getBatch(teacher[9])[2];
                window.stackView.children[window.stackView.depth - 1].block1.id += teacher[3];
                window.stackView.children[window.stackView.depth - 1].block2.id += teacher[4];
                window.stackView.children[window.stackView.depth - 1].block3.id += teacher[5];
                window.stackView.children[window.stackView.depth - 1].block4.id += teacher[6];
                window.stackView.children[window.stackView.depth - 1].block5.id += teacher[7];
                window.stackView.children[window.stackView.depth - 1].block6.id += teacher[8];
                window.stackView.children[window.stackView.depth - 1].block7.id += teacher[9];
            }
        }

        ScrollView {
            id: students
            height: 300
            width: parent.width
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            contentWidth: availableWidth

            Column {
                id: studentsList
                spacing: 5
                width: parent.width

                signal viewStudent(int id)

                onViewStudent: (id) => {
                    window.stackView.push("ViewSingleStudent.qml");
                    var student = window.database.getStudent(id);

                    window.stackView.children[window.stackView.depth - 1].reg.text = student[0]
                    window.stackView.children[window.stackView.depth - 1].edu.text = student[1]
                    window.stackView.children[window.stackView.depth - 1].name.text = student[6]
                    window.stackView.children[window.stackView.depth - 1].gender.text = student[5] === "M" ? "Male" : "Female"
                    window.stackView.children[window.stackView.depth - 1].hl1.text += window.database.getSubject(student[8])[2] + " HL";
                    window.stackView.children[window.stackView.depth - 1].hl2.text += window.database.getSubject(student[9])[2] + " HL";
                    window.stackView.children[window.stackView.depth - 1].hl3.text += window.database.getSubject(student[10])[2] + " HL";
                    window.stackView.children[window.stackView.depth - 1].sl1.text += window.database.getSubject(student[11])[2] + " SL";
                    window.stackView.children[window.stackView.depth - 1].sl2.text += window.database.getSubject(student[12])[2] + " SL";
                    window.stackView.children[window.stackView.depth - 1].sl3.text += window.database.getSubject(student[13])[2] + " SL";
                    window.stackView.children[window.stackView.depth - 1].hl1.id = student[14]
                    window.stackView.children[window.stackView.depth - 1].hl2.id = student[15]
                    window.stackView.children[window.stackView.depth - 1].hl3.id = student[16]
                    window.stackView.children[window.stackView.depth - 1].sl1.id = student[17]
                    window.stackView.children[window.stackView.depth - 1].sl2.id = student[18]
                    window.stackView.children[window.stackView.depth - 1].sl3.id = student[19]
                    window.stackView.children[window.stackView.depth - 1].tok.id = student[20]
                };
            }
        }
    }
}
