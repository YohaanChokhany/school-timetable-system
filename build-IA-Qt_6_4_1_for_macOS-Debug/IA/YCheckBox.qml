import QtQuick
import QtQuick.Controls

Item {
    id: root
    height: 40
    width: 100

    property string text: "";
    property bool border: true;
    property color color: "#047AD0";
    property color selectedColor: "#666";
    property color textColor: "white";
    property alias mouseArea: mouseArea;
    property font font;
    property var last_bg;
    property int radius: root.height;
    property bool enabled: true;
    property int horizontalAlignment: Text.AlignHCenter;

    property bool selected: false;

    signal checked();

    Rectangle {
        id: background
        anchors.fill: parent
        radius: root.radius
        border.width: root.border ? 2 : 0
        border.color: root.enabled ? root.color : "#aaa"
        color: root.color
        clip: true


        Text {
            id: label
            text: root.text
            font: root.font
            height: parent.height
            width: parent.width - 20
            anchors.top: parent.top
            color: root.textColor
            horizontalAlignment: root.horizontalAlignment
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter
            clip: true
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: root.enabled ? Qt.PointingHandCursor : Qt.ArrowCursor

            onPressed: function pressed(mouse) {
                if (root.enabled) {
                    last_bg = Qt.createQmlObject(`
                        import QtQuick 2.0
                        Rectangle {
                            color: "white"
                            opacity: 0.2
                            width: 20
                            height: 20
                            radius: 1000
                            anchors.top: parent.top
                            anchors.topMargin: ` + (mouse.y - 10) + `
                            anchors.left: parent.left
                            anchors.leftMargin: ` + (mouse.x - 10) + `
                        }
                        `,
                        background,
                        "yButton"
                    );

                    widthPressed.target = last_bg
                    widthPressed.start()

                    root.checked()

                    if (!root.selected)
                        root.selected = true
                    else
                        root.selected = false
                }
            }

            onReleased: {
                if (root.enabled) {
                    opacityReleased.target = last_bg
                    opacityReleased.start()
                }
            }
        }
    }

    onSelectedChanged: {
        if (root.selected) {
            colorSelected.start()
            borderColorSelected.start()
        } else {
            colorFocus.start()
            borderColorFocus.start()
        }
    }

    Rectangle { id: rec }

    ColorAnimation {
        id: colorFocus
        target: background
        property: "color"
        to: root.color
        duration: 100
    }

    ColorAnimation {
        id: colorSelected
        target: background
        property: "color"
        to: root.selectedColor
        duration: 100
    }

    ColorAnimation {
        id: borderColorSelected
        target: background
        property: "border.color"
        to: root.selectedColor
        duration: 100
    }

    ColorAnimation {
        id: borderColorFocus
        target: background
        property: "border.color"
        to: root.color
        duration: 100
    }

    ColorAnimation {
        id: textColorFocus
        target: label
        property: "color"
        from: "black"
        to: root.textColor
        duration: 100
    }

    NumberAnimation {
        id: widthPressed
        property: "scale"
        from: 0
        to: root.width / 10
        duration: 150
    }

    NumberAnimation {
        id: opacityReleased
        property: "opacity"
        from: 0.2
        to: 0
        duration: 100
    }
}
