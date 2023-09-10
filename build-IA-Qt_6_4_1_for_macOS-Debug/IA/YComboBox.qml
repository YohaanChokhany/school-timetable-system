import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 100
    height: 20

    property var model: [];
    property string placeholder: ""
    property color color: "#047AD0"
    property string text: comboBox.currentText
    property int index: comboBox.currentIndex

    Text {
        id: label

        anchors.top: root.top
        anchors.topMargin: -10

        anchors.left: root.left
        anchors.leftMargin: 0

        text: root.placeholder

        font.pixelSize: 10
    }

    ComboBox {
        id: comboBox
        model: root.model
        implicitWidth: root.width
        editable: true
        currentIndex: root.index

        onActiveFocusChanged: {
            if (comboBox.focus) {
                colorFocus.start()
            } else {
                colorNormal.start()
            }
        }
    }

    ColorAnimation {
        id: colorFocus
        target: label
        property: "color"
        to: root.color
        duration: 100
    }

    ColorAnimation {
        id: colorNormal
        target: label
        property: "color"
        to: "black"
        duration: 100
    }
}
