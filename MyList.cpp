/*****************************************************************//**
 * \file   MyList.cpp
 * \brief  Объявление методов класса 
 * 
 * \author Nikolaev A. (teststudent311)
 * \date   October 2022
 *********************************************************************/
#include "MyList.h"

List::List(): head(nullptr), tail(nullptr), count(0)
{}


List::~List()
{
    this->Clear();
}

void List::AddHead(const int value) noexcept
{
    Element* temp = new Element(value);

    temp->prev = nullptr;
    temp->next = this->head;

    if (this->head != nullptr)
        this->head->prev = temp;

    if (this->count == 0)
    {
        this->tail = temp;
        this->head = temp;
    }
    else
        this->head = temp;

    this->count++;
}

void List::AddTail(const int value) noexcept
{
    Element* temp = new Element(value);
    temp->next = nullptr;
    temp->prev = this->tail;

    if (this->tail != nullptr)
        this->tail->next = temp;

    // Если элемент первый, то он одновременно и голова, и хвост списка
    if (this->count == 0)
    {
        this->tail = temp;
        this->head = temp;
    }
    else
        this->tail = temp;

    this->count++;
}

void List::Insert(const int value, const size_t pos)
{   
    if (pos > this->count + 1)
    {
        throw out_of_range("Bad position!");
    }

    if (pos == this->count + 1)
    {
        AddTail(value);
        return;
    }
    else if (pos == 1)
    {
        AddHead(value);
        return;
    }

    size_t i = 1;

    // Отсчитываем от головы n - 1 элементов
    Element* ins = this->head;

    while (i < pos)
    {
        ins = ins->next;
        i++;
    }

    Element* prevIns = ins->prev;
    Element* temp = new Element(value);

    if (prevIns != nullptr && this->count != 1)
        prevIns->next = temp;

    temp->next = ins;
    temp->prev = prevIns;
    ins->prev = temp;

    this->count++;
}


string List::PrintAll() const noexcept
{
    ostringstream tmpStream;
    // Если в списке есть элементы, то печатаем с головного элемента списка
    if (this->count != 0)
    {
        Element* temp = this->head;
        while (temp->next != nullptr)
        {
            tmpStream << temp->data << ", ";
            temp = temp->next;
        }

        return tmpStream.str();
    }
}

void List::Remove(const int value)
{
    if (Contains(value) == false)
    {
        throw out_of_range("Out of range!");
    }

    Element* tmp = this->head;
    int index = -1;

    for (size_t i = 0; i < count - 1; i++)
    {
        if (tmp->data == value)
            index = i;
        
    }

    if (index <= -1)
    {
        throw out_of_range("Didn`t find values!");
    }

    static_cast<size_t>(index);
    Delete(index);
    
}

void List::Delete(const size_t pos)
{
    if (pos > this->count + 1)
    {
        throw out_of_range("Bad position!");
    }

    size_t i = 1;

    Element* del = this->head;

    while (i < pos)
    {
       del =del->next;
        i++;
    }

    Element* prevDel =del->prev;
    Element* afterDel =del->next;

    // Если удаляем не голову списка
    if (prevDel != nullptr && this->count != 1)
        prevDel->next = afterDel;
    // Если удаляем не хвост списка
    if (afterDel != nullptr && this->count != 1)
        afterDel->prev = prevDel;

    // Удаляются крайние элементы
    if (pos == 1)
        this->head = afterDel;
    if (pos == this->count)
        this->tail = prevDel;

    delete del;

    this->count--;
}

void List::Clear() noexcept
{
    while (this->count != 0)
        Delete(1);
}

size_t List::GetCount() const noexcept
{
    return this->count;
}

bool List::Contains(const int value) const noexcept
{
    Element* tmp = this->head;

    for (size_t i = 0; i < count-1; i++)
    {
        if (tmp->data == value)
            return true;
        tmp = tmp->next;

    }

    return false;
}
