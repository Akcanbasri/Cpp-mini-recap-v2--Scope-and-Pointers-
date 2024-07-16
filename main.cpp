#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "animal.h"
#include "test.h"

using namespace std;

void test(int number) {
    // Scope
    number = 50;
    qInfo() << "2- numnber: " << &number << " =" << number;
}

// Global Scoping
QString myname = "hasan";

void testMyName() { qInfo() << myname; }

// Static Scopes in classes
int Animal::count = 0;
QString Animal::name = "";

void testScope() {
    Animal fish(nullptr, "Nemo1");
    Animal fish2(nullptr, "Nemo2");
    Animal fish3(nullptr, "Nemo3");

    qInfo() << "Cout:" << fish.count;
    qInfo() << "Fish1 name:" << fish.name;
    qInfo() << "Fish2 name:" << fish2.name;
    // Deconstructed
}

// Practice
int addTen(int age) { return age + 10; }

void dogYear(int value) {
    int age = value * 7;
    qInfo() << "Dog year of your age is " << age;
}

// Pointers
void pointerTest(QString value) // Stack - COPY
{
    qInfo() << &value << "Size:" << value.length();
} // destroy

void pointerTest2(QString *value) // Stack -POINTING
{
    qInfo() << "p" << value << "Size:" << value->length();
    qInfo() << "a" << &value << "Size:" << value->length();
} // destroy

void display(QString *value) {
    qInfo() << "The Pointer" << value;
    qInfo() << "The Adress" << &value;
    qInfo() << "The Data" << *value;
}

// Automatic Memory Manegment
void wow() {
    std::unique_ptr<Test> t(new Test());
    t->doStuff2();

    // Pointer autatically deleted for us
}

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);
    // Scope
    qInfo("***********************************************");
    int number = 75;
    qInfo() << "1- numnber: " << &number << " =" << number;
    test(number);

    bool ok = true;

    if (ok) {
        // Scope
        int number = 1000; // eğer int yapmazsak main içindeki sayıyı değiştiriyordu.
        qInfo() << "3- numnber: " << &number << " =" <<
        number;
    }
    qInfo() << "4- numnber: " << &number << " =" << number;

    qInfo("***********************************************");

    // Scoping with classes
    QString name = "Basri";
    qInfo() << "My name is at" << &name << "=" << name;

    Animal cat(&a, "bulut");
    Animal dog(&a, "boncuk");
    Animal person(&a, "yunus");

    person.sayHello("Hola mi amor!");

    cat.name = "My Cat";
    dog.name = "My Dog";
    qInfo() << person.name;
    qInfo() << cat.name;
    qInfo() << dog.name;

    qInfo("***********************************************");
    myname = "Merve";
    qInfo() << myname;

    bool test = true;
    if (test) {
        QString myname = "Mustafa";
        qInfo() << myname;
        qInfo() << ::myname;
    }

    qInfo() << myname;
    testMyName();

    qInfo("***********************************************");

    qInfo() << "Cout:" << Animal::count;

    qInfo("***********************************************");
    // Test t;
    // t.doStuff();
    // t.doOtherStuff();

    Test::doOtherStuff();

    qInfo("***********************************************");

    // Practice
    int age = 0;
    qInfo() << "Enter your age:";
    cin >> age;

    qInfo() << "Ten more:" << addTen(age);
    dogYear(age);

    // Pointers
    QString name1 = "Basri"; // Stack - C++ manage this
    qInfo() << &name1 << "Size:" << name1.length();

    pointerTest(name1);
    pointerTest2(&name1);

    qInfo("***********************************************");

    QString name2 = "Mustafa"; // Stack - C++ manage this
    QString *description = new QString("Hello Pointer"); // Heap - We manage
    qInfo() << description;

    display(description);

    delete description; // destroying it

    qInfo("***********************************************");

    // Automatic memory mangement
    qInfo() << "Starting";
    wow();
    qInfo() << "Finished";

    qInfo("***********************************************");

    // QObject parent child relationships
    Test *parent = new Test(&a);
    parent->dog = new Animal(parent, "Hasan");
    delete parent;

    return a.exec();
}
