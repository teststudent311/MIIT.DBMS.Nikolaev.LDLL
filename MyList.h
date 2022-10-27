/*****************************************************************//**
 * \file   MyList.h
 * \brief  API класса линейный двухсвязный список
 *
 * \author Nikolaev A. (teststudent311)
 * \date   October 2022
 *********************************************************************/

#pragma once

#include <iostream>
#include <sstream>

using namespace std;

struct Elem
{
    int data; // данные
    Elem* next, * prev; // указатели на начало и конец списка
    Elem(const int data_) noexcept; // конструктор с параметром
};

class List
{
    // Указатели на начало и конец списка
    Elem* Head, * Tail;
    // Количество элементов списка
    int count;

public:

    // Конструктор
    List() noexcept;

    // Деструктор
    ~List() noexcept;

    // Получить количество элементов
    int GetCount() const noexcept;

    // Получить элемент списка
    Elem* getElem(const int value) const;

    // Удалить весь список
    void Clear() noexcept;

    // Удаление элемента
    void Remove(const int value) noexcept;

    // Вставка элемента
    void Insert(const int value) noexcept;

    // Добавление в конец списка
    void AddTail(int value) noexcept;

    // Добавление в начало списка
    void AddHead(int value) noexcept;

    // Печать списка
    string PrintAll() const noexcept;



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
