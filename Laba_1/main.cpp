#include <iostream>
using namespace std;

const int SIZE = 100;

template <class SType> class stack {
	SType stck[SIZE];	//инициализация стека размером SIZE = 100
	int tos;			//текущее количество элементов в стеке	
public:
	stack();			//конструктор
	~stack();			//деструктор
	void push(SType i);	//добавить элемент
	SType pop();		//достать
	SType peek();		//узнать текущее кол-во
};

// функция-конструктор stack
template <class SType> stack<SType>::stack()
{
	tos = 0;
	cout << "Stack Initialized\n";
}

// функция-деструктор stack
template <class SType> stack<SType>::~stack()
{
	cout << "Stack Destroyed\n";
}

// помещение объекта в стек
template <class SType> void stack<SType>::push(SType i)
{
	if (tos == SIZE) {
		cout << "Stack is full. \n";
		return;
	}
	stck[tos] = i;
	tos++;
}
// извлечение объекта из стека
template <class SType> SType stack<SType>::pop()
{
	if (tos == 0) {
		cout << "Stack underflow.\n";
		return 0;
	}
	tos--;
	return stck[tos];
}

template <class SType> SType stack<SType>::peek() 
{
	return tos;
}

int main()
{
	stack<int> a; // создание целочисленного стека
	stack<double> b; // создание вещественного стека
	stack<char> c; //создание символьного стека

	// использование целого и вещественного стеков
	a.push(1);
	b.push(99.3);
	a.push(2);
	b.push(-12.23);
	cout << a.peek() << " " << b.peek() << endl; // 2 2
	cout << a.pop() << " ";
	cout << a.pop() << "\n";
	cout << a.peek() << " " << b.peek() << endl; // 0 2
	cout << b.pop() << " ";
	cout << b.pop() << "\n";
		
	// демонстрация символьного стека
	for (int i = 0; i < 10; i++)
	{
		c.push('A' + i);

		cout << c.peek();
	}

	for (int i = 0; i < 10; i++)
		cout << c.pop();
}
