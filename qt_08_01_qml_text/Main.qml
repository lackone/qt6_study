import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        x: 50
        y: 50
        width: 200
        height: 50
        border.color: "red"
        border.width: 2
        color: "black"

        Text {
            id: txt1
            text: qsTr("我是中国")
            x: 5
            y: 5
            color: "red"
            font.family: "黑体"
            font.pixelSize: 32
            font.bold: true
        }
    }


}
