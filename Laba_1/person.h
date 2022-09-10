#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QRegularExpression>

class Person
{
private:
    QString last_name;
    QString first_name;
    QString patronymic;
public:
    Person(){

    }
    Person(QString last_name, QString first_name, QString patronymic): last_name(last_name), first_name(first_name), patronymic(patronymic)
    {
    }
    Person(QString full_name);

    void Set_last_name(const QString &last_name) {
        this->last_name = last_name;//определение фамилии
    }
    void Set_first_name(const QString &first_name) {
        this->first_name = first_name;//определение имени
    }
    void Set_patronymic(const QString &patronymic) {
        this->patronymic = patronymic;//определение отчества
    }
    const QString &Get_last_name() const { return last_name; }//получение фамилии
    const QString &Get_first_name() const { return first_name; }//получение имени
    const QString &Get_patronymic() const { return patronymic; }//полученеи отчества

};
Person::Person(QString full_name)
{
    QStringList str = full_name.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts); //Разбивает строку на подстроки

    if (str.size() != 2 && str.size() != 3) // если не правильное количество слов, то сообщаем об ошибке
    {
        throw "Error: Person(): String is invalid";
    }

    last_name = str[0]; // фамилия
    first_name = str[1]; // имя
    if (str.size() == 3)
    {
        patronymic = str[2];//отчество
    }
}
#endif // PERSON_H
