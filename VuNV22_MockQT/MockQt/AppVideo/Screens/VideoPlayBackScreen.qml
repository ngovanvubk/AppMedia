import QtQuick.Controls 2.0
import QtQuick 2.0
import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0

import "qrc:/CommonItem"
Item {
    id: root
    width: 780
    height: 480
    property int margin: 10
    property bool isFullScreen:false
    property bool isClicked: false
    signal clicked
    onClicked: {
        isClicked = true
        timer.restart()
    }

    visible: true
    BaseScreen {
        id: idMusicScreen
        MouseArea{
            anchors.fill: parent
            onClicked: {
                root.clicked()
            }
        }

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
                myEngine.sendInfo2Home(playlistVideo.filename,playButton.isPaused)
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
                myEngine.sendInfo2Home(playlistVideo.filename ,playButton.isPaused)
            }
        }
        MyButton {
            id: fullScreenBtn
            iconNav: "qrc:/Icon/full.png"
            height: root.height/6 - margin*2
            width: height
            anchors{
                top: parent.top
                topMargin : margin
                left: homeButton.right
                leftMargin:  margin
            }
            onClicked: {
                isFullScreen = !isFullScreen
            }
        }
        VideoOutput {
            fillMode:VideoOutput.Stretch
            anchors.centerIn: parent
            width: root.isFullScreen?root.width:300
            height: root.isFullScreen?root.height:150
            id: videoOutput
            source: playlistVideo
            visible: true
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    root.clicked()
                    if(isFullScreen){
                        root.isFullScreen  =!root.isFullScreen
                    }
                    console.log("pressed")
                }
            }
        }
        Timer{
            id:timer
            interval: 30000
            running: true
            repeat: true
            onTriggered: {
                root.isFullScreen = true
                root.isClicked = false
            }
        }
        Column{
            visible: !root.isFullScreen
            anchors{
                bottom: parent.bottom

                horizontalCenter: parent.horizontalCenter
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
                        root.clicked()
                        playButton.isPaused = true
                        console.log("prev mp4")
                        playlistVideo.prevVideo()
                    }
                }
                MyButton {
                    id: playButton
                    property bool isPaused: false
                    iconNav: isPaused? "qrc:/Icon/pause.png":"qrc:/Icon/play.png"
                    height:  70
                    width: 100
                    onClicked: {
                        playlistVideo.requestPlay()
                        root.clicked()
                        if(!isPaused){
                            console.log("start playing mp4")

                        }
                        else{
                            console.log("pause playing mp4")
                        }
                        isPaused =! isPaused
                    }
                }
                MyButton {
                    id: nextButton
                    iconNav: "qrc:/Icon/next.png"
                    height:  70
                    width: 100
                    onClicked: {
                        root.clicked()
                        playButton.isPaused =true
                        console.log("next mp4" )
                        playlistVideo.nextVideo()
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
                    to :playlistVideo.duration
                    stepSize: 1
                    value: playlistVideo.position
                    width: 340
                    height: 50
                    pressed : true
                    onPressedChanged: {
                        console.log(value)
                        playlistVideo.seekSong(value)
                    }
                }
                function formatTime(milliseconds) {
                    let minutes = Math.floor(milliseconds / 60000);
                    let seconds = Math.floor((milliseconds % 60000) / 1000);
                    return minutes.toString().padStart(2, '0') + ':' + seconds.toString().padStart(2, '0');
                }
                Label {
                    id: positionLabel2
                    text: row.formatTime(playlistVideo.duration-slider.value)
                }
            }
            Rectangle{
                id: box
                width: 400
                height:  30
                clip: true
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
                    color:"black"
                    text: qsTr(playlistVideo.filename)
                    x: 0
                    SequentialAnimation on x{
                        id: ani1
                        loops: Animation.Infinite
                        running:   (idText1.contentWidth>box.width? true:false)
                        NumberAnimation{
                            from: 0
                            to: -idText1.contentWidth -50
                            duration: Math.abs(from - to )*50
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
                    color:"black"
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

