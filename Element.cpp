/*****************************************************************//**
 * \file   Element.cpp
 * \brief  Объявление методов класса 
 * 
 * \author Dfgtr
 * \date   November 2022
 *********************************************************************/

#include "Element.h"  

Element::Element(const int data_) noexcept
{
	this->data = data_;
	this->next = nullptr;
	this->prev = nullptr;
}

Element::~Element() noexcept
{
	this->data = 0;
	this->next = nullptr;
	this->prev = nullptr;
}