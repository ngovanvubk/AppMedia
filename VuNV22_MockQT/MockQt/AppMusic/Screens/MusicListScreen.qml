


import QtQuick 2.0
import "qrc:/CommonItem"
Item {
    id: root
    width: 780
    height: 480
    property int margin: 10
    BaseScreen {
        id: idsetupScreen
        MyButton {
            id: backButton
            iconNav: "qrc:/Icon/back.png"
            height: root.height/6 - margin*2
            width: height
            anchors{
                top: parent.top
                topMargin : margin
                left: parent.left
                leftMargin:  margin
            }
            onClicked: {
                loader.source ="qrc:/Screens/MusicPlayBackScreen.qml"
            }
        }
        MyButton {
            id: homeButton
            iconNav: "qrc:/Icon/home.png"
            height: root.height/6 - margin*2
            width: height
            anchors{
                top: parent.top
                topMargin : margin
                left: backButton.right
                leftMargin:  margin
            }
            onClicked: {
                 myEngine.requestShow(1)
            }
        }

        // listview list song
        ListView{
            id: idListView
            anchors{
                top: homeButton.bottom
                topMargin :margin
            }
            width: parent.width
            height: root.height*5/6 - margin*2
            model: SongList
            delegate:
                Rectangle{
                id: box
                width: 780
                height:  50
                color: "white"
                border.color: "lightblue"
                border.width: 1
                Style{
                    id: myStyle
                }
                MyButton {
                    id: idPlaying
                    visible: (index === playlistSong.currentIndex)
                    iconNav: "qrc:/Icon/Playing.png"
                    height: 50
                    width: 70
                    z : 3
                    anchors{

                        right: box.right
                    }
                }
                Text {
                    id: idText1
                    anchors.verticalCenter: box.verticalCenter
                    verticalAlignment: Text.AlignVCenter
                    width: parent.width
                    height:  50
                    font.pixelSize: myStyle.scaleText*height*1.5
                    color:(index === playlistSong.currentIndex) ? "red":"black"
                    text: modelData
                    x: 0
                    SequentialAnimation on x{
                        id: ani1
                        loops: Animation.Infinite
                        running:  (index === playlistSong.currentIndex) ? (idText1.contentWidth>box.width? true:false) : false
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
                    verticalAlignment: Text.AlignVCenter
                    height:  50
                    color:(index === playlistSong.currentIndex) ? "red":"black"
                    font.pixelSize: myStyle.scaleText*height*1.5
                    anchors{
                        verticalCenter: box.verticalCenter
                        left: idText1.left
                        leftMargin: idText1.contentWidth+50
                    }
                    visible: idText1.contentWidth>box.width? true:false
                }

            }


        }

    }
}

