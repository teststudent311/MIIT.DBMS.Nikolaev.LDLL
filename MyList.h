/*****************************************************************//**
 * \file   MyList.h
 * \brief  API класса линейный двухсвязный список
 *
 * \author Nikolaev A. (teststudent311)
 * \date   October 2022
 *********************************************************************/

#pragma once

#include <iostream>

using namespace std;

struct Elem
{
    int data; // данные
    Elem* next, * prev; // указатели на начало и конец списка
};

class List
{
    // Указатели на начало и конец списка
    Elem* Head, * Tail;
    // Количество элементов списка
    int count;

public:

    // Конструктор
    List();

    // Деструктор
    ~List();

    // Получить количество элементов
    int getCount();

    // Получить элемент списка
    Elem* getElem(const size_t index);

    // Удалить весь список
    void gelAll();

    // Удаление элемента
    void del(const size_t index = 0);

    // Вставка элемента
    void insert(const size_t index = 0);

    // Добавление в конец списка
    void addTail(int value);

    // Добавление в начало списка
    void addHead(int value);

    // Печать списка
    void printAll();

    // Печать определенного элемента списка
    void print(const size_t index);


    /**
    * \brief Копирующий конструктор.
    */
    List(const List& other) = delete;

    /**
    * \brief Перемещающий конструктор.
    */
    List(List&& other) = delete;

    /**
    * \brief Оператор перемещения
    */
    List&& operator = (List& other) = delete;

    /**
    * \brief Оператор копирования
    */
    List& operator = (const List& other) = delete;
};
