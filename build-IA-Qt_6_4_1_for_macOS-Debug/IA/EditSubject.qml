import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Page {
    id: root
    title: "Edit Subject"
    height: parent.height
    width: parent.width

    property var window
    property var id: id
    property var name: name

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Column {
        spacing: 20
        anchors.centerIn: parent
        width: 300

        YTextField {
            id: id
            placeholder: "ID"
            width: 300
            visible: false
        }

        YTextField {
            id: name
            placeholder: "Name"
            setFocus: true
            width: 300
        }

        YButton {
            height: 40
            width: 100
            text: "Edit"
            color: "#047AD0"
            textColor: "white"
            font.weight: Font.Medium
            font.pixelSize: 14
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                var res = window.database.editSubject(id.textField.text, name.textField.text)
                if (res === "SUCCESS") {
                    window.stackView.pop()
                    window.stackView.children[window.stackView.depth - 1].refresh()
                } else {
                    popup.open()
                    popup.titleText = res
                    if (res === "INCOMPLETE")
                        popup.informationText = "All input fields of the form have not been completed. \n\nPlease click 'Add' once this has been completed."
                    if (res === "INVALID SUBJECT")
                        popup.informationText = "Chosen subject already exists. Enter a different name. \n\nPlease click 'Add' once this has been completed."
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
