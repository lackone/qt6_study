import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //动画
    Rectangle {
        id: rect1
        x: 30
        y: 30
        width: 50
        height: 50
        color: "red"
    }

    Rectangle {
        id: rect2
        x: 30
        y: 100
        width: 50
        height: 50
        color: "blue"
    }

    PropertyAnimation {
        id: ani
        targets: [rect1, rect2]
        properties: "width, x"
        from: 30
        to: 500
        duration: 1000
    }

    //鼠标区域
    MouseArea {
        anchors.fill: parent
        onClicked: ani.running = true
    }

    Rectangle {
        id: rect3
        anchors.fill: parent
        color: "white"

        Rectangle {
            id: rect4
            x: 0
            y: 0
            width: 50
            height: 480
            color: "orange"
        }
    }

    Timer {
        id: timer1
        interval: 1000
        repeat: true //重复触发
        running: true //启动定时器

        triggeredOnStart: false //true定时器在启动后立即触发，然后根据指定的时间间隔触发

        onTriggered: {
            if (rect4.x + rect4.width < rect3.width) {
                rect4.x += 50
            } else {
                rect4.x = 0
            }
        }
    }

    Rectangle {
        id: rect5
        width: 200
        height: 200
        color: "orange"
        anchors.centerIn: parent

        QtObject {
            id: attr
            property int cnt
            Component.onCompleted: {
                cnt = 10
            }
        }
    }

    Text {
        id: txt
        anchors.centerIn: parent
        color: "white"
        font.pixelSize: 150
    }

    Timer {
        id: timer2
        interval: 1000
        repeat: true
        triggeredOnStart: true
        onTriggered: {
            txt.text = attr.cnt
            attr.cnt = attr.cnt - 1
            if (attr.cnt < 0) {
                timer2.stop()
            }
        }
    }

    Button {
        id: btn
        width: 200
        text: "开始倒计时"
        anchors.top: rect5.bottom
        anchors.horizontalCenter: rect5.horizontalCenter

        onClicked: {
            timer2.stop()
            attr.cnt = 10
            timer2.start()
        }
    }

    property int range_value: 65
    property int now_range: 0

    //画布大小
    property int mw: 300
    property int mh: 300
    property int linewidth: 3

    //画圆
    property double r: mh / 2 //圆心
    property double cr: r - 20 * linewidth //圆轴长度

    //绘制曲线
    property int sx: 0
    property int sy: mh / 2
    property int axlength: mw //画轴长度
    property double wavewidth: 0.01 //波浪宽度
    property double waveheight: 5 //波浪高度
    property double speed: 0.08 //波浪速度
    property double xoffset: 0 //波浪x偏移量

    Canvas {
        id: mycan
        width: mw
        height: mh
        anchors.centerIn: parent

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, mw, mh)
            ctx.beginPath()
            ctx.strokeStyle = "red"
            ctx.arc(r, r, cr + 2, 0, 2 * Math.PI)
            ctx.stroke()

            ctx.beginPath()
            ctx.arc(r, r, cr, 0, 2 * Math.PI)
            ctx.clip()

            //显示曲线
            ctx.save()
            var points = []
            ctx.beginPath()

            for (var x = sx; x < sx + axlength; x += 20 / axlength) {
                var y = -Math.sin((sx + x) * wavewidth + xoffset)
                var dy = mh * (1 - now_range / 100)
                points.push([x, dy + y * waveheight])
                ctx.lineTo(x, dy + y * waveheight)
            }

            //显示波浪
            ctx.lineTo(axlength, mh)
            ctx.lineTo(sx, mh)
            ctx.lineTo(points[0][0], points[0][1])
            ctx.fillStyle = "blue"
            ctx.fill()
            ctx.restore()

            //显示百分数
            ctx.save()
            var size = 0.4 * cr
            ctx.font = size + "px Arial"
            ctx.textAlign = "center"
            ctx.fillStyle = "rgba(0, 255, 0, 0.8)"
            ctx.fillText(now_range + "%", r, r + size / 2)
            ctx.restore()

            //增加rang
            if (now_range <= range_value) {
                now_range = now_range + 1
            }
            if (now_range > range_value) {
                now_range = now_range - 1
            }
            xoffset = xoffset + speed
        }

        Timer {
            id: timer3
            running: false
            repeat: true
            interval: 100
            onTriggered: {
                parent.requestPaint()
            }
        }
    }

    Button {
        id: btn2
        width: 80
        height: 30
        anchors.horizontalCenter: parent.horizontalCenter
        text: "开始运行"
        onClicked: {
            if (timer3.running == false) {
                timer3.start()
                btn2.text = "停止运行"
            } else {
                timer3.stop()
                btn2.text = "开始运行"
            }
        }
    }
}
