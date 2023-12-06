#include <QCoreApplication>
#include <QDebug>
#include "test.h"



//get a list of pointers
typedef QList<Test*> testList;


testList getList()
{
    testList list;
    for(int i=0; i<5; i++)
    {
        list.append(new Test);
        list.last()->setObjectName("Test " + QString::number(i));
    }

    return list;
}


//Display a list of pointers
void display(testList list)
{
    foreach (Test *item, list)
    {
        qInfo() << item;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testList list = getList();
    display(list);

    //we notice that it doesn't follow the parent child relationship so if we don't delete it ourself it will cause a memory leak

    qInfo() << "Deleting....";

    qDeleteAll(list); //a simple algorithm to delete the entire list
    //qDeleteAll(list.begin(), list.end()); // to delete part of a list
 // NOTE: lists are allocated in the Heap

    list.clear(); //this will avoid dangling pointers after deallocation of the list

    display(list); //if not cleared we would have dangling pointers .... it will cause crashing "segmentation fault"

    return a.exec();
}
