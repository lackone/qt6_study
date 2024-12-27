import QtQuick
import QtQuick.Controls

MenuBarItem {
    id: menubaritem
    height: 40
    width: 120

    //字体
    font: Qt.font({
                      "family": "微软雅黑",
                      "pointSize": 10,
                      "weight": Font.Bold
                  })

    //颜色
    contentItem: Text {
        text: menubaritem.text
        font: menubaritem.font
        opacity: enabled ? 1.0 : 0.3
        color: "white"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitHeight: 40
        implicitWidth: 120
        opacity: enabled ? 1.0 : 0.3
        color: menubaritem.highlighted ? "yellowgreen" : "transparent"
    }
}
