#include "image_generator.hpp"
#include <QRandomGenerator>

ImageGenerator::ImageGenerator(QObject* parent) : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
  _color = QColor("black");
  _timer = new QTimer(this);
  connect(_timer, &QTimer::timeout, this, &ImageGenerator::updateImage);
  _timer->setInterval(1000);
  _timer->setSingleShot(false);
  _timer->start();
}

QPixmap ImageGenerator::requestPixmap(const QString& id, QSize* size, const QSize& requestedSize)
{
  int width = 100;
  int height = 100;

  if (size) {
    *size = QSize(width, height);
  }

  QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
    requestedSize.height() > 0 ? requestedSize.height() : height);
  pixmap.fill(_color);

  return pixmap;
}

void ImageGenerator::updateImage()
{
  _color = QColor(QRandomGenerator::global()->generate());
  emit newImageReady();
}
