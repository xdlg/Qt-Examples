#include "image_generator.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[])
{
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  ImageGenerator* imageGenerator = new ImageGenerator();

  // Make the image generator available in QML as a general object
  engine.rootContext()->setContextProperty("imageGenerator", imageGenerator);
  // Make the image generator available in QML as an image provider
  engine.addImageProvider("imageGenerator", imageGenerator);

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  engine.load(url);

  return app.exec();
}
