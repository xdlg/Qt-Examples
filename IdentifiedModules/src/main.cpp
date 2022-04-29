#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[])
{
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.addImportPath("qrc:/qml");
  const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
  engine.load(url);

  return app.exec();
}
