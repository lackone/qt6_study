import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect

        anchors.centerIn: parent //通过锚，定位到窗口中心

        // x: 10
        // y: 10
        width: 200
        height: 200
        color: "red"

        radius: 0 //0直解，大于0，圆角

        MouseArea {
            anchors.fill: parent //将这个元素的尺寸和位置设置为完全覆盖其父元素的尺寸和位置
            acceptedButtons: Qt.AllButtons
            hoverEnabled: true //此属性为false，鼠标进入，离开，移动不能捕获到

            onPositionChanged: {
                console.log("坐标" + mouseX + "," + mouseY)
            }

            onClicked: {
                if (mouse.button == Qt.LeftButton) {
                    console.log("左键点击")
                } else if (mouse.button == Qt.RightButton) {
                    console.log("右键点击")
                } else if (mouse.button == Qt.MiddleButton) {
                    console.log("中间键点击")
                }
            }
        }
    }
}
