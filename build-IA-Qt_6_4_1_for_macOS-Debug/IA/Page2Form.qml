import QtQuick
import QtQuick.Controls

Page {
    width: 600
    height: 400

    title: "Page 2"

    Label {
        text: "You are on Page 1"
        anchors.centerIn: parent
        color: "#056524"
        font.pointSize: 20
        font.family: "Karla"
        font.bold: true
    }
}
