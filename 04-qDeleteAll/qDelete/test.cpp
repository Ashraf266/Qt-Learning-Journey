#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    qInfo() << this << "constructed" << parent;
}

Test::~Test()
{
    //                                 function to get the parent
    qInfo() << this << "destructed" << this->parent();
}
