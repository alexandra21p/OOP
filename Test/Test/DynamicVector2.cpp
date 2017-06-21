#include "stdafx.h"
#include "DynamicVector2.h"



DynamicVector2::DynamicVector2(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector2::DynamicVector2(const DynamicVector2& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector2::~DynamicVector2()
{
	delete[] this->elems;
}

DynamicVector2& DynamicVector2::operator=(const DynamicVector2& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

void DynamicVector2::add(TElement e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

TElement DynamicVector2::get(int poz) {
	return elems[poz];
}

void DynamicVector2::deleteE(int poz) {
	for (int i = poz; i < size - 1; i++) {
		elems[i] = elems[i + 1];
	}
	size--;
}

void DynamicVector2::resize(double factor)
{
	this->capacity *= factor;

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = els[i];

	delete[] this->elems;
	elems = els;
}

TElement* DynamicVector2::getAllElems() const
{
	return this->elems;
}

int DynamicVector2::getSize() const
{
	return this->size;
}

void DynamicVector2::set(int pos, TElement el) {
	elems[pos] = el;
}