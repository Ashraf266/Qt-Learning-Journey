#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QStringView>



void readName(QString name)
{
    // copying this is slow
    name.insert(0, "Mr.");
    qInfo() << "Changed" << name;
}

void readName_2(QString &name)
{
    // copying this is slow
    name.insert(0, "Mr.");
    qInfo() << "Changed" << name;
}


void readOnly(QStringView name)
{
    // name.insert(0, "Mr."); No modification allowed
    qInfo() << "Changed" << name.data() << name;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstName = "Brayen";
    QString lastName = "Cairns";


 // Copy & Modification issues
    readName(firstName);
    qInfo() << "Original" << firstName;

    readName_2(firstName);
    qInfo() << "Original" << firstName;


 // StringView -> Read-only --- No copy
 //                                  .data() returns a pointer to the string's data
    qInfo() << "Changed" << firstName.data() << firstName;
    readOnly(firstName);

// notice they have the same address so we aren't copying the stirng



// Basic Parsing
    QString fullName = firstName + " " + lastName;

    foreach(QStringView part, QStringView(fullName).split(QChar(' ')))
    {
        qInfo() << "Part" << part;
    }


    return a.exec();
}
