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
                spacing: 20
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
                        window.stackView.push("AddStudent.qml")
                        window.stackView.children[window.stackView.depth - 1].grade.text = root.grade
                        modelView.list.selected = []
                        search.text = ""
                    }
                }

                YButton {
                    height: 40
                    width: 100
                    text: "⤒ Upload"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14

                    onClicked: openDialog.open()
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
                                popup.titleText = "Remove " + modelView.list.selected.length + " Students"
                                popup.informationText = "Confirm that you want to delete the chosen " + modelView.list.selected.length + " students.\n\nClick 'OK' to continue."
                            } else {
                                popup.titleText = "Remove " + modelView.list.selected.length + " Student"
                                popup.informationText = "Confirm that you want to delete the chosen " + modelView.list.selected.length + " student.\n\nClick 'OK' to continue."
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
                        modelView.model.list.removeStudents(modelView.list.selected)
                        remove.exited()
                        popup.close()
                    }
                }
            }
        }
    }

    FileDialog {
        id: openDialog
        title: "Please choose a file"
        nameFilters: ["Spreadsheet files (*.csv)"]

        onAccepted: {
            window.database.uploadFile(selectedFile)
            refresh();
        }
    }

    function refresh() {
        modelView.model.list.loadStudents();
    }
}
