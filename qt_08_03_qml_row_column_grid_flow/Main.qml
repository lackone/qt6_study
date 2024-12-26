import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //常见布局

    //row
    Rectangle {
        x: 10
        y: 10
        id: rect1
        width: 200
        height: 200
        border.color: "red"

        Row {
            anchors.centerIn: parent //相对父窗口居中
            spacing: 10 //间隔
            Rectangle {
                color: "green"
                width: 30
                height: 30
            }
            Rectangle {
                color: "red"
                width: 30
                height: 30
            }
            Rectangle {
                color: "blue"
                width: 30
                height: 30
            }
        }
    }

    //column
    Rectangle {
        x: 10
        y: 220
        id: rect2
        width: 200
        height: 200
        border.color: "red"

        Column {
            anchors.centerIn: parent //相对父窗口居中
            spacing: 10 //间隔
            Rectangle {
                color: "green"
                width: 30
                height: 30
            }
            Rectangle {
                color: "red"
                width: 30
                height: 30
            }
            Rectangle {
                color: "blue"
                width: 30
                height: 30
            }
        }
    }

    //grid
    Rectangle {
        x: 220
        y: 220
        id: rect3
        width: 200
        height: 200
        border.color: "red"

        Grid {
            anchors.centerIn: parent //相对父窗口居中
            spacing: 10 //间隔
            columns: 4 //一行4个
            Rectangle {
                color: "green"
                width: 30
                height: 30
            }
            Rectangle {
                color: "red"
                width: 30
                height: 30
            }
            Rectangle {
                color: "blue"
                width: 30
                height: 30
            }
            Rectangle {
                color: "orange"
                width: 30
                height: 30
            }
            Rectangle {
                color: "black"
                width: 30
                height: 30
            }
        }
    }

    //flow
    Flow {
        x: 10
        y: 10
        anchors.fill: parent
        anchors.margins: 5
        spacing: 10 //间隔
        Rectangle {
            color: "green"
            width: 30
            height: 30
        }
        Rectangle {
            color: "red"
            width: 30
            height: 30
        }
        Rectangle {
            color: "blue"
            width: 30
            height: 30
        }
        Rectangle {
            color: "orange"
            width: 30
            height: 30
        }
        Rectangle {
            color: "black"
            width: 30
            height: 30
        }
        Rectangle {
            color: "green"
            width: 30
            height: 30
        }
        Rectangle {
            color: "red"
            width: 30
            height: 30
        }
        Rectangle {
            color: "blue"
            width: 30
            height: 30
        }
        Rectangle {
            color: "orange"
            width: 30
            height: 30
        }
        Rectangle {
            color: "black"
            width: 30
            height: 30
        }
    }
}
