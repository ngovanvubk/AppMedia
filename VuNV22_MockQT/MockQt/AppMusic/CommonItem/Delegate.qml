import QtQuick 2.0


Rectangle{
    id:rect
    anchors.centerIn: parent
    property alias texttStr1: text1.text
    property alias texttStr2: text2.text
    property alias texttStr3: text3.text
    clip: true

    Text {
        id: text1
        font.pixelSize: 20
        text: qsTr("text")
    }
    Text {
        id: text1Clone
        font.pixelSize: 20
        x: text1.contentWidth + 20 + text1.x
        text: text1.text
    visible: text1.contentWidth < rect.width ? false : true
    }

    Text {
        id: text2
        y : rect.height/3
        font.pixelSize: 20
        text: qsTr("text")

    }
    Text {
        id: text2Clone
        x: text2.contentWidth+ 20 + text2.x
        y : rect.height/3
        font.pixelSize: 20
        text: text2.text
        visible: text2.contentWidth < rect.width ? false : true
    }
    Text {
        id: text3
        y : 2*(rect.height/3)
        font.pixelSize: 20
        text: qsTr("text")
    }
    Text {
        id: text3Clone
        x: text3.contentWidth+ 20 + text3.x
        y : 2*(rect.height/3)
        font.pixelSize: 20
        text: text3.text
        visible: text3.contentWidth < rect.width ? false : true
    }
    SequentialAnimation{
        id: animation
        running: false
        NumberAnimation {
            target: text1
            property: "x"
            from: 0
            to : (text1.contentWidth>=rect.width)? (-text1.contentWidth-20) : 0
            duration: (text1.contentWidth>=rect.width)? (text1.contentWidth)*40 : 0
            //                duration: 1000

        }

        PauseAnimation { duration: 1000 }
        NumberAnimation {
            target: text2
            property: "x"
            from: 0
            to : (text2.contentWidth>=rect.width)? (-text2.contentWidth-20) : 0
            duration: (text2.contentWidth>=rect.width)? (text2.contentWidth)*40 : 0
            //                duration: 1000
        }

        PauseAnimation { duration: 1000 }
        NumberAnimation {
            target: text3
            property: "x"
            from: 0
            to : (text3.contentWidth>=rect.width)? (-text3.contentWidth-20) : 0
            duration: (text3.contentWidth>=rect.width)? (text3.contentWidth)*40 : 0
            //                duration: 1000
        }

    }
    Timer{
        id:timer
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            if(text1.x === -text1.contentWidth){
                text1.x = 0
            }
            if(text2.x === -text2.contentWidth){
                text2.x = 0
            }
            if(text3.x === -text3.contentWidth){
                text3.x = 0
            }
            animation.running = true
        }
    }

}
