import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Page {
    id: root
    title: "View Student"
    height: parent.height
    width: parent.width

    property var window
    property var reg: reg
    property var edu: edu
    property var gender: gender
    property var name: name
    property var hl1: hl1
    property var hl2: hl2
    property var hl3: hl3
    property var sl1: sl1
    property var sl2: sl2
    property var sl3: sl3
    property var tok: tok

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
                id: reg
                placeholder: "Registration No."
                enabled: false
                width: 90
            }

            YTextField {
                id: edu
                placeholder: "Education"
                enabled: false
                width: 90
            }

            YTextField {
                id: gender
                placeholder: "Gender"
                enabled: false
                width: 90
            }
        }

        YTextField {
            id: name
            placeholder: "Name"
            enabled: false
            width: 300
        }

        Column {
            width: parent.width
            spacing: 5

            YButton {
                id: hl1
                height: 30
                width: parent.width
                text: "Block 1 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10

                property string id: ""
                onClicked: viewBatch(id)
            }

            YButton {
                id: hl2
                height: 30
                width: parent.width
                text: "Block 2 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10

                property string id: ""
                onClicked: viewBatch(id)
            }

            YButton {
                id: hl3
                height: 30
                width: parent.width
                text: "Block 3 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10

                property string id: ""
                onClicked: viewBatch(id)
            }

            YButton {
                id: sl1
                height: 30
                width: parent.width
                text: "Block 4 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10

                property string id: ""
                onClicked: viewBatch(id)
            }

            YButton {
                id: sl2
                height: 30
                width: parent.width
                text: "Block 5 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10

                property string id: ""
                onClicked: viewBatch(id)
            }

            YButton {
                id: sl3
                height: 30
                width: parent.width
                text: "Block 6 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10

                property string id: ""
                onClicked: viewBatch(id)
            }

            YButton {
                id: tok
                height: 30
                width: parent.width
                text: "Block 7 - Theory of Knowledge"
                horizontalAlignment: Text.AlignLeft
                radius: 10

                property string id: ""
                onClicked: viewBatch(id)
            }
        }
    }

    function viewBatch(id) {
        window.stackView.push("ViewSingleBatch.qml");
        var batch = window.database.getBatch(id);
        window.stackView.children[window.stackView.depth - 1].subject.text = batch[1];
        window.stackView.children[window.stackView.depth - 1].level.text = batch[2];
        window.stackView.children[window.stackView.depth - 1].block.text = batch[3];
        window.stackView.children[window.stackView.depth - 1].teacher.text += window.database.getTeacher(batch[4])[1];
        window.stackView.children[window.stackView.depth - 1].teacher.id = batch[4];
        window.stackView.children[window.stackView.depth - 1].grade.text = batch[5];
        var students = batch[6].split(", ");
        for (var student = 0; student < students.length; student++) {
            var student_option = Qt.createQmlObject(`
                import QtQuick
                import QtQuick.Controls

                YButton {
                    text: "` + window.database.getStudent(students[student])[6] + `";
                    height: 30;
                    width: parent.width - 5
                    radius: 10

                    onClicked: parent.viewStudent(` + students[student] + `)
                }
                `,
                window.stackView.children[window.stackView.depth - 1].students,
                "yButton"
            )
        }
    }
}
