import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Teacher

ColumnLayout {
    id: root

    property alias list: list
    property alias model: teacherModel

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

            model: TeacherModel {
                id: teacherModel
                list: teacherList
            }

            delegate: Rectangle {
                color: checkBox.checked ? "#B3D7FF" : "white"
                width: list.width;
                height: 34

                RowLayout {
                    id: row
                    width: list.width - 10
                    anchors.top: parent.top
                    anchors.topMargin: 2
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
                        width: 200
                    }

                    YTextField {
                        id: subjects
                        width: 350
                        text: model.subjects
                        enabled: false
                    }

                    YButton {
                        id: block1
                        Layout.fillWidth: true
                        text: model.block_1 !== "" ? window.database.getBatch(model.block_1)[1] : ""
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft
                        enabled: model.block_1 !== ""
                        onClicked: {
                            if (model.block_1 !== "")
                                root.viewBatch(model.block_1)
                        }
                    }

                    YButton {
                        id: block2
                        Layout.fillWidth: true
                        text: model.block_2 !== "" ? window.database.getBatch(model.block_2)[1] : ""
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft
                        enabled: model.block_2 !== ""
                        onClicked: {
                            if (model.block_2 !== "")
                                root.viewBatch(model.block_2)
                        }
                    }

                    YButton {
                        id: block3
                        Layout.fillWidth: true
                        text: model.block_3 !== "" ? window.database.getBatch(model.block_3)[1] : ""
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft
                        enabled: model.block_3 !== ""
                        onClicked: {
                            if (model.block_3 !== "")
                                root.viewBatch(model.block_3)
                        }
                    }

                    YButton {
                        id: block4
                        Layout.fillWidth: true
                        text: model.block_4 !== "" ? window.database.getBatch(model.block_4)[1] : ""
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft
                        enabled: model.block_4 !== ""
                        onClicked: {
                            if (model.block_4 !== "")
                                root.viewBatch(model.block_4)
                        }
                    }

                    YButton {
                        id: block5
                        Layout.fillWidth: true
                        text: model.block_5 !== "" ? window.database.getBatch(model.block_5)[1] : ""
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft
                        enabled: model.block_5 !== ""
                        onClicked: {
                            if (model.block_5 !== "")
                                root.viewBatch(model.block_5)
                        }
                    }

                    YButton {
                        id: block6
                        Layout.fillWidth: true
                        text: model.block_6 !== "" ? window.database.getBatch(model.block_6)[1] : ""
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft
                        enabled: model.block_6 !== ""
                        onClicked: {
                            if (model.block_6 !== "")
                                root.viewBatch(model.block_6)
                        }
                    }

                    YButton {
                        id: block7
                        Layout.fillWidth: true
                        text: model.block_7 !== "" ? window.database.getBatch(model.block_7)[1] : ""
                        height: 30
                        radius: 10
                        horizontalAlignment: Text.AlignLeft
                        enabled: model.block_7 !== ""
                        onClicked: {
                            if (model.block_7 !== "")
                                root.viewBatch(model.block_7)
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
