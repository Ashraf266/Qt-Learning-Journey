#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{}

void Test::doStuff()
{
    qInfo() << "Doing stuff ...";
    // we use emit to let qt know that "hey this happened"
    emit close();
}
