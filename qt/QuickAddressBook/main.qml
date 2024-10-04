import QtQuick 2.9
import QtQuick.Window 
import QtQuick.Controls 2.12
import QtQuick.Layouts 
import QtQml.Models

Window {
    id:mainWindow
    visible: true
    width: 640
    height: 480
    color: "darkgray"
    title: qsTr("Address Book")

    ColumnLayout {
        id: mainWindowLayout
        anchors.left: parent.left; anchors.right: parent.right
        spacing: 0
            Button{
                id:addButton
                anchors.left: parent.left
                anchors.right: parent.right
                text:"Add..."
                font.pointSize: 24
                onClicked: newAddressPopup.open()
	        }
            Repeater{
                id:addessListViewer
                model: addressList
                anchors.left: parent.left
                anchors.right: parent.right

            }
    }
    ListModel {
        id:addressList
	}

    Text {
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pointSize: 42
        text: "Hello World!"
    }
}
