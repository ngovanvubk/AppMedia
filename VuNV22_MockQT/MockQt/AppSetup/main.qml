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
                myEngine.requestShow(1)
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
        Rectangle{
            id: columnButton
            width: parent.width/3
            height: parent.height*5/6
            border.color: "lightblue"
            border.width: 2
            anchors{
                top: parent.top
                topMargin: parent.height/6
            }
            ButtonLabel{
                id: langugageButton
                label: qsTr("LID_Language") +translator.emptyStr
                width: columnButton.width
                height: 100
                border.color: "lightblue"
                onClicked: {
                    isPressed = !isPressed
                    if(isPressed){
                        loader.source ="qrc:/Feature/SelectLanguage.qml"
                    }
                    else{
                        loader.source =""
                    }

                    if(volumeButton.isPressed){
                        volumeButton.isPressed =!volumeButton.isPressed
                    }

                }
            }
            ButtonLabel{
                id: volumeButton
                label: qsTr("LID_Volume") +translator.emptyStr
                anchors{
                    top: langugageButton.bottom
                }
                width: columnButton.width
                height: 100
                border.color: "lightblue"
                onClicked: {
                    isPressed = !isPressed
                    if(isPressed){
                        loader.source ="qrc:/Feature/AdjustVolume.qml"
                    }
                    else{
                        loader.source =""
                    }
                    if(langugageButton.isPressed){
                        langugageButton.isPressed =!langugageButton.isPressed
                    }
                }
            }
        }
        Loader{
            id: loader
            width: parent.width*2/3 - 2
            height: parent.height*5/6 - 2
            anchors{
                top: parent.top
                left: columnButton.right
                topMargin: parent.height/6
            }
        }

    }
}
