import QtQuick
import QtQuick.Controls

import database

ApplicationWindow {
    id: root
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Dhirubhai Ambani International School")

    property alias database: database
    property alias stackView: stackView
    property string currentTitle: stackView.currentItem ? stackView.currentItem.title : ""

    Database {
        id: database

        onProgress: (progress, epochs) => {
            stackView.children[stackView.depth - 1].progress = progress / epochs
        };

        onDownloadProgress: (progress, total) => {
            stackView.children[stackView.depth - 1].downloadProgress = progress / total;
        }
    }

    header: ToolBar {
        contentHeight: 50

        background: Rectangle {
            anchors.fill: parent

            Rectangle {
                width: 200
                height: parent.height + 20
                anchors.bottom: parent.bottom
                radius: 20
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#FCB131"
            }
        }

        Row {
            spacing: 10

            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 5
            visible: currentTitle !== "Login" && currentTitle !== "Menu"

            YButton {
                id: toolButton
                text: toolButton.width === 80 ? "⏴  Back" : "\u2630"
                height: 40
                width: stackView.depth > 1 && currentTitle !== "Menu" ? 80 : 40
                color: "#047AD0"
                textColor: "white"
                font.pixelSize: 15

                onClicked: {
                    if (stackView.depth > 1 && currentTitle !== "Menu") {
                        stackView.pop()
                    } else {
                        drawer.open()
                    }
                }
            }

            YButton {
                id: homeButton
                text: "Home"
                height: 40
                width: 80
                color: "#047AD0"
                textColor: "white"
                font.pixelSize: 15

                onClicked: {
                    while (stackView.depth > 2) {
                        stackView.pop();
                    }
                }
            }
        }

        Label {
            text: currentTitle
            anchors.centerIn: parent
            font.pixelSize: 20
            font.weight: Font.Bold
            color: "black"

            Rectangle {
                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width + 5
                height: 2
                color: "#047AD0"
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "Login.qml"
        anchors.fill: parent

        onCurrentItemChanged: {
            children[depth - 1].window = root
        }
    }
}
