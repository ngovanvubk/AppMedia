


import QtQuick 2.0
import "qrc:/CommonItem"
Item {
    id: root
    width: 780
    height: 480
    property int margin: 10
   Rectangle{
       anchors.fill: parent
       color: "black"
       MouseArea{
           id:mouse
           anchors.fill: parent
           onClicked: {
               loader.source ="qrc:/Screens/VideoPlayBackScreen.qml"
           }
       }
   }

}

