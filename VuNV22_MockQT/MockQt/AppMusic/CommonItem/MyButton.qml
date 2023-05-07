import QtQuick 2.0
Rectangle{
    id: button
    width: 100
    height: 100
    property alias iconNav: idIcon.source
    signal clicked
    color: "white"
    opacity: mouse.pressed? 0.5:1
    border.width: 2
    border.color: "black"
    Image {
        id:idIcon
        source: "qrc:/Icon/back.png"
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
    }
    MouseArea{
        id: mouse
        anchors.fill: parent
        onClicked: {
            button.clicked()
        }
    }
}


