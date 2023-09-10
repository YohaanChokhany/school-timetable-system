import QtQuick
import QtQuick.Controls

Page {
    id: root
    title: "Login"
    height: parent.height
    width: parent.width

    property var window

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Component.onCompleted: {
        username.focus = true
        username.text = "yohaanchokhany@gmail.com"

        password.focus = true
        password.text = "6teenH&42"
    }

    Column {
        width: 300
        spacing: 20
        anchors.centerIn: parent

        YTextField {
            id: username
            width: parent.width
            height: 25

            placeholder: "Username"
            color: "#047AD0"

            Keys.onReturnPressed: login()
        }

        YTextField {
            id: password
            width: parent.width
            height: 25

            placeholder: "Password"
            color: "#047AD0"
            echoMode: TextField.Password

            Keys.onReturnPressed: login()
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

            onClicked: login()
        }
    }

    function login() {
        var response = window.database.loginUser(username.textField.text, password.textField.text)
        if (response === "SUCCESS") {
            username.text = ""
            password.text = ""
            username.focus = true
            window.stackView.push("MainMenu.qml")
        } else if (response === "Incorrect Username") {
            username.error()
        } else if (response === "Incorrect Password") {
            password.error()
        }
    }
}
