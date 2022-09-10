#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <cstring>


class Exception

{

private:

    char* message;

public:
// конструктор
Exception(const char* arg_message)

{

    message = new char[strlen(arg_message)+1];// выделяем память под сообщение об ошибке

    strcpy(message,arg_message);// сообщение об ошибке

}
// конструктор копирования
Exception(const Exception& arg)

{

    message = new char[strlen(arg.message)+1];// выделяем память под копию сообщения

    strcpy(message,arg.message);// копируем сообщение об ошибке

}
// деструктор
~Exception()

{

    delete message;// освобождаем память

}

    const char* what() const { return message; }

};

#endif // EXCEPTIONS_H
