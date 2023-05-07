import QtQuick 2.0

Rectangle{
    id: button
    width: 100
    height: 100
    property alias label: idlabel.text
    property alias fontsize: idlabel.font.pixelSize
    property alias labelColor: idlabel.color
    property bool isPressed: false
    signal clicked
    color: "#f5f5dc"
    opacity: isPressed? 0.5:1
    border.width: 2
    border.color: "black"
    Text {
        id: idlabel
        //        anchors.fill: parent
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 20
        }
        font.bold: isPressed? true: false
        horizontalAlignment: Text.AlignLeft
        text: qsTr("text")
        font.pixelSize: 30
        color: isPressed?"red": "black"
    }
    MouseArea{
        id: mouse
        anchors.fill: parent
        onClicked: {

            button.clicked()
        }
    }
}
