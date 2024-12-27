import QtQuick
import QtQuick.Controls

Button {
    id: mybtn
    property var backColor: "while"
    property var fontPixSize: 20
    property var fontColor: "#ffffff"

    text: "button"

    implicitWidth: 100
    implicitHeight: 30
    hoverEnabled: true

    //设置文本
    contentItem: Label {
        id: btnForeGround
        text: parent.text
        font.family: "微软雅黑"
        font.pixelSize: fontPixSize
        color: fontColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        id: mybtnback
        color: backColor
        radius: 6
        Rectangle {
            width: mybtnback.width * 0.8
            height: mybtnback.height * 0.5
            x: mybtnback.width * 0.05
            y: mybtnback.height * 0.05
            radius: 3
            color: Qt.lighter(mybtnback.color, 1.10)
        }
    }

    onDownChanged: {
        mybtnback.color = down ? Qt.lighter(backColor, 0.9) : backColor
    }

    onHoveredChanged: {
        mybtnback.color = hovered ? Qt.lighter(backColor, 1.9) : backColor
    }
}
