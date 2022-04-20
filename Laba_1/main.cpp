#include <QCoreApplication>
#include <iostream>
#include <stack>  // подключаем библиотеку для
                  // использования стека
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

  stack <int> steck;  // создаем стек

  int i = 0;

  cout << "Input 6 numbers: " << endl; // предлагаем пользователю
                                                      // ввести 6 чисел
  while (i != 6) {
    int a;
    cin >> a;

    steck.push(a);  // добавляем введенные числа
    i++;
  }

  if (steck.empty()) cout << "Stack not empty";  // проверяем пуст ли стек (нет)

  cout << "Top element: " << steck.top() << endl; // выводим верхний элемент
  cout << "Lets delete " << endl;

  steck.pop();  // удаляем верхний элемент

  cout << "New top elem: " << steck.top(); // выводим уже новый

    return a.exec();
}
