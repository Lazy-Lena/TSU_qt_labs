#ifndef STACK_H
#define STACK_H

#include "exceptions.h"
#include "empty.h"
#include <functional>

template <class T>
class Stack
{
public:
    ~Stack(); // деструктор
    void Push(const T &k); //Помещение объекта в стек;
    const T Pop(); // Извлечение объекта из стека;
    int Size(); // размер стека
    void Clear(); // удаление из стека всех узлов
    void Enum(std::function<void(const T &k)> f) const;//функция перебора значений

private:
    struct Node
    {
        const T key; // храним константное значение

        Node *prev = nullptr; // указатель на предыдущее звено стека
    };

    Node *t = nullptr; // последний элемент стека

    int size = 0;
};

// деструктор
template <class T>Stack<T>::~Stack()
{
    Clear();
}

// Помещение объекта в стек;
template <class T>void Stack<T>::Push(const T &k)
{
    Node *node = new Node{ k, t }; // создаем новое звено
    if (node == nullptr) // память не выделелась
    {
        throw Exception("No enough memory."); //Память закончилась
    }

    t = node; // Переопределяем созданное звено

    size++; // увеличиваем размер стека
}

// Извлечение объекта из стека;
template <class T> const T Stack<T>::Pop()
{
    if (t == nullptr) // если стек пуст, возвращаем исключение
    {
        throw EStackEmpty();
    }

    const T k = t->key; // сохраняем значение звена в k

    Node *tmp = t; // сохраняем в tmp

    t = t->prev; // перемещаем на предпоследнее звено

    delete tmp; // удаляем звено

    size--; // уменьшаем размер стека

    return k; // возвращаем сохраненое значение
}

//размерность стека
template <class T> int Stack<T>::Size()
{
    return size; // размер стека
}

template <class T> void Stack<T>::Clear()
{
    while (t != nullptr) // пока стек не пуст
    {
        Node *tmp = t; // сохраняем последний элемент

        t = t->prev; // переопределяем последний элемент

        delete tmp; // удаляем последний элемент ( который сохраняли в tmp
    }
}
// функция перебора значений
template <class T>
void Stack<T>::Enum(std::function<void(const T &k)> f) const
{
    Node *tmp = t; // перебор начинаем с последнего

    while (tmp != nullptr) // заканчивая первым
    {
        f(tmp->key); // вызов функции обратной связи

        tmp = tmp->prev;
    }
}
#endif // STACK_H
