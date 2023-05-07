import QtQuick 2.0


Rectangle{
    id: box
    width: parent.width
    height:  30
    color: "white"
    border.color: "lightblue"
    border.width: 1
    Style{
        id: myStyle
    }
    Text {
        id: idText1
        anchors.verticalCenter: box.verticalCenter
        width: parent.width
        height:  30
        font.pixelSize: myStyle.scaleText*height*1.5
        color: (box.ListView.currentIndex === playlistSong.currentIndex) ? "red":"black"
        text: modelData
        x: 0
        SequentialAnimation on x{
            id: ani1
            loops: Animation.Infinite
            running:  box.ListView.isCurrentItem ? (idText1.contentWidth>box.width? true:false) : false
            NumberAnimation{
                from: 0
                to: -idText1.contentWidth -50
                duration: Math.abs(from - to )*10
            }
            NumberAnimation{
                to :0
                duration: 0
            }
        }
    }
    Text {
        id: textclone
        text: qsTr(idText1.text)
        width: parent.width
        height:  30
        color: ListView.currentIndex ? "red":"black"
        font.pixelSize: myStyle.scaleText*height*1.5
        anchors{
            verticalCenter: box.verticalCenter
            left: idText1.left
            leftMargin: idText1.contentWidth+50
        }
        visible: idText1.contentWidth>box.width? true:false
    }
}
