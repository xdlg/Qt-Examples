#include <QColor>
#include <QObject>
#include <QQuickImageProvider>
#include <QTimer>

class ImageGenerator : public QQuickImageProvider
{
  Q_OBJECT

public:
  ImageGenerator(QObject* parent = nullptr);
  QPixmap requestPixmap(const QString& id, QSize* size, const QSize& requestedSize) override;

public slots:
  void updateImage();

signals:
  void newImageReady();

private:
  QTimer* _timer;
  QColor _color;
};
