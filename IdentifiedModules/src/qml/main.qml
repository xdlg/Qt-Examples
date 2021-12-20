import QtQuick
import QtQuick.Window

import components 1.0 as Components

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("IdentifiedModules")

  Components.CustomComponent { anchors.centerIn: parent }
  Components.AnotherCustomComponent { anchors.centerIn: parent }
}
