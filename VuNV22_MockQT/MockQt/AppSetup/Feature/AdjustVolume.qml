import QtQuick 2.0
import QtQuick.Controls 2.0
import"qrc:/CommonItem"
Rectangle{
    id: box
    property alias value: slider.value
    MyButton{
        id: minus
        iconNav: "qrc:/Icon/minus.png"
        width: 30
        height: 30
        anchors{
            verticalCenter: parent.verticalCenter
            right: slider.left
        }
        onClicked:
        {
            slider.value -=1
        }
    }
    MyButton{
        id: plus
        iconNav: "qrc:/Icon/plus.png"
        width: 30
        height: 30
        anchors{
            verticalCenter: parent.verticalCenter
            left : slider.right
        }
        onClicked:
        {
            slider.value +=1
        }
    }
    Slider{
        id: slider
        anchors.centerIn: parent
        from :0
        to :10
        stepSize: 1
        value: myEngine.getVolume()
        width: box.width/2
        height: 50
        onValueChanged:{
            console.log(value)
            myEngine.setVolme(value)
            myEngine.sendVolume2MusicAndVideo(value*10)
        }
        handle: Rectangle{
            x:(slider.value/slider.to)*slider.width -width/2
            anchors.verticalCenter: parent.verticalCenter
            width: 30
            height: 30
            radius: 50
            border.width: 2
            Text {
                id: textValue
                text: box.value
                anchors.centerIn: parent
            }
        }
    }
}
