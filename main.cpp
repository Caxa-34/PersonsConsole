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

    //открытые файла в папке с исходниками и запись в массив persons
    QFile inputFile("input.txt");
    // Проверка существования файла
    if (!inputFile.exists()) {
        qDebug() << "! файл не существует";
        return a.exec();
    }

    if (inputFile.open(QIODevice::ReadOnly)) {

        QTextStream reading(&inputFile);
        while (!reading.atEnd()) { //пока файл не закончится
            QString line = reading.readLine(); //считывать построчно
            if (line.isNull() || line.trimmed().isEmpty()) continue; //пропуск пустой строки

            //получение из строки имени и возраста
            QStringList personData = line.split(' ');
            QString name = personData.value(0, "").trimmed();
            if (name == "") continue; //проверка что имя обработалось
            int age = personData.value(1, "-1").toInt();
            if (age == -1) continue; //проверка что возраст обработался
            persons.append(QPair<QString, int>(name, age));
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


