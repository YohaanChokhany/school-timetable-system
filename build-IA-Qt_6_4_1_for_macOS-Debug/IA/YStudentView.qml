import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Student

ColumnLayout {
    id: root

    property int grade: 11
    property alias list: list
    property alias model: studentModel

    signal itemCheckStateChanged()
    signal viewBatch(string batch)

    Frame {
        Layout.fillWidth: true
        Layout.fillHeight: true

        ListView {
            id: list
            anchors.fill: parent
            anchors.leftMargin: 10
            anchors.topMargin: 10
            clip: true

            property var selected: []

            model: StudentModel {
                id: studentModel
                list: root.grade == 11 ? list11 : list12
            }

            delegate: Rectangle {
                color: checkBox.checked ? "#B3D7FF" : "white"
                width: list.width;
                height: 32

                RowLayout {
                    id: row
                    width: list.width - 10
                    anchors.left: parent.left
                    anchors.leftMargin: 5

                    CheckBox {
                        id: checkBox
                        checked: list.selected.indexOf(model.index) != -1

                        onCheckedChanged: {
                            if (checked) {
                                if (list.selected.indexOf(model.index) == -1)
                                    list.selected.push(model.index)
                            } else {
                                list.selected.splice(list.selected.indexOf(model.index), 1)
                            }
                            root.itemCheckStateChanged()
                        }
                    }

                    YTextField {
                        id: reg
                        text: model.reg
                        width: 73
                        horizontalAlignment: TextInput.AlignHCenter
                        enabled: false
                    }

                    ComboBox {
                        id: edu_field
                        implicitWidth: 85
                        model: [ "IGCSE", "ICSE", "New" ]
                        currentIndex: edu === "IGCSE" ? 0 : edu === "ICSE" ? 1 : 2
                        onActivated: edu = edu_field.currentIndex === 0 ? "IGCSE" : edu_field.currentIndex === 1 ? "ICSE" : "New"
                    }

                    YTextField {
                        id: first_name
                        width: 80
                        text: model.first_name
                        onTextEdited: model.first_name = first_name.textField.text
                    }

                    YTextField {
                        id: middle_name
                        width: 80
                        text: model.middle_name
                        onTextEdited: model.middle_name = middle_name.textField.text
                    }

                    YTextField {
                        id: last_name
                        width: 80
                        text: model.last_name
                        onTextEdited: model.last_name = last_name.textField.text
                    }

                    ComboBox {
                        id: gender_field
                        implicitWidth: 58
                        model: [ "M", "F" ]
                        currentIndex: gender === "M" ? 0 : 1
                        onActivated: gender = gender_field.currentIndex === 0 ? "M" : "F"
                    }

                    YTextField {
                        id: hl1
                        text: model.hl1
                        enabled: false
                        onTextEdited: model.hl1 = hl1.textField.text
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "0"
                    }

                    YButton {
                        id: block_1
                        text: model.classes[0] !== "" ? model.hl1 : "OPEN"
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "1"
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft;
                        enabled: model.classes[0] !== ""
                        onClicked: {
                            if (model.classes[0] !== "")
                                root.viewBatch(model.classes[0])
                        }
                    }

                    YTextField {
                        id: hl2
                        text: model.hl2
                        enabled: false
                        onTextEdited: model.hl2 = hl2.textField.text
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "0"
                    }

                    YButton {
                        id: block_2
                        text: model.classes[1] !== "" ? model.hl2 : "OPEN"
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "1"
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft;
                        enabled: model.classes[1] !== ""
                        onClicked: {
                            if (model.classes[1] !== "")
                                root.viewBatch(model.classes[1])
                        }
                    }

                    YTextField {
                        id: hl3
                        text: model.hl3
                        enabled: false
                        onTextEdited: model.hl3 = hl3.textField.text
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "0"
                    }

                    YButton {
                        id: block_3
                        text: model.classes[2] !== "" ? model.hl3 : "OPEN"
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "1"
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft;
                        enabled: model.classes[2] !== ""
                        onClicked: {
                            if (model.classes[2] !== "")
                                root.viewBatch(model.classes[2])
                        }
                    }

                    YTextField {
                        id: sl1
                        text: model.sl1
                        enabled: false
                        onTextEdited: model.sl1 = sl1.textField.text
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "0"
                    }

                    YButton {
                        id: block_4
                        text: model.classes[3] !== "" ? model.sl1 : "OPEN"
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "1"
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft;
                        enabled: model.classes[3] !== ""
                        onClicked: {
                            if (model.classes[3] !== "")
                                root.viewBatch(model.classes[3])
                        }
                    }

                    YTextField {
                        id: sl2
                        text: model.sl2
                        enabled: false
                        onTextEdited: model.sl2 = sl2.textField.text
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "0"
                    }

                    YButton {
                        id: block_5
                        text: model.classes[4] !== "" ? model.sl2 : "OPEN"
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "1"
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft;
                        enabled: model.classes[4] !== ""
                        onClicked: {
                            if (model.classes[4] !== "")
                                root.viewBatch(model.classes[4])
                        }
                    }

                    YTextField {
                        id: sl3
                        text: model.sl3
                        enabled: false
                        onTextEdited: model.sl3 = sl3.textField.text
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "0"
                    }

                    YButton {
                        id: block_6
                        text: model.classes[5] !== "" ? model.sl3 : "OPEN"
                        Layout.fillWidth: true
                        visible: window.database.getGrade(root.grade)[1] === "1"
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft;
                        enabled: model.classes[5] !== ""
                        onClicked: {
                            if (model.classes[5] !== "")
                                root.viewBatch(model.classes[5])
                        }
                    }

                    YButton {
                        id: block_7
                        text: model.classes[6] !== "" ? "TOK" : "OPEN"
                        visible: window.database.getGrade(root.grade)[1] === "1" && model.classes[6] !== ""
                        radius: 10
                        height: 30
                        width: 45
                        onClicked: {
                            if (model.classes[6] !== "")
                                root.viewBatch(model.classes[6])
                        }
                    }

                    YButton {
                        id: block_8
                        text: model.classes[7] !== "" ? "TOK" : "OPEN"
                        visible: window.database.getGrade(root.grade)[1] === "1" && model.classes[7] !== ""
                        radius: 10
                        height: 30
                        width: 45
                        onClicked: {
                            if (model.classes[7] !== "")
                                root.viewBatch(model.classes[7])
                        }
                    }

                    Component.onCompleted: {
                        for (var i = 2; i < row.children.length; i++) {
                            if (!row.children[i].model) {
                                row.children[i].children[0].select(0, 0);
                            }
                        }
                    }
                }
            }
        }
    }
}
