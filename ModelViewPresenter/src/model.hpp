#pragma once

#include <QObject>

class Model : public QObject
{
  Q_OBJECT
  Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
  Model(QObject* parent = nullptr);
  unsigned int value() const;

public slots:
  void setValue(unsigned int);
  void resetValue();

signals:
  void valueChanged(unsigned int value);

private:
  unsigned int _value = 0;
};
