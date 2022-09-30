#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include <QFile>
#include <QString>

#include "Stack.h"
#include "person.h"

//Singleton
class PersonKeeper
{
public:
    static PersonKeeper &instance(); ///< хранится единственный экземпляр класса
    Stack<Person> readPersons(QString path); ///< считать ФИО из файла и вернуть данные
    void writePersons(QString path, Stack<Person> &person) const; ///< записать ФИО в файл

private:
    PersonKeeper(){} ///< конструкторы по умолчанию
    PersonKeeper(const PersonKeeper &); ///< конструктор копирования
    ~PersonKeeper(){} ///< деструктор
    PersonKeeper &operator=(const PersonKeeper &); ///< оператор присовения
};

#endif // PERSONKEEPER_H
