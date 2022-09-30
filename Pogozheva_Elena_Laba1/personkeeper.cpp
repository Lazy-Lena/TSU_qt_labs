#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "personkeeper.h"
#include "estackempty.h"

PersonKeeper &PersonKeeper::instance()
{
    static PersonKeeper inst;
    return inst;
}

Stack<Person> PersonKeeper::readPersons(QString path)
{
    QFile file(path);
    Stack<Person> person;

    // Генерация исключения при не открытом или не существующем файле
    try {
        // существует ли файл
        if (!file.exists())
            throw EStackException("Error: File doesn't exists").what();

        // открытие файла на чтение
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            throw EStackException("Error: Not open file").what();

    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return {};
    }

    // поток текстовых данных файла
    QTextStream input(&file);

    // буфер для записи строк
    QString buffLine;

    // считытваем, пока не конец файла
    while (input.readLineInto(&buffLine))
    {
        // добавляем в стек ФИО
        person.push(Person(buffLine));
    }

    // закрываем для чтения файл
    file.close();

    return person;
}

void PersonKeeper::writePersons(QString path, Stack<Person> &person) const
{
    QFile file(path);

    // Генерация исключения при не открытом или не существующем файле
    try {
        // существует ли файл
        if (!file.exists())
            throw EStackException("Error: File doesn't exists").what();

        // открытие файла на чтение
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            throw EStackException("Error: Not open file").what();

    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return ;
    }

    QTextStream output(&file);

    // проходимся по всем значеним для записи
    person.enumeration([&](const Person &person) { output << person.getFullName() << "\n"; });

    // закрываем файл для записи
    file.close();
}
