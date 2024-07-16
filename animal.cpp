#include "animal.h"

Animal::Animal(QObject *parent, QString name) : QObject{parent} {
    qInfo() << "Constructed";
    this->name = name;
    qInfo() << "Animal name param" << &name << "=" << name;
    qInfo() << "Animal name" << &this->name << "=" << name;
    count++;
}

Animal::~Animal() {
    count--;
    qInfo() << this << "Deconstructer";
}

void Animal::sayHello(QString message) {
    // SAME!
    qInfo() << message << "from" << name << "at" << &name;
    qInfo() << message << "from" << this->name << "at" << &this->name;
}
