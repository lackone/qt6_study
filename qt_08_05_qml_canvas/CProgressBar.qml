import QtQuick

Item {
    id: progressbar

    property int size: 150
    property int lineWidth: 5
    property real value: 0

    property color pcolor: "azure"
    property color scolor: "aqua"

    property int duration: 800

    width: size
    height: size

    onValueChanged: {
        mycanvas.degree = value * 360
    }

    Canvas {
        id: mycanvas

        property real degree: 0

        anchors.fill: parent
        antialiasing: true

        onDegreeChanged: {
            requestPaint()
        }

        onPaint: {
            var ctx = getContext("2d")
            var x = progressbar.width / 2
            var y = progressbar.height / 2

            var radius = progressbar.size / 2 - progressbar.lineWidth
            var start = (Math.PI / 180) * 270
            var full = (Math.PI / 180) * (270 + 360)
            var progress = (Math.PI / 180) * (270 + degree)

            ctx.reset()

            ctx.lineCap = 'round'
            ctx.lineWidth = progressbar.lineWidth

            ctx.beginPath()
            ctx.arc(x, y, radius, start, full)
            ctx.strokeStyle = progressbar.scolor
            ctx.stroke()

            ctx.beginPath()
            ctx.arc(x, y, radius, start, progress)
            ctx.strokeStyle = progressbar.pcolor
            ctx.stroke()
        }

        Behavior on degree {

            NumberAnimation {
                duration: progressbar.duration
            }
        }
    }
}
