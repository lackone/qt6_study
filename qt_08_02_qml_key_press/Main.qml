import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect
        anchors.centerIn: parent

        width: 200
        height: 200
        color: "red"

        focus: true //不设置焦点，获取不了键盘事件

        Keys.onPressed: {
            console.log("key " + event.key)
            console.log("nativeScanCode " + event.nativeScanCode)
            console.log("text " + event.text)
        }

        Keys.onTabPressed: {
            console.log("按下tab")
        }

        Keys.onSpacePressed: {
            console.log("按下space")
        }
    }
}
