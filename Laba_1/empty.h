#ifndef EMPTY_H
#define EMPTY_H
#include "exceptions.h"
class EStackEmpty : public Exception
{
public:
    // конструктор по умолчанию
    EStackEmpty()
        : Exception("Stack is empty") // инициализируем базовый класс сообщением об ошибке
    {

    }

    // конструктор копирования
    EStackEmpty(const EStackEmpty &t)
        : Exception(t) // инициализируем базовый класс переденным обьектом
    {

    }
};
#endif // EMPTY_H
