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

/**
 * \brief Структура состоящая из 3 эелементов:
 *        data - значение элемента списка
 *        Element* next - указатели на начало списка
 *        Element* prev - указатели на конец списка
 */
struct Element
{
    int data; 
    Element* next;
    Element* prev;

    /**
     * \brief Конструктор для создания элемента списка 
     */
    Element(const int data_) noexcept;
};

class List
{
    // Указатели на начало и конец списка
    Element* Head;
    Element* Tail;
    // Количество элементов списка
    int count;

public:

    /**
    * \brief Конструктор класса
    */
    List() noexcept;

    /**
     * \brief Деструктор класса
     */
    ~List() noexcept;

    /**
     * \brief Функция для подсчета элементов списка
     * \return int - количество элементов списка 
     */
    int GetCount() const noexcept;

    /**
     * \brief Проверяет есть такой элемент в списке
     * \param value - значение элемента
     * \return true - если есть такой элемент, иначе - false
     */
    bool Contains(const int value) const noexcept;

    /**
     * \brief Функция очистки списка
     */
    void Clear();

    /**
     * \brief Функция для удаления элемента списка по индексу
     * \param pos - индекс элемента
     */
    void Del(const size_t pos);

    /**
     * \brief Функция для удаления элемент списка по значению
     * \param value - значение элемента
     */
    void Remove(const int value);

    /**
     * \brief Функция встраивания элемента
     * \param value - значение элемента
     */
    void Insert(const int value, const size_t pos);

    /**
     * \brief Функция добавления элемента в конец списка
     * \param value - значение элемента
     */
    void AddTail(const int value) noexcept;

    /**
     * \brief Функция добавления элемента в начало списка
     * \param value - значение элемента
     */
    void AddHead(const int value) noexcept;

    /**
     * \brief Функция сохранения в строку списка
     * \return строка содержащая список
     */
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
