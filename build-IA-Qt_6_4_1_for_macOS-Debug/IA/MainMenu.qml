import QtQuick
import QtQuick.Controls

Page {
    id: root
    title: "Menu"
    height: parent.height
    width: parent.width

    property var window

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }


    Rectangle {
        width: 300
        height: 350
        anchors.centerIn: parent
        radius: 30
        border.width: 2
        border.color: "black"

        Column {
            spacing: 10
            anchors.centerIn: parent

            YButton {
                text: "View Students"
                height: 40
                width: 140
                anchors.horizontalCenter: parent.horizontalCenter

                color: "#047AD0"
                textColor: "white"
                font.pixelSize: 14
                font.weight: Font.Medium

                onClicked: popup.open()
            }

            YButton {
                text: "View Teachers"
                height: 40
                width: 140
                anchors.horizontalCenter: parent.horizontalCenter

                color: "#047AD0"
                textColor: "white"
                font.pixelSize: 14
                font.weight: Font.Medium

                onClicked: {
                    window.stackView.push("ViewTeachers.qml")
                    window.stackView.children[window.stackView.depth - 1].refresh()
                }
            }

            YButton {
                text: "View Subjects"
                height: 40
                width: 140
                anchors.horizontalCenter: parent.horizontalCenter

                color: "#047AD0"
                textColor: "white"
                font.pixelSize: 14
                font.weight: Font.Medium

                onClicked: {
                    window.stackView.push("ViewSubjects.qml")
                    window.stackView.children[window.stackView.depth - 1].refresh()
                }
            }

            YButton {
                text: "Student Locator"
                height: 40
                width: 140
                anchors.horizontalCenter: parent.horizontalCenter

                color: "#047AD0"
                textColor: "white"
                font.pixelSize: 14
                font.weight: Font.Medium

                onClicked: {
                    window.stackView.push("StudentLocator.qml")
                    window.stackView.children[window.stackView.depth - 1].loadStudents("");
                }
            }

            YButton {
                text: "⚙ Settings"
                height: 40
                width: 140
                anchors.horizontalCenter: parent.horizontalCenter

                color: "#047AD0"
                textColor: "white"
                font.pixelSize: 14
                font.weight: Font.Medium

                onClicked: {
                    window.stackView.push("SettingsMenu.qml")
                    window.stackView.children[window.stackView.depth - 1].refresh_new_year.visible = window.database.getGrade(11)[1] === "1"
                }
            }
        }
    }

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 400
        height: 200
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        property string titleText: "Choose Grade"
        property string informationText: "Which grade's student data do you wish to view.\n\nKindly click on one of the buttons below to continue."

        Rectangle {
            anchors.fill: parent
            color: "white"

            Text {
                text: popup.titleText
                font.pixelSize: 20
                font.weight: Font.Bold
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 20

                Rectangle {
                    width: parent.width
                    height: 3
                    color: "#047AD0"
                    anchors.bottom: parent.bottom
                }
            }

            Text {
                text: popup.informationText
                width: parent.width - 40
                wrapMode: Text.WordWrap
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 65
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 130
                spacing: 20

                YButton {
                    height: 40
                    width: 80
                    text: "Grade 11"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14

                    onClicked: {
                        popup.close()
                        window.stackView.push("ViewStudents.qml")
                        window.stackView.children[window.stackView.depth - 1].grade = 11
                        window.stackView.children[window.stackView.depth - 1].refresh()
                        window.stackView.children[window.stackView.depth - 1].assignBatches.visible = window.database.getGrade(11)[1] === "0" && window.database.verifyStudentData(11)
                        window.stackView.children[window.stackView.depth - 1].upload_button.visible = window.database.getGrade(11)[1] === "0"
                        window.stackView.children[window.stackView.depth - 1].download_pdf_button.visible = window.database.getGrade(11)[1] === "1"
                    }
                }

                YButton {
                    height: 40
                    width: 80
                    text: "Grade 12"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14

                    onClicked: {
                        popup.close()
                        window.stackView.push("ViewStudents.qml")
                        window.stackView.children[window.stackView.depth - 1].grade = 12
                        window.stackView.children[window.stackView.depth - 1].refresh()
                        window.stackView.children[window.stackView.depth - 1].download_pdf_button.visible = window.database.getGrade(12)[1] === "1"
                    }
                }
            }
        }
    }
}
