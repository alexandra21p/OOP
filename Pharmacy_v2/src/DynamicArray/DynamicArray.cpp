/*
 * DynamicArray.cpp
 *
 *  Created on: 31 Mar 2015
 *      Author: Alexandra
 */

#include "DynamicArray.h"


DynamicArray::DynamicArray() {
	capacity = 10;
	elems = new TElem[capacity];
	size = 0;
}

DynamicArray::~DynamicArray() {
	delete[] elems;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& ot) {
	if (&ot == this) {
		return *this;
	}
	TElem* aux = new TElem[ot.capacity];
	for (int i = 0; i < ot.size; i++) {
		aux[i] = ot.elems[i];
	}
	delete[] elems;
	elems = aux;
	size = ot.size;
	capacity = ot.capacity;
	return *this;
}

DynamicArray::DynamicArray(const DynamicArray &ot) {
	elems = new TElem[ot.capacity];
	for (int i = 0; i < ot.size; i++) {
		elems[i] = ot.elems[i];
	}
	size = ot.size;
}

/**
 * Create enough space to hold nrElem elements
 * nrElems - the number of elements that we need to store
 */
void DynamicArray::ensureCapacity(int nrElems) {
	if (capacity >= nrElems) {
		return; //we have space to store the values
	}
	//we need to allocate more space for the values
	TElem *aux = elems;
	//create space to hold more numbers
	capacity = capacity * 2;
	elems = new TElem[capacity];
	//copy the values
	for (int i = 0; i < size; i++) {
		elems[i] = aux[i];
	}
	//release the memory
	delete[] aux;
}
/**
 * Add an element to the dynamic array
 * e - is a generic element
 */
void DynamicArray::addE(TElem e) {
	ensureCapacity(size + 1);
	elems[size] = e;
	size++;
}

/**
 * Access the element from a given position
 * poz - the position (poz>=0 ;poz<size)
 */
TElem DynamicArray::get(int poz) {
	return elems[poz];
}
/**
 * Give the size of the array
 * return the number of elements in the array
 */
int DynamicArray::getSize() {
	return size;
}

/**
 * Clear the array
 * Post: the array will contain 0 elements
 */
void DynamicArray::clear() {
	size = 0;
}

/**
 * Delete the element from the given position
 * poz - the position of the elem to be deleted, poz>=0; poz<size
 * return the deleted element
 */
TElem DynamicArray::deleteElem(int poz) {
	TElem rez = elems[poz];
	for (int i = poz; i < size - 1; i++) {
		elems[i] = elems[i + 1];
	}
	size--;
	return rez;
}

void DynamicArray::insert(TElem e, int poz)
{
	ensureCapacity(size + 1);
	int i;
	this->size++;
	for (i=this->size-1;i>poz;i--)
	{
		this->elems[i]=this->elems[i-1];
	}
	elems[poz] = e;

}

