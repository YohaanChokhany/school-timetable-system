import QtQuick
import QtQuick.Controls

Item {
    id: root
    height: 40
    width: 100

    property string text: "";
    property bool border: true;
    property color background: "white";
    property color color: "#047AD0";
    property color textColor: "white";
    property alias mouseArea: mouseArea;
    property font font;
    property var last_bg;
    property int radius: root.height;
    property bool enabled: true;
    property int horizontalAlignment: Text.AlignHCenter;

    signal clicked();

    function exited() {
        colorNormal.start()
        textColorNormal.start()
    }

    Rectangle {
        id: background
        anchors.fill: parent
        radius: root.radius
        border.width: root.border ? 2 : 0
        border.color: root.enabled ? root.color : "#aaa"
        color: root.background
        clip: true


        Text {
            id: label
            text: root.text
            font: root.font
            height: parent.height
            width: parent.width - 20
            anchors.top: parent.top
            color: "black"
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

            onEntered: {
                if (root.enabled) {
                    colorFocus.start()
                    textColorFocus.start()
                }
            }

            onExited: {
                if (root.enabled) {
                    colorNormal.start()
                    textColorNormal.start()
                }
            }

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
                }
            }

            onReleased: {
                if (root.enabled) {
                    opacityReleased.target = last_bg
                    opacityReleased.start()
                }
            }

            onClicked: root.clicked()
        }
    }

    Rectangle { id: rec }

    ColorAnimation {
        id: colorFocus
        target: background
        property: "color"
        from: root.background
        to: root.color
        duration: 100
    }

    ColorAnimation {
        id: colorNormal
        target: background
        property: "color"
        from: root.color
        to: root.background
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

    ColorAnimation {
        id: textColorNormal
        target: label
        property: "color"
        from: root.textColor
        to: "black"
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
