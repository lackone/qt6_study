import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        anchors.centerIn: parent

        CProgressBar {
            id: pb1
            lineWidth: 10
            value: 0.13
            size: 150
            pcolor: "aqua"
            scolor: "azure"

            Text {
                text: parseInt(pb1.value * 100) + "%"
                anchors.centerIn: parent
                font.pointSize: 20
                color: pb1.pcolor
            }
        }

        CProgressBar {
            id: pb2
            lineWidth: 10
            value: 0.50
            size: 150
            pcolor: "aqua"
            scolor: "azure"

            Text {
                text: parseInt(pb2.value * 100) + "%"
                anchors.centerIn: parent
                font.pointSize: 20
                color: pb1.pcolor
            }
        }

        CProgressBar {
            id: pb3
            lineWidth: 20
            value: 0.20
            size: 150
            pcolor: "black"
            scolor: "red"

            Text {
                text: parseInt(pb3.value * 100) + "%"
                anchors.centerIn: parent
                font.pointSize: 20
                color: pb1.pcolor
            }
        }
    }
}
