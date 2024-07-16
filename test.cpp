#include "test.h"

Test::Test(QObject *parent) : QObject{parent} {
    qInfo() << this << "Constructed";
}

Test::~Test() { qInfo() << this << "Deconstructed"; }

void Test::doStuff() {
    qInfo() << this << "doStuff";
    Test::doOtherStuff();
}

void Test::doOtherStuff() {
    // "this" doesn't exist.
    // qInfo() << this << "doOtherStuff";
    // doStuff(); // No instance can not call the other function

    // we can still run code without an instance
    qInfo() << "doOtherStuff";
}

void Test::doStuff2() { qInfo() << this << Q_FUNC_INFO; }
