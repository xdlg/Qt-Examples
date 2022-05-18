import QtQuick
import QtQuick.Window

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Image Generator")

  Connections {
    target: imageGenerator
    function onNewImageReady() {
      image.refresh();
    }
  }

  Image {
    id: image
    anchors.fill: parent
    source: "image://imageGenerator/dynamicImage"
    // Necessary to reload the image after changing the source
    cache: false

    function refresh() {
      var oldSource = source
      source = ""
      source = oldSource
    }
  }
}
