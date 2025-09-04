#include <QCoreApplication>
#include <QObject>
#include <iostream>

#include <QVector>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <personprinter.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<QPair<QString, int>> persons;

    //открытые файла и запись в массив persons
    QFile inputFile("input.txt");
    if (inputFile.open(QIODevice::ReadOnly)) {

        QTextStream reading(&inputFile);
        while (!reading.atEnd()) { //пока файл не закончится
            QString line = reading.readLine(); //считывать построчно

            //получение из строки имени и возраста
            QStringList personData = line.split(' ');
            persons.append(QPair<QString, int>(personData[0].trimmed(), personData[1].toInt()));
        }
    }
    else qDebug() << "! файл не открывается";

    //создание объекта класса и связи сигнала и слота
    PersonPrinter personprinter(persons, nullptr);
    QObject::connect(&personprinter, &PersonPrinter::finished, &PersonPrinter::done);

    //вывод на экран после чего сработает слот DONE
    personprinter.print();

    return a.exec();
}


