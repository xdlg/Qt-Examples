import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import Presenter 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ModelViewPresenter")

    Presenter {
      id: presenter
    }

    ColumnLayout {
      anchors.centerIn: parent

      SpinBox {
        id: spinBox
        Layout.alignment: Qt.AlignHCenter
        value: presenter.value
        onValueChanged: presenter.value = value
      }

      Button {
        Layout.alignment: Qt.AlignHCenter
        text: "Reset"
        onClicked: presenter.resetValue()
      }
    }
}
