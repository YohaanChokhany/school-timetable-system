import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Page {
    id: root
    title: "View Teacher"
    height: parent.height
    width: parent.width

    property var window

    property var name: name
    property var block1: block1
    property var block2: block2
    property var block3: block3
    property var block4: block4
    property var block5: block5
    property var block6: block6
    property var block7: block7

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Column {
        spacing: 20
        anchors.centerIn: parent
        width: 300

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
                id: block1
                height: 30
                width: parent.width
                text: "Block 1 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10
                enabled: text !== "Block 1 - Free"

                property string id: ""
                onClicked: {
                    if (enabled) {
                        viewBatch(id)
                    }
                }
            }

            YButton {
                id: block2
                height: 30
                width: parent.width
                text: "Block 2 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10
                enabled: text !== "Block 2 - Free"

                property string id: ""
                onClicked: {
                    if (enabled) {
                        viewBatch(id)
                    }
                }
            }

            YButton {
                id: block3
                height: 30
                width: parent.width
                text: "Block 3 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10
                enabled: text !== "Block 3 - Free"

                property string id: ""
                onClicked: {
                    if (enabled) {
                        viewBatch(id)
                    }
                }
            }

            YButton {
                id: block4
                height: 30
                width: parent.width
                text: "Block 4 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10
                enabled: text !== "Block 4 - Free"

                property string id: ""
                onClicked: {
                    if (enabled) {
                        viewBatch(id)
                    }
                }
            }

            YButton {
                id: block5
                height: 30
                width: parent.width
                text: "Block 5 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10
                enabled: text !== "Block 5 - Free"

                property string id: ""
                onClicked: {
                    if (enabled) {
                        viewBatch(id)
                    }
                }
            }

            YButton {
                id: block6
                height: 30
                width: parent.width
                text: "Block 6 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10
                enabled: text !== "Block 6 - Free"

                property string id: ""
                onClicked: {
                    if (enabled) {
                        viewBatch(id)
                    }
                }
            }

            YButton {
                id: block7
                height: 30
                width: parent.width
                text: "Block 7 - "
                horizontalAlignment: Text.AlignLeft
                radius: 10
                enabled: text !== "Block 7 - Free"

                property string id: ""
                onClicked: {
                    if (enabled) {
                        viewBatch(id)
                    }
                }
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
