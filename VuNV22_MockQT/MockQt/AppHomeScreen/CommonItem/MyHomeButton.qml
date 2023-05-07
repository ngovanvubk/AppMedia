import QtQuick 2.0


Rectangle{
    id: button
    clip: true
    property alias label1: idlabel1.text
    property alias label2: idlabel2.text
    property alias label3: idlabel3.text
    property alias fontsize: idlabel1.font.pixelSize
    property alias labelColor: idlabel1.color
    property alias appIconSource: idIcon.source
    property bool active: false
    signal clicked
    color: "#f5f5f5"
    opacity: mouse.pressed? 0.5:1
    border.width: 2
    border.color: "black"
    Text {
        id: idlabel1
        width: idIcon.width
        height: button.height/5
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: parent.top
        }
        font.bold: true
        text: qsTr("text1")
        font.pixelSize: 30
        color: labelColor
    }
    Image {
        id: idIcon
        height:  button.height*2/5
        width:  button.width *0.5
        anchors{
            horizontalCenter: parent.horizontalCenter
            top : idlabel1.bottom

        }
        source: "qrc:/setting.png"
        onSourceChanged: {
            console.log("source is changed")
        }
    }
    Text {
        id: idlabel2
        width: button.width
        height: button.height/5
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors{
            top : idIcon.bottom
            topMargin: 20
        }
        SequentialAnimation on x{
            id: ani1
            loops: Animation.Infinite
            running:  active ? (idlabel2.contentWidth>idIcon.width? true:false) : false
            NumberAnimation{
                from: 0
                to: -idlabel2.contentWidth -50
                duration:Math.abs(from - to )*30
            }

        }
        elide: active ? Text.ElideNone:Text.ElideRight
        text: qsTr("text2")
        font.pixelSize: 30
        color: labelColor
    }
    Text {
        id: idlabel2clone
        width: button.width
        height: button.height/5
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors{
            top : idIcon.bottom
            topMargin: 20
            left: idlabel2.left
            leftMargin: idlabel2.contentWidth +100
        }
        elide: active ? Text.ElideNone:Text.ElideRight
        visible: idlabel2.contentWidth>idIcon.width? true:false
        text: idlabel2.text
        font.pixelSize: 30
        color: labelColor
    }

    Text {
        id: idlabel3
        width: button.width
        height: button.height/5
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        anchors{
            top : idlabel2.bottom

        }
        SequentialAnimation on x{
            id: ani2
            loops: Animation.Infinite
            running:  active ? (idlabel3.contentWidth>idIcon.width? true:false) : false
            NumberAnimation{
                from: 0
                to: -idlabel3.contentWidth -50
                duration:Math.abs(from - to )*30
            }
        }
        elide: active ? Text.ElideNone:Text.ElideRight
        text: qsTr("text3")
        font.pixelSize: 30
        color: labelColor
    }
    Text {
        id: idlabel3clone
        width: button.width
        height: button.height/5
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors{
            top : idlabel2.bottom
            left: idlabel3.left
            leftMargin: idlabel3.contentWidth+50
        }
        elide: active ? Text.ElideNone:Text.ElideRight
        visible: idlabel3.contentWidth>idIcon.width? true :false
        text: idlabel3.text
        font.pixelSize: 30
        color: labelColor
    }
    MouseArea{
        id: mouse
        anchors.fill: parent
        onClicked: {
            button.clicked()
        }
    }
}




