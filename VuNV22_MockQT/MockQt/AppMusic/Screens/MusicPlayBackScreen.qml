import QtQuick.Controls 2.0
import QtQuick 2.0
import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0

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
                myEngine.requestShow(1)
                myEngine.sendInfo2Home(myEngine.title ,myEngine.artist , myEngine.coverart ,playButton.isPaused)
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
                myEngine.sendInfo2Home(myEngine.title ,myEngine.artist , myEngine.coverart , playButton.isPaused)
            }
        }
        MyButton {
            id: listButton
            iconNav: "qrc:/Icon/list.png"
            height: root.height/6 - margin*2
            width: height
            anchors{
                top: parent.top
                topMargin : margin
                left: homeButton.right
                leftMargin:  margin
            }
            onClicked: {
                loader.source = "qrc:/Screens/MusicListScreen.qml"
            }
        }
        Rectangle{
            id: coverart
            width: root.width*1/2 -100
            height: width
            color: "black"
            anchors{
                top: displayInforsong.top
                left: displayInforsong.right
                leftMargin: 20
            }
            Image {
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("pressed")
                    }
                }
                source: myEngine.coverart
            }
        }
        Rectangle{
            id: displayInforsong
            width: parent.width*2/4
            height: parent.height/3
            clip :true
            anchors{
                top: parent.top
                topMargin: root.height/6 +10
                left: parent.left
                leftMargin: 40
            }
            Delegate{
                color: "lightblue"
                radius: 10
                border.color: "Black"
                border.width: 2
                anchors.fill: parent
                texttStr1: myEngine.title
                texttStr2: myEngine.album
                texttStr3: myEngine.artist
            }
        }
        Column{
            anchors{
                top: displayInforsong.bottom
                topMargin: 20
                left: parent.left
                leftMargin: 40
            }
            Row{
                id: playbackButton
                spacing: 20
                MyButton {
                    id: prevButton
                    iconNav: "qrc:/Icon/prev.png"
                    height:  70
                    width: 100
                    onClicked: {
                        playButton.isPaused = false
                        console.log("prev mp3")
                        myEngine.prev()
                        myEngine.getData(playlistSong.currentIndex)
                    }
                }
                MyButton {
                    id: playButton
                    property bool isPaused: false
                    iconNav: isPaused? "qrc:/Icon/pause.png":"qrc:/Icon/play.png"
                    height:  70
                    width: 100
                    onClicked: {
                        myEngine.requestPlay()
                        if(!isPaused){
                            console.log("start playing mp3")
                        }
                        else{
                            console.log("pause playing mp3")
                        }
                        isPaused =! isPaused
                    }
                }
                Connections{
                    target: myEngine
                    onMediaIschanged:{
                        playButton.isPaused = !playButton.isPaused
                    }
                }

                MyButton {
                    id: nextButton
                    iconNav: "qrc:/Icon/next.png"
                    height:  70
                    width: 100
                    onClicked: {
                        playButton.isPaused = false
                        myEngine.next()
                        console.log("next mp3" +playlistSong.currentIndex)
                        myEngine.getData(playlistSong.currentIndex)
                    }
                }
            }
            RowLayout {
                id: row
                Label {
                    id: positionLabel1
                    text: row.formatTime(slider.value)

                }
                Slider{
                    id: slider
                    from :0
                    to : myEngine.duration
                    stepSize: 1
                    value: myEngine.position
                    width: 340
                    height: 50
                    pressed : true
                    onPressedChanged: {
                        myEngine.seekSong(value)
                    }
                }
                function formatTime(milliseconds) {
                    let minutes = Math.floor(milliseconds / 60000);
                    let seconds = Math.floor((milliseconds % 60000) / 1000);
                    return minutes.toString().padStart(2, '0') + ':' + seconds.toString().padStart(2, '0');
                }
                Label {
                    id: positionLabel2
                    text: row.formatTime(myEngine.duration-slider.value)
                }
            }

        }
    }
}

