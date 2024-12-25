import QtQuick

import QtQuick.Controls
//import QtGraphicalEffects 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    BusyIndicator {
        id: mybusy

        /*
        //锚点布局
        anchors.centerIn: parent
        implicitWidth: 200
        implicitHeight: 200

        contentItem: Item {
            Rectangle {
                id: myrect
                width: parent.width
                height: parent.height
                color: Qt.rgba(0, 0, 0, 0)
                radius: width / 2;
                border.width: width / 8 //数字越大圆圈越小
                visible: false //边框是否可见
            }
        }
        */

        /*
        ConicalGradient {
            width: myrect.width
            height: myrect.height
            gradient: Gradient {
                GradientStop {
                    position: 0.0
                    color:"chartreuse" //圆圈颜色
                }
                GradientStop {
                    position: 1.0
                    color:"orange" //圆圈旋转后的颜色
                }
            }
            source: myrect
            Rectangle {
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                width: myrect.border.width
                height: width
                radius: width / 2
                color: "red"
            }
            RotationAnimation on rotation {
                from: 0
                to: 360
                duration: 2000
                loops: Animation.Infinite
            }
        }
        */
    }
}
