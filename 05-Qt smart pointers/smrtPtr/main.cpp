#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include <QSharedPointer>
#include "test.h"

/*
 * Qt memory mangement
 * QScopePointer
 * QSharedPointer
 *
 * Qt smart pointer
 */

void testScope()
{
    //smart pointer frees the memory automatically when it gets out of scope
    QScopedPointer<Test> ptr(new Test());
    ptr->message("Hello");
    //Here out of scope
}

void finish(QSharedPointer<Test> ptr)
{
    ptr->message("Finished");
}

void work(QSharedPointer<Test> ptr)
{
    ptr->message("working");
}

void step(QSharedPointer<Test> ptr)
{
    ptr->message("stepping");
    for(int i =0; i<3; i++)
    {
        work(ptr);
    }
    finish(ptr);
}

void testShared(Test *test)
{
    QSharedPointer<Test> ptr(test);
    ptr->message("Starting...");
    step(ptr);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testShared(new Test());

    //testScope();

    return a.exec();
}
