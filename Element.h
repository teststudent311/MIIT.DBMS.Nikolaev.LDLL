/*****************************************************************//**
 * \file   Element.h
 * \brief  API класса элемент
 * 
 * \author Dfgtr
 * \date   November 2022
 *********************************************************************/
#pragma once

#include <iostream>
#include <sstream>

using namespace std;
 
class Element
{
public:
    // Значение элемента
    int data;
    // Указатели на начало и конец списка
    Element* next;
    Element* prev;

    /**
     * \brief Конструктор класса
     */
    Element(const int data_) noexcept;

    /**
     * \brief Деструктор класса
      */
    ~Element() noexcept;
};



