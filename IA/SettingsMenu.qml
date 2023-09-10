import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Page {
    id: root
    title: "Settings"
    height: parent.height
    width: parent.width

    property var window
    property alias refresh_new_year: refresh_new_year

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Column {
        width: 300
        spacing: 10
        anchors.centerIn: parent

        YButton {
            id: refresh_new_year
            text: "↻ Refresh For New Year"
            height: 40
            width: 180
            anchors.horizontalCenter: parent.horizontalCenter

            color: "#047AD0"
            textColor: "white"
            font.pixelSize: 14
            font.weight: Font.Medium

            onClicked: popup.open()
        }

        YButton {
            text: "+ Add User"
            height: 40
            width: 120
            anchors.horizontalCenter: parent.horizontalCenter

            color: "#047AD0"
            textColor: "white"
            font.pixelSize: 14
            font.weight: Font.Medium

            onClicked: window.stackView.push("AddUser.qml")
        }

        YButton {
            text: "Sign Out"
            height: 40
            width: 120
            anchors.horizontalCenter: parent.horizontalCenter

            color: "#047AD0"
            textColor: "white"
            font.pixelSize: 14
            font.weight: Font.Medium

            onClicked: {
                window.stackView.pop();
                window.stackView.pop();
                window.stackView.pop();
            }
        }
    }

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 400
        height: 230
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        property string titleText: "Refresh Student Data?"
        property string informationText: "Confirm that you want to refresh student data for the new year. This involves updating Grade 11 to Grade 12, and backing up Grade 12 data.\n\nClick 'OK' to continue."

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
                anchors.topMargin: 160
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
                        popup.close()
                        saveDialog.open()
                    }
                }
            }
        }
    }

    FileDialog {
        id: saveDialog
        title: "Save File"
        nameFilters: ["Folder (*)"]
        fileMode: FileDialog.SaveFile

        onAccepted: {
            window.database.refreshNewYear(selectedFile)
            window.stackView.pop()
        }
    }
}
