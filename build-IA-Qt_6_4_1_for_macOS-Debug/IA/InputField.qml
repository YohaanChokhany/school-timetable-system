import QtQuick
import QtQuick.Controls

Item {
    id: root
    height: 25
    width: 100

    property string placeholder: ""
    property int echoMode: TextField.Normal
    property color color: "red"

    TextField {
        id: textField
        width: root.width
        height: root.height
        echoMode: root.echoMode
        focus: root.focus

        background: Rectangle {
            anchors.fill: parent
            color: "white"
        }

        onActiveFocusChanged: {
            if (textField.focus && textField.text === "") {
                colorFocus.start()
                fontFocus.start()
                topMarginFocus.start()
                leftMarginFocus.start()
                underlineFocus.start()
            } else if (!textField.focus && textField.text === "") {
                colorNormal.start()
                fontNormal.start()
                topMarginNormal.start()
                leftMarginNormal.start()
                underlineNormal.start()
            } else if (!textField.focus) {
                colorNormal.start()
                underlineNormal.start()
            } else if (textField.focus) {
                colorFocus.start()
                underlineFocus.start()
            }
        }
    }

    Label {
        id: label
        text: root.placeholder
        anchors.top: textField.top
        anchors.left: textField.left
        anchors.topMargin: 4
        anchors.leftMargin: 4
        font.pixelSize: 13
        color: "black"
    }

    Rectangle {
        width: parent.width
        height: 1
        anchors.bottom: textField.bottom
        color: "#aaa"
    }

    Rectangle {
        id: underline
        height: 2
        width: 0
        color: root.color
        anchors.bottom: textField.bottom
        anchors.horizontalCenter: textField.horizontalCenter
    }



    NumberAnimation {
        id: fontFocus
        target: label
        property: "font.pixelSize"
        from: 13
        to: 10
        duration: 100
    }

    NumberAnimation {
        id: fontNormal
        target: label
        property: "font.pixelSize"
        from: 10
        to: 13
        duration: 100
    }

    NumberAnimation {
        id: topMarginFocus
        target: label
        property: "anchors.topMargin"
        from: 4
        to: -10
        duration: 100
    }

    NumberAnimation {
        id: topMarginNormal
        target: label
        property: "anchors.topMargin"
        from: -10
        to: 4
        duration: 100
    }

    NumberAnimation {
        id: leftMarginFocus
        target: label
        property: "anchors.leftMargin"
        from: 4
        to: 0
        duration: 100
    }

    NumberAnimation {
        id: leftMarginNormal
        target: label
        property: "anchors.leftMargin"
        from: 0
        to: 4
        duration: 100
    }

    ColorAnimation {
        id: colorFocus
        target: label
        property: "color"
        from: "black"
        to: root.color
        duration: 100
    }

    ColorAnimation {
        id: colorNormal
        target: label
        property: "color"
        from: root.color
        to: "black"
        duration: 100
    }

    NumberAnimation {
        id: underlineFocus
        target: underline
        property: "width"
        from: 0
        to: root.width
        duration: 100
    }

    NumberAnimation {
        id: underlineNormal
        target: underline
        property: "width"
        from: root.width
        to: 0
        duration: 100
    }
}
