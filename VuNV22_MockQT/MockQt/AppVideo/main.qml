import QtQuick 2.0
import "qrc:/CommonItem"
Item {
    id: root
    width: 780
    height: 480

    Loader{
        id:loader
        source: "qrc:/Screens/VideoPlayBackScreen.qml"
    }

}
