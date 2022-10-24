/*****************************************************************//**
 * \file   MyList.h
 * \brief  API ������ �������� ����������� ������
 *
 * \author Nikolaev A. (teststudent311)
 * \date   October 2022
 *********************************************************************/

#pragma once

#include <iostream>

using namespace std;

struct Elem
{
    int data; // ������
    Elem* next, * prev; // ��������� �� ������ � ����� ������
};

class List
{
    // ��������� �� ������ � ����� ������
    Elem* Head, * Tail;
    // ���������� ��������� ������
    int count;

public:

    // �����������
    List();

    // ����������
    ~List();

    // �������� ���������� ���������
    int getCount();

    // �������� ������� ������
    Elem* getElem(const size_t index);

    // ������� ���� ������
    void gelAll();

    // �������� ��������
    void del(const size_t index = 0);

    // ������� ��������
    void insert(const size_t index = 0);

    // ���������� � ����� ������
    void addTail(int value);

    // ���������� � ������ ������
    void addHead(int value);

    // ������ ������
    void printAll();

    // ������ ������������� �������� ������
    void print(const size_t index);


    /**
    * \brief ���������� �����������.
    */
    List(const List& other) = delete;

    /**
    * \brief ������������ �����������.
    */
    List(List&& other) = delete;

    /**
    * \brief �������� �����������
    */
    List&& operator = (List& other) = delete;

    /**
    * \brief �������� �����������
    */
    List& operator = (const List& other) = delete;
};
