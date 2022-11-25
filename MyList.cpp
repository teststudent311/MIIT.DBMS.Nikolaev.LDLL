/*****************************************************************//**
 * \file   MyList.cpp
 * \brief  Объявление методов класса 
 * 
 * \author Nikolaev A. (teststudent311)
 * \date   October 2022
 *********************************************************************/
#include "MyList.h"

List::List() noexcept : head(nullptr), tail(nullptr), count(0)
{}

List::~List()
{
    while (this->count != 0)
    {
        Delete(0);
    }
}

void List::AddHead(const int value) noexcept
{
    Element* temp = new Element(value);
    temp->prev = nullptr;
    temp->next = this->head;

    if (this->head != nullptr)
    {
        this->head->prev = temp;
    }
    if (this->count == 0)
    {
        this->tail = temp;
        this->head = temp;
    }
    else
    {
        this->head = temp;
    }

    this->count++;
}

void List::AddTail(const int value) noexcept
{
    Element* temp = new Element(value);
    temp->next = nullptr;
    temp->prev = this->tail;

    if (this->tail != nullptr)
    {
        this->tail->next = temp;
    }
    if (this->count == 0)
    {
        this->tail = temp;
        this->head = temp;
    }
    else
    {
        this->tail = temp;
    }

    this->count++;
}

void List::Insert(const int value, const size_t position)
{   
    if (position > this->count)
    {
        throw out_of_range("Bad position!");
    }
    if (position == 0)
    {
        this->AddHead(value);
        return;
    }
    if (position == this->count)
    {
        this->AddTail(value);
        return;
    }

    Element* prevInsert = this->head;
    for (size_t index = 0; index < position - 1; index++)
    {
        prevInsert = prevInsert->next;
    }

    Element* elementToInsert = new Element(value);
    Element* nextInsert = prevInsert->next;
    prevInsert->next = elementToInsert;
    elementToInsert->prev = prevInsert; 
    elementToInsert->next = nextInsert;

    this->count++;
}


string List::ToString() const noexcept
{
    ostringstream tmpStream;

    Element* temp = this->head;
    for (size_t index = 0; index < this->count; index++)
    {
        tmpStream << temp->data;
        if (index != this->count - 1)
        {
            tmpStream << ", ";
        }
        temp = temp->next;
    }
    return tmpStream.str();
}

void List::Remove(const int value)
{
    if (Contains(value) == false)
    {
        throw out_of_range("Out of range!");
    }

    Element* tmp = this->head;
    int index = -1;

    for (size_t i = 0; i < this->count; i++)
    {
        if (tmp->data == value)
        {
            index = i;
        }
        tmp = tmp->next;
        
    }

    static_cast<size_t>(index);
    Delete(index);
    
}

void List::Delete(const size_t position)
{
    if (position > this->count - 1)
    {
        throw out_of_range("Выход за пределы массива");
    }

    Element* tmp = this->head;
    for (size_t index = 0; index < position; index++)
    {
        tmp = tmp->next;
    }

    if (this->count == 1)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        Element* prevDelete = tmp->prev;
        Element* nextDelete = tmp->next;
        if (prevDelete != nullptr)
        {
            prevDelete->next = nextDelete;
        }
        if (nextDelete != nullptr)
        {
            nextDelete->prev = prevDelete;
        }
        if (tmp == this->head)
        {
            this->head = nextDelete;
        }
        if (tmp == this->tail)
        {
            this->tail = prevDelete;
        }
    }
    this->count--;
}

bool List::Contains(const int value) const noexcept
{
    Element* tmp = this->head;

    for (size_t i = 0; i < this->count; i++)
    {
        if (tmp->data == value)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

List::List(const List& other) noexcept
{
    this->head = other.head;
    this->tail = other.tail;
}

List::List(List&& other) noexcept
{
    this->head = other.head;
    this->tail = other.tail;
    
    other.~List();
}

List& List::operator = (List&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    this->~List();

    this->head = other.head;
    this->tail = other.tail;

    other.head = nullptr;
    other.tail = nullptr;

    return *this;
}

List& List::operator = (const List& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    Element* temp = other.head;

    while (temp != 0)
    {
        AddTail(temp->data);
        temp = temp->next;
    }

    return *this;
}
