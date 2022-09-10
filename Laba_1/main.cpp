#include <QCoreApplication>
#include "Stack.h"
#include <iostream>
#include <cstring>
#include <QString>
#include "person_keeper.h"
#include <QFile>
using namespace std;
//int main(int argc, char *argv[])
int main()
{
    //QCoreApplication a(argc, argv);
    Stack<int> st1;
    Stack<float> st2;
    Stack<string> st3;
    cout << "Created three stacks of type, st1 - int, st2 - float, st3 - string" << endl;
    cout << "Test 1:" << endl << "Check adding integer data by pushing 10 values from 0..9 onto the stack - st1" << endl;

    for(int i=0;i<10;i++){
        st1.Push(i);
    }
    cout<<"Stack output of type int: ";
    st1.Enum([&](const int &k){
        cout<<k<<" ";
    });

    cout << "Test 2:" << endl << "Check adding real data by pushing 3 values onto the stack - st2" << endl;
    st2.Push(1.2398);
    st2.Push(2.38);
    st2.Push(9.048);
    cout << endl;
    cout<<"Stack output of type float: ";
    st2.Enum([&](const float &k){
        cout<<k<<" ";
    });

    cout << "Test 3:" << endl << "Check adding data of type by pushing 3 values on the stack - st3" << endl;
    st3.Push("Vasilevich");
    st3.Push("Ivan");
    st3.Push("Ivanov");

    cout << endl;
    cout<<"Stack output of type string: ";
    st3.Enum([&](const string &k){
        cout << k<<" ";
    });
    cout <<endl;
    cout << "Test 4:" << endl << "Let's create two files, in the folder where the project is built, name.txt and name_out.txt" << endl;
    PersonKeeper &persorKeep(PersonKeeper::Instance());
    QString path1 = "name.txt";
    QString path2 = "name_out.txt";
    persorKeep.Clear(); // удаляем имена
    cout << "Reading data from file name.txt" << endl;
    persorKeep.ReadPersons(path1); // считываем имена из файла
    cout << "We write data to the file name_out.txt that were read from the file name.txt" << endl;
    persorKeep.WritePersons(path2); // записываем имена в файл
    cout << "We open this file, we see that the data is all written" << endl;

    cout << "Test 5: " << endl << "Let's throw an exception, for this we will create an empty stack and try to remove the last element" << endl;
    Stack<int> st4;
    st4.Pop();
    //return 1;//a.exec();
}
