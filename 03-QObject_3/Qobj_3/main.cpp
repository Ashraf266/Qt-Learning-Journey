#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "test.h"



//setting in constructor
Test* getTest(QObject *parent)
{
    return new Test(parent);
}

//setting up after constructor
Test* getTest()
{
    return new Test;//this will cause a memory leak
}



/*
 * Qt Memory Mangement
 * Parent child relationship
 */

/*
  * what is a slot?
  * a slot is a normal function but it got moc around it ...
  * so it can be used in a (signal & slot) scenario
  * and we can send messages between messages
  */


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << &a;

    QTimer timer;

    //    singleShot(interval, pointer to receiver, slot);
    timer.singleShot(3000,&a, &QCoreApplication::quit);

    //setting in constructor
    Test* dog = getTest(&a);
    dog->setObjectName("Rex");
    //we will notice that Rex will be Destructed automatically as it's a child to a


    //setting up after constructor
    Test* cat = getTest();
    cat->setObjectName("Renis");
    cat->setParent(dog);


    int value = a.exec();

    qInfo() << "Exit Code:" << value;

    return value;
}
