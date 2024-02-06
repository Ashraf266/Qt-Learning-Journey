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

    //list.replace(3,54444444);


    for(int i=0; i<list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i);
    }

}


void test_search()
{
    QList<int> list = getNumbers();

    int item = 999;
    list.insert(0,item);
    list.insert(3,item);
    list.append(item);

    for(int i=0; i<list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i);
    }

    //First
    int fpos = list.indexOf(item);

    qInfo() << "First" << fpos;

    //Last
    int lpos = list.lastIndexOf(item);
    qInfo() << "Last" << lpos;


    //All
    int pos = list.indexOf(item);
    do
    {
        qInfo() << "At" << pos;
        //start searching from pos+1 ---- .indexOf( what we are searching for, the index to start searching from);
        pos = list.indexOf(item,pos+1);
    }while(pos > -1);


    qInfo() << "Contains" << list.contains(item);

    //Get a slice
    // --------------------.sliced(pos, num of items);
    QList<int> items = list.sliced(1,4);

    qInfo() << list;
    qInfo() << items;


}


//--- Memory Considrations ---
void test_deleteall()
{
    QList<Test *> list;
    for(int i = 0; i<5; i++)
    {
        list.append(new Test());// Dangerous no parent if we used "new Test()"
    }

    qInfo() << "Cleaning up";
    qDeleteAll(list);//it doesn't remove the dangling pointers from the list but it deletes the Qobjects itself

    qInfo() << "before clearing" << list.length();//dangling pointers

    list.clear();

    qInfo() << "After clearing" << list.length();

    //this is not the easiest way of dealing with it we can use smart pointers to make it easier
}

void test_smart()
{
    QList<QSharedPointer<Test>> list;

    for(int i=0; i<5; i++)
    {
        QSharedPointer<Test> item(new Test); //Auto memory mangement
        list.append(item);
    }

    qInfo() << "Remove First";
    list.removeFirst();

    qInfo() << "Clearing";
    list.clear();
    qInfo() << list.length();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // ---- Creating and adding data
    testNumbers();

    qInfo() << "-------------------------";

    // --- Modifying existing data
    modifyNumbers();


    qInfo() << "-------------------------";


    // --- Searching
    test_search();

    //--- memory considrations
    test_deleteall();

    test_smart();

    return a.exec();
}
