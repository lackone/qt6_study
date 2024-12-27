import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function onLoad() {
        loader1.source = "MyButton.qml"
        loader2.source = "MyButton.qml"
    }

    function onRemove() {
        loader1.source = ""
        loader2.source = ""
    }

    function onConfirmClick() {
        console.log("你点击Confirm")
    }

    function onCancelClick() {
        console.log("你点击Cancel")
    }

    Row {
        id: row
        spacing: 20
        padding: 20

        Button {
            id: load
            font.pixelSize: 18
            text: "加载按钮"
            onClicked: onLoad()
        }

        Button {
            id: remove
            font.pixelSize: 18
            text: "移除按钮"
            onClicked: onRemove()
        }
    }

    Column {
        anchors.top: row.bottom

        spacing: 20
        padding: 20

        Loader {
            id: loader1
            onLoaded: {
                item.text = "confirm"
                item.backColor = "red"
                item.clicked.connect(onConfirmClick)
            }
        }

        Loader {
            id: loader2
            onLoaded: {
                item.text = "cancel"
                item.backColor = "blue"
                item.clicked.connect(onCancelClick)
            }
        }
    }
}
