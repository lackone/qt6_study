import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: txt1
        text: qsTr("我是一侧面")

        anchors.horizontalCenter: parent.horizontalCenter //水平居中
        anchors.top: parent.top
        anchors.topMargin: 50 //要让topMargin生效，必须要设置top锚定物

        // x: 50
        // y: 50
        color: "blue"
        font.pixelSize: 28
    }

    Rectangle {
        id: rect
        x: 100
        y: 100
        anchors.left: txt1.left

        width: 100
        height: 100
        color: "red"
        border.width: 1 //边框宽度
        border.color: "black" //边框颜色
        radius: 50

        TextInput {
            id: txtipt
            width: 80
            height: 30
            x: 5
            y: 5
            focus: true //焦点
        }
    }

    Image {
        id: img
        anchors.horizontalCenter: rect.horizontalCenter
        anchors.top: rect.bottom
        anchors.topMargin: 20

        width: 50
        height: 50
        source: "/images/1.png"

        fillMode: Image.PreserveAspectFit
    }
}
