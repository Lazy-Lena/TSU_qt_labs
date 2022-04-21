#include <QCoreApplication>
//#include <fstream>
#include <iostream>
//#include <stack>
#include <exception>
using namespace std;

class Stack_init
{
    char* stck; //непосредственно стэк
    int tos;    //счетчик

    //Параметрический конструктор класса Stack
public:

    Stack_init(int size) {
        stck = new char[size];
        tos = 0;
    }
    //Метод помещает в неполный стек элемент
    void push(char ch)
    {
        if (tos == sizeof(stck))
        {
            cout << ("Stack full");
            return;
        }
        stck[tos] = ch;
        tos++;
    }
    //Метод отдаёт из непустого стека элемент
    char pop()
    {
        if (tos == 0)
        {
            return '0';
            //throw exception();
        }
        tos--;
        return stck[tos];
    }
    //Метод показывает общий объём стека
    int volume()
    {
        return sizeof(stck);
    }
    //Метод показывает текущий объём стека
    int kol()
    {
        return tos;
    }
    //Метод возвращает значение true, если стек полон
    bool empty()
    {
        return tos == sizeof(stck);
    }
    //Метод возвращает значение true, если стек пуст
    bool full()
    {
        return tos == 0;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

        Stack_init stack1(10);

        cout << stack1.volume() << endl;

        for (int i = 0; !stack1.empty(); i++)
            stack1.push('A' + i);

        cout << "Number of elements: " << stack1.kol() << endl;

        string ch;
        for (int i = 0; !stack1.full(); i++)
        {
            //try {
                ch = stack1.pop();
                cout << ch << endl;
            /* }
            catch (const exception& x) {
                cerr << "Error" << x.what() << endl;
            }*/
        }

    return a.exec();
}
