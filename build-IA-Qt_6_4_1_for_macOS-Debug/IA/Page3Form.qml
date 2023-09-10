import QtQuick
import QtQuick.Controls

Page {
    width: 600
    height: 400

    title: "Page 1"

    Column {
        width: 185
        spacing: 10
        anchors.centerIn: parent

        Grid {
            id: grid
            columns: 2
            spacing: 10

            width: 265

            Label {
                text: "First Name"
                height: 22
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: firstName

                placeholderText: "First Name"
                text: ""
            }

            Label {
                text: "Last Name"
                height: 22
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: lastName

                placeholderText: "Last Name"
                text: ""
            }
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            height: 40
            width: 100
            text: "Save"
        }
    }
}
