#include "Model.hpp"
#include <QDebug>

Model::Model(QObject* parent): QObject(parent) {}

unsigned int Model::value() const
{
  qDebug() << "Get value (model)";
  return _value;
}

void Model::setValue(unsigned int value)
{
  if (_value != value) {
    qDebug() << "Set value (model)";
    _value = value;
    emit valueChanged(_value);
  }
}

void Model::resetValue()
{
  if (_value != 0) {
    qDebug() << "Reset value (model)";
    _value = 0;
    emit valueChanged(_value);
  }
}
