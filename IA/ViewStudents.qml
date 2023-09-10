import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Page {
    id: root
    title: "Student Database"
    height: parent.height
    width: parent.width

    property var window
    property int grade: 11
    property var assignBatches: assignBatches;
    property double progress: 0;
    property double downloadProgress: 0;
    property alias upload_button: upload_button;
    property alias download_pdf_button: pdf_button;

    onProgressChanged: {
        progress_animation.to = root.progress * (loading_container.width - 4)
        progress_animation.start()
        loading_bg_animation.start()

        delay(200, function() {
            if (root.progress == 1) {
                progress.close()
                root.refresh()
                pdf_button.visible = window.database.getGrade(grade)[1] === "1"
            }
        });
    }

    onDownloadProgressChanged: {
        progress_animation.to = root.downloadProgress * (loading_container.width - 4)
        progress_animation.start()
        loading_bg_animation.start()

        delay(200, function() {
            if (root.downloadProgress == 1)
                progress.close()
        });
    }

    NumberAnimation {
        id: progress_animation
        target: progress_rect
        property: "width"
        to: root.progress * loading_container.width
        duration: 100
    }

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
                        modelView.model.list.searchStudents(text);
                    }
                }
            }

            Row {
                spacing: 10
                anchors.right: parent.right

                YButton {
                    id: assignBatches
                    height: 40
                    width: 135
                    text: "Assign Batches"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14
                    visible: false

                    onClicked: {
                        popup.open()
                        popup.height = 220
                        popup.titleText = "Assign Batches"
                        popup.informationText = "Pressing this button will assign all students in this grade to batches and create a timetable.\n\nClick 'OK' to continue."
                        popup.aim = "Assign Batches"
                    }
                }

                YButton {
                    height: 40
                    width: 70
                    text: "+ Add"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14

                    onClicked: {
                        window.stackView.push("AddStudent.qml")
                        window.stackView.children[window.stackView.depth - 1].grade.text = root.grade
                        modelView.list.selected = []
                        search.text = ""
                    }
                }

                YButton {
                    id: upload_button
                    height: 40
                    width: 90
                    text: "⤒ Upload"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14
                    visible: false

                    onClicked: openDialog.open()
                }

                YButton {
                    id: pdf_button
                    height: 40
                    width: 140
                    text: "⤓ Download PDF"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14
                    visible: false

                    onClicked: saveDialog.open()
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
                            popup.height = 200
                            popup.aim = "Remove Students"
                            if (modelView.list.selected.length > 1) {
                                popup.titleText = "Remove " + modelView.list.selected.length + " Students"
                                popup.informationText = "Confirm that you want to delete the chosen " + modelView.list.selected.length + " students.\n\nClick 'OK' to continue."
                            } else {
                                popup.titleText = "Remove " + modelView.list.selected.length + " Student"
                                popup.informationText = "Confirm that you want to delete the chosen " + modelView.list.selected.length + " student.\n\nClick 'OK' to continue."
                            }

                            popup.ok.onClicked = function() {
                                modelView.model.list.removeStudents(modelView.list.selected)
                                remove.exited()
                                popup.close()
                            }
                        }
                    }
                }

                YButton {
                    id: edit
                    height: 40
                    width: 70
                    text: "✎ Edit"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14
                    visible: false

                    onClicked: {
                        if (edit.enabled) {
                            var item = modelView.model.list.getStudent(modelView.list.selected)
                            window.stackView.push("EditStudent.qml")

                            window.stackView.children[window.stackView.depth - 1].reg.text = item[0]
                            window.stackView.children[window.stackView.depth - 1].edu.index = window.stackView.children[window.stackView.depth - 1].edu.model.indexOf(item[1])
                            window.stackView.children[window.stackView.depth - 1].first_name.text = item[2]
                            window.stackView.children[window.stackView.depth - 1].middle_name.text = item[3]
                            window.stackView.children[window.stackView.depth - 1].last_name.text = item[4]
                            window.stackView.children[window.stackView.depth - 1].gender.index = window.stackView.children[window.stackView.depth - 1].gender.model.indexOf(item[5])
                            window.stackView.children[window.stackView.depth - 1].hl1.index = window.stackView.children[window.stackView.depth - 1].hl1.model.indexOf(item[6])
                            window.stackView.children[window.stackView.depth - 1].hl2.index = window.stackView.children[window.stackView.depth - 1].hl2.model.indexOf(item[7])
                            window.stackView.children[window.stackView.depth - 1].hl3.index = window.stackView.children[window.stackView.depth - 1].hl3.model.indexOf(item[8])
                            window.stackView.children[window.stackView.depth - 1].sl1.index = window.stackView.children[window.stackView.depth - 1].sl1.model.indexOf(item[9])
                            window.stackView.children[window.stackView.depth - 1].sl2.index = window.stackView.children[window.stackView.depth - 1].sl2.model.indexOf(item[10])
                            window.stackView.children[window.stackView.depth - 1].sl3.index = window.stackView.children[window.stackView.depth - 1].sl3.model.indexOf(item[11])

                            modelView.list.selected = []
                            search.text = ""
                            edit.exited()
                        }
                    }
                }
            }
        }

        YStudentView {
            id: modelView
            width: parent.width
            height: parent.height - 50
            anchors.bottom: parent.bottom
            grade: root.grade

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
            text: "NO STUDENTS AVAILABLE"
            font.pixelSize: 70
            font.weight: Font.Black
            anchors.centerIn: parent

            visible: modelView.list.count === 0
        }
    }

    Popup {
        id: progress
        anchors.centerIn: parent
        width: 400
        height: 140
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose

        Rectangle {
            anchors.fill: parent
            color: "white"

            Text {
                text: "Loading..."
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

            Rectangle {
                id: loading_container
                width: parent.width - 50
                height: 30
                anchors.top: parent.top
                anchors.topMargin: 70
                anchors.horizontalCenter: parent.horizontalCenter
                border.color: "black"
                border.width: 2

                Rectangle {
                    id: progress_rect
                    height: parent.height - 4
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 2
                    width: 0
                    color: "#047AD0"
                    clip: true


                    Rectangle {
                        width: 150
                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: -150
                        opacity: 0.2
                        gradient: Gradient {
                            orientation: Gradient.Horizontal

                            GradientStop { position: 0.0; color: "#047AD0" }
                            GradientStop { position: 0.5; color: "white" }
                            GradientStop { position: 1.0; color: "#047AD0" }
                        }

                        NumberAnimation on anchors.leftMargin {
                            id: loading_bg_animation
                            running: false
                            from: -150
                            to: loading_container.width
                            duration: 2000
                            loops: Animation.Infinite
                        }
                    }
                }
            }
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
        property string aim: ""

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
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
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
                    id: ok
                    height: 40
                    width: 80
                    text: "OK"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14

                    onClicked: {
                        if (popup.aim == "Remove Students") {
                            modelView.model.list.removeStudents(modelView.list.selected)
                            remove.exited()
                            popup.close()
                        } else if (popup.aim == "Assign Batches") {
                            popup.close()
                            progress.open()
                            progress_rect.width = 0;
                            window.database.assignBatches(root.grade)
                            assignBatches.visible = false
                            upload_button.visible = false
                        }
                    }
                }
            }
        }
    }

    FileDialog {
        id: openDialog
        title: "Please choose a file"
        nameFilters: ["Spreadsheet files (*.csv)"]
        fileMode: FileDialog.OpenFile

        onAccepted: {
            window.database.uploadFile(selectedFile)
            assignBatches.visible = window.database.verifyStudentData(11)
            refresh();
        }
    }

    FileDialog {
        id: saveDialog
        title: "Save File"
        nameFilters: ["Folder (*)"]
        fileMode: FileDialog.SaveFile

        onAccepted: {
            window.database.createTimetable(selectedFile, root.grade);
            progress.open();
            progress_rect.width = 0;
        }
    }

    Timer {
        id: timer
    }

    function refresh() {
        modelView.model.list.loadStudents();
    }

    function delay(delayTime, cb) {
        timer.interval = delayTime;
        timer.repeat = false;
        timer.triggered.connect(cb);
        timer.start();
    }
}
