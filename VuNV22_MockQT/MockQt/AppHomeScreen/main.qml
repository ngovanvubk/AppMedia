import QtQuick 2.9
import"qrc:/CommonItem"
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
Item {
    id: root
    width: 780
    height: 480
    BaseScreen {
        id: homeScreen
        property alias currentPage: view.currentIndex
        property int margin: 30

        Connections{
            target: myEngine
            onSendInfo2QmlMusic:{
                audioButton.label2 = qsTr(title)
                audioButton.label3 = qsTr(artist)
                audioButton.active = isPaused
                console.log(title)
                console.log(artist)
            }
        }
        Connections{
            target: myEngine
             onSendInfo2QmlVideo:{
                 videoButton.label2 = qsTr(fileName)
                 videoButton.active = isPaused
                 console.log(fileName)
             }
        }

        SwipeView{
            anchors{
                leftMargin: homeScreen.margin
                topMargin: homeScreen.height/6+homeScreen.margin
            }
            id: view
            currentIndex: 0
            anchors.fill: parent
            Item {
                id: firstPage
                Row{
                    spacing: homeScreen.margin
                    MyHomeButton{
                        id : audioButton
                        border.color:"lightblue"
                        border.width:2
                        label1: qsTr("LID_Music") + translator.emptyStr
                        label2: qsTr("LID_unknow_Music") + translator.emptyStr
                        label3: qsTr("LID_Unknow_Music") + translator.emptyStr
                        active: false
                        appIconSource: "qrc:/music.png"
                        width: (root.width-homeScreen.margin*3)/2
                        height : root.height*5/6 - homeScreen.margin*2
                        onClicked: {
                            myEngine.requestShow(2)
                            myEngine.registerDbusMusic()
                        }
                    }
                    MyHomeButton{
                        id : videoButton
                        border.color:"lightblue"
                        border.width:2
                        label1: qsTr("LID_Video") + translator.emptyStr
                        label2: qsTr("LID_Unknow_Video") + translator.emptyStr
                        label3: qsTr("") + translator.emptyStr
                        appIconSource: "qrc:/video.png"
                        width: (root.width-homeScreen.margin*3)/2
                        height : root.height*5/6 - homeScreen.margin*2
                        onClicked: {
                            myEngine.requestShow(3)
                            myEngine.registerDbusVideo()
                        }
                    }
                }
            }
            Item {
                id: secondPage
                Row{
                    spacing: homeScreen.margin
                    MyHomeButton{
                        id : settingButton
                        border.color:"lightblue"
                        border.width:2
                        label1: qsTr("LID_Setting") + translator.emptyStr
                        label2: qsTr("") + translator.emptyStr
                        label3: qsTr("") + translator.emptyStr
                        appIconSource: "qrc:/setting.png"
                        width: (root.width-homeScreen.margin*3)/2
                        height : root.height*5/6 - homeScreen.margin*2
                        onClicked: {
                            myEngine.requestShow(4)
                        }
                    }
                }

            }
        }
        PageIndicator{
            id : indicator
            count: view.count
            currentIndex: view.currentIndex
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

}
