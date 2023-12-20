#include <QCoreApplication>


void status(QByteArray &data)
{
    qInfo() << "Length" << data.length() << "Capacity" << data.capacity();
    qInfo() << "data:" << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

// NOTE: QByteArray is not a QObject so we can copy it

// Create an Array
    QByteArray stuff;
    qInfo() << stuff; // qInfo() treats it as a string

    QByteArray data("Hello");
    qInfo() << data;

    QByteArray buffer(10, '\t');
    qInfo() << buffer;

    QByteArray person(QString("Ashraf").toLocal8Bit());
    qInfo() << person;


// Sizing the array
    data.reserve(25); // go out and attempt to reserve some memory so you don't have to allocate
    status(data);

    data.resize(10);
    status(data);
// Note: While resize() will grow the capacity if needed,
// it never shrinks capacity. To shed excess capacity, use squeeze().

    data.truncate(8);
    status(data);

    data.clear();
    status(data);


// Modifying the data
    data.resize(5);
    data.fill('\x02');
    status(data);

    data.replace(0, 1, QByteArray("Sweet"));//Check this !!
    status(data);

    data.clear();
    data.resize(5);
    data.fill('\x02');
    status(data);

    data.replace(0, 99, QByteArray("Sweet"));//Check the difference
    status(data);

    data.fill('*');
    data.insert(3, QByteArray("Hello World"));
    status(data);

    data.append('!');
    status(data);

    data.remove(14, 3);
    status(data);

// Reading the data



    return a.exec();
}
