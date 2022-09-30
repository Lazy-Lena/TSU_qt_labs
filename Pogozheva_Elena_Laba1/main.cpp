#include <iostream>
#include <cstring>
#include <string>
#include <QString>
#include <QFile>
#include <QDebug>

#include "personkeeper.h"
#include "Stack.h"
#include "person.h"

int main()
{
    QString inputFile = "input.txt"; // файл для чтения
    QString outputFile = "output.txt"; // файл для записи
    Stack<Person> person;
    PersonKeeper &persorKeep(PersonKeeper::instance());

    qDebug() << "Creat 2 files in the folder where the project exists: input.txt and output.txt";
    // считываем имена из файла
    qDebug() << "Read data from input.txt";
    person = persorKeep.readPersons(inputFile);
    qDebug() << "sosi";
    qDebug() << "Data from input.txt: ";
    // перебор стека для вывода
    person.enumeration([&](const Person &value){
        qDebug() << value.getLastName() << value.getFirstName() << value.getPatronymic();
    });

    qDebug() << "Write data from input.txt into ouput.txt";
    // записываем имена в файл
    persorKeep.writePersons(outputFile, person);
    qDebug() << "Now you can open files to compare data";

    qDebug() << "---------------------------------";


    srand (time(NULL));
    Stack<int> stackOfInteger;
    Stack<float> stackOffloat;

    qDebug() << "Add 10 randoms values of integer into stackOfInteger";
    for(int i = 0; i < 10; ++i) {
        int val = rand() % 10  + 1;
        stackOfInteger.push(val);
        qDebug() << val;
    }

    qDebug() << "Output the stackOfInteger: ";
    stackOfInteger.enumeration([&](const int &value){
        qDebug() << value;
    });

    qDebug() << "---------------------------------";

    qDebug() << "Add 10 values of float into stackOfFloat";
    for(int i = 0; i < 10; ++i) {
        float val = static_cast<float>(i / (i + 2.5));
        stackOffloat.push(val);
        qDebug() << val;
    }

    qDebug() << "Output the stackOfFloat: ";
    stackOffloat.enumeration([&](const float &value){
        qDebug() << value;
    });

    qDebug() << "---------------------------------";

    qDebug() << "Try to throw an exception";
    Stack<bool> stack;
    stack.pop();
}
