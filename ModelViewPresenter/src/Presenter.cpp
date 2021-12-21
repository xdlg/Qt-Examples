#include "Presenter.hpp"
#include <QDebug>

Presenter::Presenter(QObject* parent): QObject(parent), _model(this)
{
  QObject::connect(&_model, &Model::valueChanged, this, &Presenter::valueChanged);
}

unsigned int Presenter::value() const
{
  qDebug() << "Get value (presenter)";
  return _model.value();
}

void Presenter::setValue(unsigned int value)
{
  qDebug() << "Set value (presenter)";
  _model.setValue(value);
}

void Presenter::resetValue()
{
  qDebug() << "Reset value (presenter)";
  _model.resetValue();
}
