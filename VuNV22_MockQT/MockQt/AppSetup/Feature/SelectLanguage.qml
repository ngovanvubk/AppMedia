import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import"qrc:/CommonItem"
Rectangle{
    id : box
    ColumnLayout{
        width: box.width
        height: box.height/2
        RadioButton {
            id: radioButton1
            width: box.width
            height: box.height/4
            checked: (myEngine.getLanguage() === "English")? true : false
            onCheckedChanged: {
                myEngine.setLanguage(radioButton1.text)
                translator.setTranslation(radioButton1.text)
                myEngine.notifyLanguegeChanged(radioButton1.text)
            }
            text: qsTr("English")
            font.pixelSize: 30
        }
        RadioButton {
            id:radioButton2
            width: box.width
            height: box.height/4
            checked:  (myEngine.getLanguage() === "VietNamese")? true : false
            font.pixelSize: 30
            text: qsTr("VietNamese")
            onCheckedChanged: {
                myEngine.setLanguage(radioButton2.text)
                translator.setTranslation(radioButton2.text)
                myEngine.notifyLanguegeChanged(radioButton2.text)
            }
        }

    }
}
