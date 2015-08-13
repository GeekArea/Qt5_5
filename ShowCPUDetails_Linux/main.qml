import QtQuick 2.4
import QtQuick.Controls 1.4

ApplicationWindow {
    title: qsTr("CPU Details from /proc/cpuinfo")
    width: 640
    height: 480
    visible: true

    ScrollView //used for variable data length to display
    {
        anchors.fill: parent
        verticalScrollBarPolicy : Qt.ScrollBarAlwaysOn

        ListView {                  // view for CPU data
            id:viewCpuDetails
            model: cpuInfoModel     // model data coming from C++
            delegate: Rectangle {   // displaying each item
                height: 25
                width: parent.width
                Text {
                    color: "Red"
                    text: display }
            }//viewCpuDetails delegate
        } //viewCpuDetails
    } // ScrollView
} //ApplicationWindow
