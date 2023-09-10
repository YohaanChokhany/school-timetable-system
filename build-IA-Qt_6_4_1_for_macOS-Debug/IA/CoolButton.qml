import QtQuick

Item {
    id: root

    property string text: ""
    property color color: "#99C2FA"
    property color hoverColor: "#D1E3FA"
    property color textColor: "black"
    property color clickColor: "#F7D4AC"
    property alias title: display
    property alias area: mouseArea

    Rectangle {
        anchors.fill: parent
        color: root.color

        Text {
            id: display
            text: root.text
            color: root.textColor
            font.bold: true
            anchors.centerIn: parent
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: parent.color = root.hoverColor
            onExited: parent.color = root.color
            onPressed: parent.color = root.clickColor
            onReleased: parent.color = root.hoverColor
        }
    }
}
