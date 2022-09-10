#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H
#include <QTextStream>
#include <QFile>
#include <QString>
#include "Stack.h"
#include "person.h"

//Singleton
class PersonKeeper
{
private:
    PersonKeeper(){} // конструкторы по умолчанию
    PersonKeeper(const PersonKeeper &); //конструктор копирования
    ~PersonKeeper(){}//деструктор
    PersonKeeper &operator=(const PersonKeeper &); //оператор присовения
    Stack<Person> st; // имена
public:
    static PersonKeeper &Instance(); // хранится единственный экземпляр класса
    void ReadPersons(QString path); //считать ФИО из файла
    void WritePersons(QString path) const; //записать ФИО в файл
    int Size(); // количество ФИО
    void Clear(); // очистить список ФИО

};
//Размер
int PersonKeeper::Size()
{
    return st.Size();
}
//Удаление
void PersonKeeper::Clear()
{
    return st.Clear();
}
// хранится единственный экземпляр класса
PersonKeeper &PersonKeeper::Instance()
{
    static PersonKeeper inst;
    return inst;
}

//считать ФИО из файла
void PersonKeeper::ReadPersons(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // открытие файла на чтение
    {
        throw "Not open file"; // файл не открылся
    }
    QTextStream stream(&file); // поток текстовых данных файла
    QString line; // в буфер считываются строки

    while (stream.readLineInto(&line)) // считытваем, пока не конец файла
    {
        st.Push(Person(line)); // добавляем в стек ФИО
    }
    file.close(); // закрываем данный файл
}

//записать ФИО в файл
void PersonKeeper::WritePersons(QString path) const
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) // открытие файла на запись
    {
        throw "Not open file"; // файл не открылся
    }
    QTextStream stream(&file); // поток текстовых данных файла
    st.Enum([&](const Person &k) // перебираем значения
    {
        stream << k.Get_last_name() << " " << k.Get_first_name() << " " << k.Get_patronymic() << Qt::endl; // записываем ФИО в файл
    });
    file.close(); // закрываем файл
}
#endif // PERSON_KEEPER_H
