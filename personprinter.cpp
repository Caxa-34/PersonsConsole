#include "personprinter.h"

PersonPrinter::PersonPrinter(QVector<QPair<QString, int>> persons, QObject *parent = nullptr)
{
    this->persons = persons;

    //сортировка по возрастанию с помощью лямда функции
    qSort(this->persons.begin(), this->persons.end(),
    [] (const QPair<QString,int> &a, const QPair<QString,int> &b) {
        return a.second < b.second;
    });
}

void PersonPrinter::print() {
    //сортировка по убыванию
    qSort(this->persons.begin(), this->persons.end(),
    [] (const QPair<QString,int> &a, const QPair<QString,int> &b) {
        return a.second > b.second;
    });

    //вывод в консоль
    for (const QPair<QString, int> &p : persons) {
            std::cout << p.first.toStdString() << " (" << p.second << ")" << std::endl;
        }

    emit finished();
}

void PersonPrinter::done() {
    std::cout << "--- DONE ---" << std::endl;
}
