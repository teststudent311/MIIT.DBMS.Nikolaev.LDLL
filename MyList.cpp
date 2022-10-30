/*****************************************************************//**
 * \file   MyList.cpp
 * \brief  Объявление методов класса 
 * 
 * \author Nikolaev A. (teststudent311)
 * \date   October 2022
 *********************************************************************/
#include "MyList.h"

List::List()
{
    this->Head = this->Tail = NULL;
    this->count = 0;
}


List::~List()
{
    this->Clear();
}

void List::AddHead(const int value) noexcept
{
    Element* temp = new Element(value);

    temp->prev = 0;
    temp->next = this->Head;

    if (this->Head != 0)
        this->Head->prev = temp;

    if (this->count == 0)
        this->Head = this->Tail = temp;
    else
        this->Head = temp;

    this->count++;
}

void List::AddTail(const int value) noexcept
{
    Element* temp = new Element(value);
    temp->next = 0;
    temp->prev = this->Tail;

    if (this->Tail != 0)
        this->Tail->next = temp;

    // Если элемент первый, то он одновременно и голова, и хвост списка
    if (this->count == 0)
        this->Head = this->Tail = temp;
    else
        this->Tail = temp;

    this->count++;
}

void List::Insert(const int value, const size_t pos)
{   
    if (pos < 1 || pos > this->count + 1)
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

    int i = 1;

    // Отсчитываем от головы n - 1 элементов
    Element* Ins = this->Head;

    while (i < pos)
    {
        Ins = Ins->next;
        i++;
    }

    Element* PrevIns = Ins->prev;
    Element* temp = new Element(value);

    if (PrevIns != 0 && this->count != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    this->count++;
}

void List::Remove(const int value)
{
    return;
}


string List::PrintAll() const noexcept
{
    ostringstream tmpStream;
    // Если в списке есть элементы, то печатаем с головного элемента списка
    if (this->count != 0)
    {
        Element* temp = this->Head;
        while (temp->next != 0)
        {
            tmpStream << temp->data << ", ";
            temp = temp->next;
        }

        return tmpStream.str();
    }
}

void List::Del(const size_t pos)
{
    if (pos < 1 || pos > this->count + 1)
    {
        throw out_of_range("Bad position!");
    }

    int i = 1;

    Element* Del = this->Head;

    while (i < pos)
    {
        Del = Del->next;
        i++;
    }

    Element* PrevDel = Del->prev;
    Element* AfterDel = Del->next;

    // Если удаляем не голову списка
    if (PrevDel != 0 && this->count != 1)
        PrevDel->next = AfterDel;
    // Если удаляем не хвост списка
    if (AfterDel != 0 && this->count != 1)
        AfterDel->prev = PrevDel;

    // Удаляются крайние элементы
    if (pos == 1)
        this->Head = AfterDel;
    if (pos == this->count)
        this->Tail = PrevDel;

    delete Del;

    this->count--;
}

void List::Clear() noexcept
{
    while (this->count != 0)
        Del(1);
}

int List::GetCount() const noexcept
{
    return this->count;
}

bool List::Contains(const int value) const noexcept
{
    return;
}
