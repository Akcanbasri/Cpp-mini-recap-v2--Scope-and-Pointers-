#ifndef TEST_H
#define TEST_H

#include "animal.h"
#include <QDebug>
#include <QObject>

class Test : public QObject {
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    ~Test();

    Animal *dog;
    void doStuff();
    static void doOtherStuff();
    void doStuff2();
signals:
};

#endif // TEST_H
