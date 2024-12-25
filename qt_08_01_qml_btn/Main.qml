import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //定义变量
    property int count:1

    Button {
        id: btn1
        x: 200
        y: 200
        height: 45
        width: 100

        text: qsTr("测试")

        icon.source: "/images/login01.bmp"
        icon.color: "transparent"

        //单出事件
        onClicked: {
            console.log("点击了" + count++)
        }
    }
}
