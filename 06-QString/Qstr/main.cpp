#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <iostream>

void test(QString str)
{
    // NOTE: it's better to pass it by refrence
    qInfo() << str;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

// Creating a QString
    QString line("Hello World !");
    qInfo() << line;

    QString name;
    name = "Mohamed Ashraf";
    qInfo() << name;

    int pos = 504;
    int max = 4892;
    // construct a QString
    QString status = QString("Processing File %1 of %2").arg(pos).arg(max);
    qInfo() << status;


// Reading each character
    for(int i=0; i < line.length(); i++)
    {
        QChar c = line.at(i);
        qInfo() << c;
    }


// Comparing & Searching
    qInfo() << "Compare" << line.compare("hello world !",Qt::CaseSensitivity::CaseInsensitive);
    qInfo() << "Compare" << line.compare("hello world !",Qt::CaseSensitivity::CaseSensitive);

    qInfo() << "Starts" << line.startsWith("hello");
    qInfo() << "Starts" << line.startsWith("hello", Qt::CaseSensitivity::CaseInsensitive);
    qInfo() << "Starts" << line.startsWith("Hello");

    qInfo() << "Ends" << line.endsWith("!");

    qInfo() << "Contains" << line.contains("Hello");

    qInfo() << "Index" << line.indexOf('!');
    qInfo() << "Index" << line.indexOf("World");


// Modifying & Parsing
    //line.append("\r\nHow are \"you\"?");
    line.append("\r\nHow are you?");
    qInfo() << "Escape" << line;

    line.append("\r\n<i>This</i>is HTML<br>");
    qInfo() << "Html" << line.toHtmlEscaped();


    line.replace('!', '?');
    qInfo() << "Replaced" << line;


    qInfo() << "Upper" << line.toUpper();
    qInfo() << "Lower" << line.toLower();
    //                         start from index 3 and parse 5 characters
    qInfo() << "Mid" << line.mid(3,5);
    qInfo() << "Search & grap" << line.mid(line.indexOf("World"), 5);


    QStringList list = line.split('\n');
    foreach(QString item, list)
    {
        //qInfo() << "Item" << item;
        qInfo() << "Item" << item.trimmed();
    }


// Conversion
    std::cout << "\n\nstd " << line.toStdString() << std::endl;

    qInfo() << "UTF-8" << line.toUtf8();
    qInfo() << "Base64" << line.toUtf8().toBase64();
    qInfo() << "HEX" << line.toUtf8().toHex(' ');


// NOTE: QString is NOT a QObject
//       QObject cannot be copied but QString can be copied

    test(line);



    return a.exec();
}
