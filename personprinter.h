#ifndef PERSONPRINTER_H
#define PERSONPRINTER_H

#include <iostream>
#include <QVector>
#include <QObject>

/**
 * @brief Класс для хранения списка людей с именем и возрастом и его вывода в консоль
 */
class PersonPrinter : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief конструктор класса PersonPrinter
     * @param persons - список людей
     * @param parent - родитель
     */
    PersonPrinter(QVector<QPair<QString, int>> persons, QObject *parent);

    /**
     * @brief печать списка людей в консоль в порядке убывания возраста
     */
    void print();

signals:
    /**
     * @brief сигнал о завершении печати списка людей в консоль
     */
    void finished();

private:
    ///список людей
    QVector<QPair<QString, int>> persons;

public slots:
    //вывод завершающего сообщения при завершении печати списка людей
    void done();
};

#endif // PERSONPRINTER_H
