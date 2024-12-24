import QtQuick

//
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //创建一个按钮
    Button
    {
        id: edit_btn
        text: "edit btn"
        anchors.left: parent.left
        anchors.leftMargin: 20 //左边距
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100 //向下距

        onClicked:
        {
            Qt.quit() //退出
        }
    }

    //创建一个矩形
    Rectangle {
        x: 100
        y: 100
        width: 180
        height: 30
        color: "blue"
    }

    //创建一个复选框
    CheckBox {
        id: chk_box
        text: qsTr("你好")
        checked: false
        x: 200
        y: 200

        indicator : Rectangle {
            implicitWidth:60
            implicitHeight:60

            x: chk_box.leftPadding
            y: parent.height/2-height/2

            radius: 30

            border.color: chk_box.down ? "#18a81a" : "*888999"

            Rectangle {
                width: 30
                height: 30
                x: 15
                y: 15

                radius: 30

                color: chk_box.down ? "#18a81a" : "*888999"
            }
        }

        //改变字体大小
        contentItem: Text {
            text: chk_box.text
            font.pixelSize : 30

            color: chk_box.down ? "#18a81a" : "*888999"

            verticalAlignment: Text.AlignVCenter //垂直对齐
            leftPadding: chk_box.indicator.width + chk_box.spacing
        }
    }

    //动画操作

    Rectangle {
        id: rect1
        x: 300
        y: 300
        width: 50
        height: 50
        state: "red"
        states: [ //状态列表
            State {
                name: "red"
                PropertyChanges {
                    target: rect1
                    color: "red"
                }
            },
            State {
                name: "blue"
                PropertyChanges {
                    target: rect1
                    color: "blue"
                    width: 80
                    height: 80
                }
            }
        ]
        transitions: [
            Transition {
                from: "red"
                to: "blue"
                PropertyAnimation {
                    properties: "color, width, height"
                    duration: 3000 //过程时间
                }
            }
        ]
    }

    Button {
        id: chg_btn
        x: 300
        y: 400
        text: qsTr("chg state blue")

        onClicked: rect1.state = "blue"
    }

    Button {
        id: chg_btn2
        x: 400
        y: 400
        text: qsTr("chg state red")

        onClicked: rect1.state = "red"
    }
}
