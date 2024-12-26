import QtQuick
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //layout布局
    RowLayout {
        spacing: 10
        x: 10
        y: 10

        Rectangle {
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100
            Layout.alignment: Qt.AlignLeft
            color: "red"
        }

        Rectangle {
            Layout.preferredWidth: 50
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignLeft
            color: "cyan"
        }

        Rectangle {
            Layout.preferredWidth: 100
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignRight
            color: "black"
        }
    }
    ColumnLayout {
        width: 200
        x: 200
        y: 200

        Rectangle {
            Layout.alignment: Qt.AlignCenter
            color: "yellow"
            Layout.preferredWidth: 50
            Layout.preferredHeight: 50
        }

        Rectangle {
            Layout.alignment: Qt.AlignLeft
            color: "blue"
            Layout.preferredWidth: 50
            Layout.preferredHeight: 50
        }

        Rectangle {
            Layout.alignment: Qt.AlignRight
            color: "black"
            Layout.preferredWidth: 50
            Layout.preferredHeight: 50
        }
    }
}
