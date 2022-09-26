#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QRegularExpression>

class Person
{
public:
    Person() = delete;
    Person(QString lastName, QString firstName, QString patronymic):
        _lastName(lastName),
        _firstName(firstName),
        _patronymic(patronymic){ };

    Person(QString fullName);

    void setLastName(const QString &lastName);    // задать фамалию
    void setFirstName(const QString &firstName);  // задать имя
    void setPatronymic(const QString &patronymic);// задать отчество

    const QString &getFullName() const { return _fullName; }    // получить ФИО
    const QString &getLastName() const { return _lastName; }    // получить фамилии
    const QString &getFirstName() const { return _firstName; }  // получить имени
    const QString &getPatronymic() const { return _patronymic; }// получить отчества

private:
    QString _fullName; ///< ФИО
    QString _lastName; ///< Фамилия
    QString _firstName; ///< Имя
    QString _patronymic; ///< Отчество

};
#endif // PERSON_H
