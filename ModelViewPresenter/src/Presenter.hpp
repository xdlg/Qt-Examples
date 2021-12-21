#pragma once

#include <QObject>
#include <QtQml/qqmlregistration.h>
#include "Model.hpp"

class Presenter: public QObject
{
  Q_OBJECT
  Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
  QML_ELEMENT

public:
  Presenter(QObject* parent = nullptr);
  unsigned int value() const;

public slots:
  void setValue(unsigned int);
  void resetValue();

signals:
  void valueChanged(unsigned int value);

private:
  Model _model;
};
