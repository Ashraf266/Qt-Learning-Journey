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
    int first = data.indexOf('*');   //return -1 if not found
    int last = data.lastIndexOf('*');
    qInfo() << "First *:" << first << "Last *:" << last;

    if(first > -1 && last > -1)
    {
        qInfo() << "Mid" << data.mid(first, last-first+1);
    }

    data.clear();
    data.append("Mohamed Ashraf");

    for(int i=0; i < data.length(); i++)
    {
        qInfo() << "At" << data.at(i) << "or" << data[i]; // .at() does range checking
    }

    foreach(char c, data)
    {
        qInfo() << "Char" << c;
    }

    foreach(auto item, data.split(' '))
    {
        qInfo() << "Item" << item;
    }


// Encoding the data
    qInfo() << "Normal" << data;
    qInfo() << "Repeated" << data.repeated(3);

    data.append(QByteArray("\t\r\n"));
    data.insert(0,QByteArray("      \t\t\t"));
    qInfo() << "Normal" << data;
    qInfo() << "Trimmed" << data.trimmed(); //Trims white spaces
    data = data.trimmed();

    // Convert to & from Hex encoding
    QByteArray hex = data.toHex();
    qInfo() << "Hex" << hex;
    QByteArray from_hex = QByteArray::fromHex(hex);
    qInfo() << "From Hex" << from_hex;


    QByteArray base64 = data.toBase64();
    qInfo() << "Base64" << base64;
    QByteArray from_base64 = QByteArray::fromBase64(base64);
    qInfo() << "From Base64" << from_base64;


    return a.exec();
}
