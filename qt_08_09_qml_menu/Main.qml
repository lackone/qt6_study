import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 900
    height: 550
    visible: true
    title: qsTr("Hello World")

    menuBar: MenuBar {
        delegate: GMenuBar {}
        background: GMenuBarBg {}

        Menu {
            delegate: GMenuBarItemBg {}
            background: GMenuBarBg {}
            title: qsTr("教育课程")
            Action {
                text: qsTr("linux内核分析")
                onTriggered: {
                    console.log("linux内核分析")
                }
            }
            Action {
                text: qsTr("BAT大厂")
            }
            Action {
                text: qsTr("音视频开发")
            }
            Action {
                text: qsTr("后台开发")
            }
        }

        Menu {
            delegate: GMenuBarItemBg {}
            background: GMenuBarBg {}
            title: qsTr("开发课程")
            Action {
                text: qsTr("C/C++")
            }
            Action {
                text: qsTr("mysql")
            }
            Action {
                text: qsTr("数据结构")
            }
            Action {
                text: qsTr("opencv专栏")
            }
        }

        Menu {
            title: qsTr("讲师团队")
            Action {
                text: qsTr("小张")
            }
            Action {
                text: qsTr("小李")
            }
            Action {
                text: qsTr("小明")
            }
            Action {
                text: qsTr("小王")
            }
            Action {
                text: qsTr("小几")
            }
            Action {
                text: qsTr("以遥")
            }

            delegate: GMenuBarItemBg {}
            background: GMenuBarBg {}
        }
    }
}
