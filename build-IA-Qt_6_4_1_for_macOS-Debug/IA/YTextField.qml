import QtQuick
import QtQuick.Controls

Item {
    id: root
    height: 25
    width: 100

    property color color: "#047AD0"
    property color textColor: "#000000"
    property int echoMode: TextField.Normal
    property bool enabled: true
    property bool errorEnabled: false
    property string placeholder: ""
    property bool setFocus: false
    property string text: textField.text
    property var errorAnimation: errorAnimation
    property int horizontalAlignment: TextInput.AlignLeft
    property alias textField: textField

    signal editingFinished();
    signal textEdited();

    TextField {
        id: textField
        width: root.width
        height: root.height
        echoMode: root.echoMode
        focus: root.setFocus
        font.pixelSize: 14
        enabled: root.enabled
        text: root.text
        horizontalAlignment: root.horizontalAlignment
        color: root.textColor

        background: Rectangle {
            anchors.fill: parent
            color: "transparent"
        }

        onPressed: function pressed(mouse) {
            if (!textField.focus) {
                focusUnderline.anchors.leftMargin = mouse.x
                textField.focus = true

                var pos = textField.positionAt(mouse.x, mouse.y, TextInput.CursorBetweenCharacters)
                textField.select(pos, pos)
            }
        }

        onActiveFocusChanged: {
            if (!errorEnabled) {
                if (textField.activeFocus && textField.text === "") {
                    colorFocus.start()
                    fontFocus.start()
                    topMarginFocus.start()
                    leftMarginFocus.start()
                    underlineFocus.start()
                } else if (!textField.activeFocus && textField.text === "") {
                    colorNormal.start()
                    fontNormal.start()
                    topMarginNormal.start()
                    leftMarginNormal.start()
                    underlineNormal.start()
                } else if (!textField.activeFocus) {
                    colorNormal.start()
                    underlineNormal.start()
                } else if (textField.activeFocus) {
                    colorFocus.start()
                    underlineFocus.start()
                }
            } else {
                if (textField.activeFocus && textField.text === "") {
                    colorError.start()
                    fontFocus.start()
                    topMarginFocus.start()
                    leftMarginFocus.start()
                    underlineFocus.start()
                } else if (!textField.activeFocus && textField.text === "") {
                    colorNormal.start()
                    fontNormal.start()
                    topMarginNormal.start()
                    leftMarginNormal.start()
                    underlineNormal.start()
                } else if (!textField.activeFocus) {
                    underlineNormal.start()
                } else if (textField.activeFocus) {
                    underlineFocus.start()
                }
            }
        }

        onTextEdited: {
            root.textEdited()
            if (root.errorEnabled) {
                normalAnimation.start()
                root.errorEnabled = false
            }
        }

        onEditingFinished: root.editingFinished()

        onTextChanged: {
            if (root.text != "") {
                label.font.pixelSize = 10
                label.anchors.topMargin = -10
                label.anchors.leftMargin = 0
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
        font.pixelSize: 14
        color: "black"
    }

    Rectangle {
        id: underline
        width: parent.width
        height: 1
        anchors.bottom: textField.bottom
        color: "#aaa"
    }

    Rectangle {
        id: focusUnderline
        height: 2
        width: 0
        color: root.color
        anchors.bottom: textField.bottom
        anchors.left: parent.left
        anchors.leftMargin: root.width / 2
    }



    NumberAnimation {
        id: fontFocus
        target: label
        property: "font.pixelSize"
        from: 14
        to: 10
        duration: 100
    }

    NumberAnimation {
        id: fontNormal
        target: label
        property: "font.pixelSize"
        from: 10
        to: 14
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
        id: colorError
        target: label
        property: "color"
        from: "black"
        to: "red"
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

    ParallelAnimation {
        id: underlineFocus
        NumberAnimation { target: focusUnderline; property: "width"; to: root.width; duration: 100 }
        NumberAnimation { target: focusUnderline; property: "anchors.leftMargin"; to: 0; duration: 100 }
    }

    ParallelAnimation {
        id: underlineNormal
        NumberAnimation { target: focusUnderline; property: "width"; to: 0; duration: 100 }
        NumberAnimation { target: focusUnderline; property: "anchors.leftMargin"; to: root.width / 2; duration: 100 }
    }

    ParallelAnimation {
        id: errorAnimation
        ColorAnimation { target: label; property: "color"; to: "red"; duration: 100 }
        ColorAnimation { target: underline; property: "color"; to: "red"; duration: 100 }
        ColorAnimation { target: focusUnderline; property: "color"; to: "red"; duration: 100 }
    }

    ParallelAnimation {
        id: normalAnimation
        ColorAnimation { target: label; property: "color"; to: root.color; duration: 100 }
        ColorAnimation { target: underline; property: "color"; to: "#aaa"; duration: 100 }
        ColorAnimation { target: focusUnderline; property: "color"; to: root.color; duration: 100 }
    }

    onFocusChanged: {
        if (focus) {
            textField.forceActiveFocus()
        }
    }

    function error() {
        errorAnimation.start()
        root.errorEnabled = true
        textField.focus = true
    }
}
