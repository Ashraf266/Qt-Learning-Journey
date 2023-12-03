#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QTextStream>
#include <QDebug>


// C++ way
void do_cpp()
{
    std::string name;
    std::cout << "Please enter your name: " ;
    std::getline(std::cin, name);
    std::cout << "Hello " << name << std::endl;
}

// Qt way
void do_qt()
{
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    QString name;

    qout << "Please enter your name: ";
    qout.flush();
    name = qin.readLine();
    qout << "Hello " << name << "\n";
    qout.flush();
}

// Mixed way
void do_mixed()
{
    //qInfo() is for debugging
    QTextStream qin(stdin);
    qInfo() << "Please enter your name: ";
    QString name = qin.readLine();
    qInfo() << "Hello" << name;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //To do - Code:

    //do_cpp();

    //do_qt();

    do_mixed();


    return a.exec();
}
