import QtQuick
import QtQuick.Controls

Page {
    id: root
    title: "Add User"
    height: parent.height
    width: parent.width

    property var window

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Column {
        width: 300
        spacing: 20
        anchors.centerIn: parent

        YTextField {
            id: username
            width: parent.width
            height: 25

            setFocus: true

            placeholder: "Username"
            color: "#047AD0"

            Keys.onReturnPressed: addUser()
        }

        YTextField {
            id: password
            width: parent.width
            height: 25

            placeholder: "Password"
            color: "#047AD0"
            echoMode: TextField.Password

            Keys.onReturnPressed: addUser()
        }

        YTextField {
            id: confirmPassword
            width: parent.width
            height: 25

            placeholder: "Confirm Password"
            color: "#047AD0"
            echoMode: TextField.Password

            Keys.onReturnPressed: addUser()
        }

        YButton {
            text: "Submit"
            height: 40
            width: 100
            anchors.horizontalCenter: parent.horizontalCenter

            color: "#047AD0"
            textColor: "white"
            font.pixelSize: 14
            font.weight: Font.Medium

            onClicked: addUser()
        }
    }

    function addUser() {
        var response = window.database.addUser(username.text, password.text, confirmPassword.text)
        if (response === "SUCCESS") {
            window.stackView.pop()
            window.stackView.pop()
            window.stackView.pop()
            window.stackView.pop()
        } else {
            popup.titleText = response
            popup.open()
            if (response === "INCOMPLETE")
                popup.informationText = "Please enter data in all fields.";
            else if (response === "INVALID EMAIL")
                popup.informationText = "Username entered in wrong format. Please enter an email.";
            else if (response === "INVALID PASSWORD")
                popup.informationText = "Use 8 characters or more for your password.";
            else if (response === "DID NOT MATCH")
                popup.informationText = "Those passwords did not match. Try again.";
            else if (response === "USERNAME EXISTS")
                popup.informationText = "Username entered already exists. Please try again.";
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
