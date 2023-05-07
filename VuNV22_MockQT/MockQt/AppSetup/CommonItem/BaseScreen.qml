import QtQuick 2.0
import"qrc:/CommonItem/Time.js" as Mytime
Rectangle{
    id: root
    anchors.fill: parent
    border.color: "lightblue"
    border.width: 2
    clip: true
    property int margin: 10
    Rectangle
    {
        id: statusbar
        width: root.width
        height: root.height/6
        color: "black"
        Text {
            id: textDigitalClock
            property string currentTime: Mytime.getCurrentDateTime()
            Timer {
                id: timer
                interval: 1000 // interval in milliseconds
                repeat: true
                running: true
                onTriggered: {
                    // function to be executed every 1 second
                    textDigitalClock.currentTime = Mytime.getCurrentDateTime();
                }
            }
            color:"white"
            font.bold: true
            font.pixelSize: statusbar.height*0.3
            text: qsTr(currentTime)
            anchors.centerIn: parent
        }

    }
}

