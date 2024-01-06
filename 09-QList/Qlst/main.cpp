#include <QCoreApplication>
#include <QSharedPointer>
#include <QRandomGenerator>
#include "test.h"




// ---- Creating and adding data
QList<int> getNumbers()
{
    // QList is not a QObject so it can be copied
    QList<int> list;


    //Adding data
    list << 400 << 300 << 500;

    int max = QRandomGenerator::global()->bounded(1,10);

    for(int i=0; i<max; i++)
    {
        list.append(QRandomGenerator::global()->bounded(1,100));
    }

    return list;
}


void testNumbers()
{
    QList<int> list = getNumbers();
    qInfo() << list;

    qInfo() << "length" << list.length();//same
    qInfo() << "count" << list.count();//same a little different with a parameter
    qInfo() << "size" <<list.size();//same

    for(int i=0; i<list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i) << "or" << list[i];
    }


    qInfo() << "-------------------------";

    foreach (int i, list) {
        qInfo() << i;
    }

}

void modifyNumbers()
{

    QList<int> list = getNumbers();

    //direct modification
    list[0] = 123;

    //Error
    //list.at(3) = 3;

    //appending
    list.append(55);
    list << 32 << 43;

    //inserting
    list.insert(0,55);
    list.insert(2,32);
    list.insert(2,32);
    list.insert(2,32);
    list.insert(2,32);
    list.insert(2,32);
    list.insert(2,32);
    list.insert(2,32);

    for(int i=0; i<list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i);
    }

    qInfo() << "length" << list.length();

    //removing
    list.removeAt(0);

    qInfo() << "length" << list.length();


    qInfo() << "length" << list.length();

    //removing
    list.removeOne(300);//removes the first occurence of the number
    list.removeAll(32);//removes all the occurences of the number

    qInfo() << "length" << list.length();


    qInfo() << "length" << list.length();

    //remove is tricky
    list.remove(1,3);//first one is index second one is number of elements to delete

    qInfo() << "length" << list.length();


    for(int i=0; i<list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i);
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // ---- Creating and adding data
    testNumbers();

    qInfo() << "-------------------------";

    // --- Modifying existing data
    modifyNumbers();

    return a.exec();
}
