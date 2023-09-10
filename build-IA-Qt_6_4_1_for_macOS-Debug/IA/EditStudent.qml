import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Page {
    id: root
    title: "Edit Student"
    height: parent.height
    width: parent.width

    property var window
    property alias reg: reg
    property alias edu: edu
    property alias first_name: first_name
    property alias middle_name: middle_name
    property alias last_name: last_name
    property alias gender: gender
    property alias hl1: hl1
    property alias hl2: hl2
    property alias hl3: hl3
    property alias sl1: sl1
    property alias sl2: sl2
    property alias sl3: sl3

    background: Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Column {
        spacing: 20
        anchors.centerIn: parent

        Row {
            spacing: 10
            width: 260
            anchors.horizontalCenter: parent.horizontalCenter

            YTextField {
                id: reg
                placeholder: "Registration No."
                width: 150
                enabled: false
            }

            YComboBox {
                id: edu
                width: 100
                placeholder: "Education"
                model: ["IGCSE", "ICSE", "New"]
            }
        }

        Row {
            spacing: 10

            YTextField {
                id: first_name
                setFocus: true
                placeholder: "First Name"
                width: 150
            }

            YTextField {
                id: middle_name
                placeholder: "Middle Name"
                width: 150
            }

            YTextField {
                id: last_name
                placeholder: "Last Name"
                width: 150
            }
        }

        YComboBox {
            id: gender
            width: 100
            placeholder: "Gender"
            anchors.horizontalCenter: parent.horizontalCenter
            model: [ "Male", "Female" ]
        }

        YComboBox {
            id: hl1
            placeholder: "HL Subject 1"
            width: 280
            anchors.horizontalCenter: parent.horizontalCenter
            model: ["Biology", "Business Management", "Chemistry", "Computer Science", "Economics", "English Language and Literature", "English Literature", "French Ab Initio", "French B", "Geography", "Global Politics", "Hindi B", "History", "Maths Analysis and Approaches", "Maths Applications and Interpretations", "Physics", "Psychology", "Spanish Ab Initio", "Spanish B", "Sports, Exercise, and Health Science", "Theatre", "Theory of Knowledge", "Visual Arts"]
        }

        YComboBox {
            id: hl2
            placeholder: "HL Subject 2"
            width: 280
            anchors.horizontalCenter: parent.horizontalCenter
            model: ["Biology", "Business Management", "Chemistry", "Computer Science", "Economics", "English Language and Literature", "English Literature", "French Ab Initio", "French B", "Geography", "Global Politics", "Hindi B", "History", "Maths Analysis and Approaches", "Maths Applications and Interpretations", "Physics", "Psychology", "Spanish Ab Initio", "Spanish B", "Sports, Exercise, and Health Science", "Theatre", "Theory of Knowledge", "Visual Arts"]
        }

        YComboBox {
            id: hl3
            placeholder: "HL Subject 3"
            width: 280
            anchors.horizontalCenter: parent.horizontalCenter
            model: ["Biology", "Business Management", "Chemistry", "Computer Science", "Economics", "English Language and Literature", "English Literature", "French Ab Initio", "French B", "Geography", "Global Politics", "Hindi B", "History", "Maths Analysis and Approaches", "Maths Applications and Interpretations", "Physics", "Psychology", "Spanish Ab Initio", "Spanish B", "Sports, Exercise, and Health Science", "Theatre", "Theory of Knowledge", "Visual Arts"]
        }

        YComboBox {
            id: sl1
            placeholder: "SL Subject 1"
            width: 280
            anchors.horizontalCenter: parent.horizontalCenter
            model: ["Biology", "Business Management", "Chemistry", "Computer Science", "Economics", "English Language and Literature", "English Literature", "French Ab Initio", "French B", "Geography", "Global Politics", "Hindi B", "History", "Maths Analysis and Approaches", "Maths Applications and Interpretations", "Physics", "Psychology", "Spanish Ab Initio", "Spanish B", "Sports, Exercise, and Health Science", "Theatre", "Theory of Knowledge", "Visual Arts"]
        }

        YComboBox {
            id: sl2
            placeholder: "SL Subject 2"
            width: 280
            anchors.horizontalCenter: parent.horizontalCenter
            model: ["Biology", "Business Management", "Chemistry", "Computer Science", "Economics", "English Language and Literature", "English Literature", "French Ab Initio", "French B", "Geography", "Global Politics", "Hindi B", "History", "Maths Analysis and Approaches", "Maths Applications and Interpretations", "Physics", "Psychology", "Spanish Ab Initio", "Spanish B", "Sports, Exercise, and Health Science", "Theatre", "Theory of Knowledge", "Visual Arts"]
        }

        YComboBox {
            id: sl3
            placeholder: "SL Subject 3"
            width: 280
            anchors.horizontalCenter: parent.horizontalCenter
            model: ["Biology", "Business Management", "Chemistry", "Computer Science", "Economics", "English Language and Literature", "English Literature", "French Ab Initio", "French B", "Geography", "Global Politics", "Hindi B", "History", "Maths Analysis and Approaches", "Maths Applications and Interpretations", "Physics", "Psychology", "Spanish Ab Initio", "Spanish B", "Sports, Exercise, and Health Science", "Theatre", "Theory of Knowledge", "Visual Arts"]
        }

        YButton {
            height: 40
            width: 100
            text: "Edit"
            color: "#047AD0"
            textColor: "white"
            font.weight: Font.Medium
            font.pixelSize: 14
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                var res = window.database.editStudent(reg.text, edu.text, first_name.textField.text, middle_name.textField.text, last_name.textField.text, gender.text, hl1.text, hl2.text, hl3.text, sl1.text, sl2.text, sl3.text)
                if (res === "SUCCESS") {
                    window.stackView.pop()
                    window.stackView.children[window.stackView.depth - 1].refresh()
                } else {
                    popup.open()
                    popup.titleText = res
                    if (res === "INCOMPLETE")
                        popup.informationText = "Text has not been entered in all input fields of the form. \n\nPlease click 'Add' once this has been completed."
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

            property string titleText: "ERROR"
            property string informationText: ""

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
                    width: parent.width - 50
                    wrapMode: Text.WordWrap
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 65
                }

                YButton {
                    height: 40
                    width: 80
                    text: "Close"
                    color: "#047AD0"
                    textColor: "white"
                    font.weight: Font.Medium
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 130

                    onClicked: popup.close()
                }
            }
        }
    }
}
