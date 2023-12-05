#include <QCoreApplication>
#include "cat.h"
#include <QDebug>

//Q_DISABLE_COPY
// void test(Cat cat)
// {

// }


// ------Alter solutions------

//Use refrence
void test_ref(Cat &cat)
{
    //prints the address of cat
    qInfo() << "Address:" << &cat ;
}

//Use pointer
void test_ptr(Cat *cat)
{
    //prints the address of cat
    qInfo() << "Ptr:" << cat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Please NM the cringe

    //Each QObject is unique and what define that is its memory location
    Cat kitty;
    kitty.setObjectName("Kitty");
    //We cannot copy a QObject class && we Cannot move it also !!!
    //It's tied to it's memory location
 /*
  * Why Qt disables copying of QObjects ?
  * Because of signals&slots if we copy a QObject.. when emmiting a signal it will
  * affect two objects in two different memory locations & it gets more complicated with the program complixty
  */
    //test(kitty);

    Cat kitty1;
    //kitty1.setObjectName("Kitty one");
    //Note that the memory address is what really defines the object not the name
    kitty1.setObjectName("Kitty");

    qInfo() << &kitty ;
    test_ref(kitty);
    test_ptr(&kitty);

    qInfo() << &kitty1 ;
    test_ref(kitty1);
    test_ptr(&kitty1);

    return a.exec();
}
