#ifndef STACK_H
#define STACK_H

#include <functional>
#include <iostream>
#include "exception.h"
#include "estackempty.h"

template <class T>
class Stack
{
public:
    ~Stack(); ///< деструктор
    void push(const T &val); ///< помещение элемента в стек
    const T pop(); ///< извлечение элемента из стека
    int size(); ///< вернуть размер стека
    void clear(); ///< очистить весь стек
    void enumeration(std::function<void(const T &val)> func) const; ///< перебор элементов

private:
    struct Node
    {
        Node() = default;
        explicit Node (T val, Node *node) : value(val), previousNode(node) {};
        const T value; ///< храним константное значение

        Node *previousNode = nullptr; ///< указатель на предпоследний узел стека
    };

    Node *_lastElement { nullptr }; ///< последний элемент стека

    int _sizeOfStack { 0 }; ///< размер стека
};

template <class T>
Stack<T>::~Stack()
{
    clear();
}

template <class T>
int Stack<T>::size()
{
    return _sizeOfStack;
}

template <class T>
const T Stack<T>::pop()
{

    // если стек пуст, возвращаем исключение
    try {
        if (_lastElement == nullptr)
            throw EStackEmpty().what();

    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return {};
    }

    // сохраняем значение узла
    const T value = _lastElement->value;

    // сохраняем последнией узел в tmp
    Node *tmp = _lastElement;

    // перемещаем на предпоследний узел
    _lastElement = _lastElement->previousNode;

    // освобождаем память из под последнего узла
    delete tmp;

    // уменьшаем размер стека
    _sizeOfStack--;

    // возвращаем сохраненое значение
    return value;
}

template <class T>
void Stack<T>::clear()
{
    // пока стек не пуст
    while (_lastElement != nullptr)
    {
        // сохраняем последний элемент
        Node *last = _lastElement;

        // переопределяем последний элемент
        _lastElement = _lastElement->previousNode;

        // удаляем последний элемент который сохраняли в last
        delete last;
    }
    _sizeOfStack = 0;
}

template <class T>
void Stack<T>::push(const T &val)
{
    // создаем новый узел
    Node *node = new Node{ val, _lastElement };

    try {
        // память не выделелась
        if (node == nullptr)
            throw EStackException("Error: memory is not allocated").what();

    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return ;
    }

    // переопределяем созданный узел
    _lastElement = node;

    // увеличиваем размер стека
    _sizeOfStack++;
}

template <class T>
void Stack<T>::enumeration(std::function<void(const T &val)> func) const
{
    // перебор начинаем с последнего
    Node *last = _lastElement;

    // пока не дойдем до первого
    while (last != nullptr)
    {
        // вызов функции обратной связи
        func(last->value);
        last = last->previousNode;
    }
}
#endif // STACK_H
