#ifndef ANIMAL_H
#define ANIMAL_H

#include <QDebug>
#include <QObject>

class Animal : public QObject
{
    Q_OBJECT
public:
    explicit Animal(QObject *parent = nullptr, QString name="");
    ~Animal();

    static QString name;
    static int count;

    void sayHello(QString message);


signals:
};

#endif // ANIMAL_H
