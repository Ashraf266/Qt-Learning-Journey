#include <QCoreApplication>
#include "test.h"
#include <QDebug>
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;


    // connect the signal & the slot
    //       connect(sender, signal, context, slot, connection type)
    //we are connecting test to our application here saying when close is emitted we want to quit
    QObject::connect(&test, &Test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);


    test.doStuff();
    //std::cout << "HELLO WORLD !!" << std::endl;

    int value = a.exec();

    qInfo() << "Exit value :" << value;

    return value;
}
