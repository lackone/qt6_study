import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: 300
        height: 300
        color: "red"

        Rectangle {
            width: 50
            height: 50
            x: 10
            y: 10
            color: "blue"
        }
    }
}
