import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Page {
    id: root
    title: "Subject Database"
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
                        modelView.model.list.searchSubjects(text);
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
                        modelView.list.selected = []
                        search.text = ""
                        window.stackView.push("AddSubject.qml")
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
                                popup.titleText = "Remove " + modelView.list.selected.length + " Subjects"
                                popup.informationText = "Confirm that you want to delete the chosen " + modelView.list.selected.length + " subjects.\n\nClick 'OK' to continue."
                            } else {
                                popup.titleText = "Remove " + modelView.list.selected.length + " Subject"
                                popup.informationText = "Confirm that you want to delete the chosen " + modelView.list.selected.length + " subject.\n\nClick 'OK' to continue."
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
                            var item = modelView.model.list.getSubject(modelView.list.selected)
                            window.stackView.push("EditSubject.qml")

                            window.stackView.children[window.stackView.depth - 1].id.text = item[0]
                            window.stackView.children[window.stackView.depth - 1].name.text = item[1]

                            modelView.list.selected = []
                            search.text = ""
                        }
                    }
                }
            }
        }

        YSubjectView {
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
        }

        Text {
            text: "NO SUBJECTS AVAILABLE"
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
                        modelView.model.list.removeSubjects(modelView.list.selected)
                        remove.exited()
                        popup.close()
                    }
                }
            }
        }
    }

    function refresh() {
        modelView.model.list.loadSubjects();
    }
}
