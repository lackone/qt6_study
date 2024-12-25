import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: test
        text: qsTr("text")
    }

    Column {
        anchors.centerIn: parent

        Image {
            id: img1
            source: "/images/qq.jpg"
            fillMode: Image.Pad //
        }

        Image {
            id: img2
            height: 80
            width: 80
            //anchors.centerIn: parent
            source: "/images/qq.jpg"
            //fillMode: Image.Pad //填充模式不会变形
            //fillMode: Image.PreserveAspectFit //按比例缩放，不裁剪
            //fillMode: Image.TileVertically //水平填充
            //fillMode: Image.TileHorizontally //垂直填充
        }
    }
}
