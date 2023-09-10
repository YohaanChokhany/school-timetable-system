import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Page {
    id: root
    title: "Teacher Database"
    height: parent.height
    width: parent.width

    property var window

    background: Rectangle {
        color: "white"
        anchors.fill: parent
    }

    Column {
        height: parent.height - 20
        width: parent.width - 20
        anchors.centerIn: parent
        spacing: 10

        Row {
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20

            Row {
                spacing: 20
                height: parent.height
                anchors.left: parent.left
                anchors.leftMargin: 32

                YTextField {
                    id: search
                    placeholder: "Search"
                    setFocus: true

                    width: 150
                    height: 25
                    anchors.top: parent.top
                    anchors.topMargin: 8

                    onTextChanged: {
                        modelView.list.selected = []
                        modelView.model.list.searchTeachers(text);
                    }
                }
            }

            Row {
                spacing: 10
                anchors.right: parent.right

                YButton {
                    height: 40
                    width: 100
                    text: "+ Add"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14

                    onClicked: {
                        window.stackView.push("AddTeacher.qml")
                        var subjects = window.database.getSubjects()
                        for (var subject = 0; subject < subjects.length; subject ++) {
                            var subject_option = Qt.createQmlObject(`
                                import QtQuick
                                import QtQuick.Controls

                                Row {
                                    spacing: 10

                                    CheckBox {
                                        checked: false

                                        onCheckedChanged: {
                                            if (checked) {
                                                if (parent.parent.selected.indexOf(` + subject + `) == -1)
                                                    parent.parent.selected.push(` + subject + `)
                                            } else {
                                                parent.parent.selected.splice(parent.parent.selected.indexOf(` + subject + `), 1)
                                            }
                                        }
                                    }

                                    Text {
                                        text: '` + subjects[subject] + `'
                                    }
                                }
                                `,
                                window.stackView.children[window.stackView.depth - 1].subjects,
                                "yButton"
                            );
                        }
                        modelView.list.selected = []
                        search.text = ""
                    }
                }

                YButton {
                    id: remove
                    height: 40
                    width: 100
                    text: "⌫ Remove"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14
                    visible: false

                    onClicked: {
                        if (modelView.list.selected.length > 0) {
                            popup.open()
                            if (modelView.list.selected.length > 1) {
                                popup.titleText = "Remove " + modelView.list.selected.length + " Teachers"
                                popup.informationText = "Confirm that you want to delete the chosen " + modelView.list.selected.length + " teachers.\n\nClick 'OK' to continue."
                            } else {
                                popup.titleText = "Remove " + modelView.list.selected.length + " Teacher"
                                popup.informationText = "Confirm that you want to delete the chosen " + modelView.list.selected.length + " teacher.\n\nClick 'OK' to continue."
                            }
                        }
                    }
                }

                YButton {
                    id: edit
                    height: 40
                    width: 100
                    text: "✎ Edit"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14
                    visible: false

                    onClicked: {
                        if (edit.enabled) {
                            var item = modelView.model.list.getTeacher(modelView.list.selected)
                            window.stackView.push("EditTeacher.qml")

                            var teacher_subjects = item[2].split(", ")
                            for (var sub in teacher_subjects) {
                                teacher_subjects[sub] = parseInt(teacher_subjects[sub]);
                            }

                            console.log(teacher_subjects)

                            window.stackView.children[window.stackView.depth - 1].id.text = item[0]
                            window.stackView.children[window.stackView.depth - 1].name.text = item[1]
                            window.stackView.children[window.stackView.depth - 1].subjects.selected = teacher_subjects

                            var subjects = window.database.getSubjects()
                            for (var subject = 0; subject < subjects.length; subject ++) {
                                var subject_option = Qt.createQmlObject(`
                                    import QtQuick
                                    import QtQuick.Controls

                                    Row {
                                        spacing: 10

                                        CheckBox {
                                            checked: ` + (teacher_subjects.includes(subject + 1)) + `

                                            onCheckedChanged: {
                                                console.log(parent.parent.selected.indexOf(` + (subject + 1) + `))
                                                if (checked) {
                                                    if (parent.parent.selected.indexOf(` + (subject + 1) + `) == -1)
                                                        parent.parent.selected.push(` + (subject + 1) + `)
                                                } else {
                                                    parent.parent.selected.splice(parent.parent.selected.indexOf(` + (subject + 1) + `), 1)
                                                }
                                            }
                                        }

                                        Text {
                                            text: '` + subjects[subject] + `'
                                        }
                                    }
                                    `,
                                    window.stackView.children[window.stackView.depth - 1].subjects,
                                    "yButton"
                                );
                            }

                            modelView.list.selected = []
                            search.text = ""

                        }
                    }
                }
            }
        }

        YTeacherView {
            id: modelView
            width: parent.width
            height: parent.height - 50
            anchors.bottom: parent.bottom

            onItemCheckStateChanged: {
                if (modelView.list.selected.length > 0) {
                    remove.visible = true
                } else {
                    remove.visible = false
                }

                if (modelView.list.selected.length == 1) {
                    edit.visible = true
                } else {
                    edit.visible = false
                }
            }

            onViewBatch: (id) => {
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

        Text {
            text: "NO TEACHERS AVAILABLE"
            font.pixelSize: 100
            font.weight: Font.Black
            anchors.centerIn: parent

            visible: modelView.list.count === 0
        }
    }

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 400
        height: 200
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        property string titleText: ""
        property string informationText: ""

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

            Text {
                text: popup.informationText
                width: parent.width - 40
                wrapMode: Text.WordWrap
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 65
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 130
                spacing: 20

                YButton {
                    height: 40
                    width: 80
                    text: "Cancel"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14

                    onClicked: popup.close()
                }

                YButton {
                    height: 40
                    width: 80
                    text: "OK"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14

                    onClicked: {
                        modelView.model.list.removeTeachers(modelView.list.selected)
                        remove.exited()
                        popup.close()
                    }
                }
            }
        }
    }

    function refresh() {
        modelView.model.list.loadTeachers();
    }
}
