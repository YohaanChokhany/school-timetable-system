import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Subject

ColumnLayout {
    id: root

    property alias list: list
    property alias model: subjectModel

    signal itemCheckStateChanged()

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

            model: SubjectModel {
                id: subjectModel
                list: subjectList
            }

            delegate: Rectangle {
                color: checkBox.checked ? "#B3D7FF" : "white"
                width: list.width;
                height: 32

                RowLayout {
                    id: row
                    width: list.width - 10
                    anchors.top: parent.top
                    anchors.topMargin: 3
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
                        id: name
                        text: model.name
                        width: 250
                        enabled: false
                    }

                    YTextField {
                        id: teachers
                        width: 80
                        text: model.teachers
                        enabled: false
                        Layout.fillWidth: true
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
