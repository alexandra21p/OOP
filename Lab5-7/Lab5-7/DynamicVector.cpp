#include "stdafx.h"
#include "DynamicVector.h"


#include "DynamicVector.h"


DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
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

void DynamicVector::add(TElement e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

TElement DynamicVector::get(int poz) {
	return elems[poz];
}

void DynamicVector::deleteE(int poz) {
	for (int i = poz; i < size - 1; i++) {
		elems[i] = elems[i + 1];
	}
	size--;
}

void DynamicVector::resize(double factor)
{
	this->capacity *= factor;

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = els[i];

	delete[] this->elems;
	elems = els;
}

TElement* DynamicVector::getAllElems() const
{
	return this->elems;
}

int DynamicVector::getSize() const
{
	return this->size;
}

void DynamicVector::set(int pos, TElement el) {
	elems[pos] = el;
}