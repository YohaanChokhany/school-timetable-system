import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Page {
    id: root
    title: "Add Teacher"
    height: parent.height
    width: parent.width

    property var window
    property var subjects: subjectsList

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
            setFocus: true
            width: 300
        }

        ScrollView {
            id: subjects
            height: 300
            width: parent.width
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            contentWidth: availableWidth

            Column {
                id: subjectsList
                spacing: 10
                width: parent.width

                property var selected: []
            }
        }

        YButton {
            height: 40
            width: 100
            text: "Add"
            color: "#047AD0"
            textColor: "white"
            font.weight: Font.Medium
            font.pixelSize: 14
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                var res = window.database.addTeacher(name.text, subjectsList.selected)
                if (res === "SUCCESS") {
                    window.stackView.pop()
                    window.stackView.children[window.stackView.depth - 1].refresh()
                } else {
                    popup.open()
                    popup.titleText = res
                    if (res === "INCOMPLETE")
                        popup.informationText = "All input fields of the form have not been completed. \n\nPlease click 'Add' once this has been completed."
                    if (res === "INVALID ID")
                        popup.informationText = "Chosen ID already exists. Please choose a new ID. \n\nPlease click 'Add' once this has been completed."
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

            property string titleText: "ERROR"
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
                    width: parent.width - 50
                    wrapMode: Text.WordWrap
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 65
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
                    anchors.top: parent.top
                    anchors.topMargin: 130

                    onClicked: popup.close()
                }
            }
        }
    }
}
