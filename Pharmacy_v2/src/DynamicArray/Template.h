/*
 * Template.h
 *
 *  Created on: 16 Apr 2015
 *      Author: Alexandra
 */

#ifndef TEMPLATE_H_
#define TEMPLATE_H_

//#include "../cppMemDbg.h"

template<typename Element>
class DynamicArray3 {
public:
	/**
	 * Default constructor
	 */
	DynamicArray3();

	/**
	 * destructor
	 */
	~DynamicArray3();

	/**
	 * Copy constructor
	 */
	DynamicArray3(const DynamicArray3 &ot);

	/**
	 * Assignment operator
	 */
	DynamicArray3& operator=(const DynamicArray3& ot);


	/**
	 * Add an element to the dynamic array to the end of the array
	 * e - is a generic element
	 */
	void addE(Element e);


	/**
	 * Delete the element from the given position
	 * poz - the position of the elem to be deleted, poz>=0;poz<size
	 * returns the deleted element
	 */
	Element deleteElem(int poz);


	/**
	 * Access the element from a given position
	 * poz - the position (poz>=0;poz<size)
	 */
	Element get(int poz) const;


	/**
	 * Set the element from a given position
	 * poz - the position (poz>=0;poz<size)
	 */
	void set(int poz, Element el);


	/**
	 * Give the size of the array
	 * return the number of elements in the array
	 */
	int getSize();

	/**
	 * Clear the array
	 * Post: the array will contain 0 elements
	 */
	void clear();

	/*
	 * reduce the size of the array
	 */
	void reduceSize();

private:
	Element *elems;
	int capacity;
	int size;


	/**
	 * Create enough space to hold nrElem elements
	 * nrElems - the number of elements that we need to store
	 */
	void ensureCapacity(int nrElems);
};


template<typename Element>

DynamicArray3<Element>::DynamicArray3() {
	capacity = 10;
	elems = new Element[capacity];
	size = 0;
}

template<typename Element>
DynamicArray3<Element>::~DynamicArray3() {
	delete[] elems;
}

template<typename Element>
DynamicArray3<Element>::DynamicArray3(const DynamicArray3<Element>& d) {
	this->capacity = d.capacity;
	this->size = d.size;
	this->elems = new Element[capacity];
	for (int i = 0; i < d.size; i++) {
		this->elems[i] = d.elems[i];
	}
}

/**
 * Operator for assignment
 */
template<typename Element>
DynamicArray3<Element>& DynamicArray3<Element>::operator=(
		const DynamicArray3<Element>& ot) {
	if (this == &ot) {
		// protect against self-assignment (a = a)
		return *this;
	}
	//delete the allocated memory
	delete[] this->elems;

	this->elems = new Element[ot.capacity];
	for (int i = 0; i < ot.size; i++) {
		this->elems[i] = ot.elems[i];
	}
	this->capacity = ot.capacity;
	this->size = ot.size;
	return *this;
}

/**
 * Create enough space to hold nrElem elements
 * nrElems - the number of elements that we need to store
 */
template<typename Element>
void DynamicArray3<Element>::ensureCapacity(int nrElems) {
	if (capacity >= nrElems) {
		return; //we have space to store the values
	}
	//we need to allocate more space for the values
	Element *aux = elems;
	//create space to hold more numbers
	capacity = capacity * 2;
	elems = new Element[capacity];
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
template<typename Element>
void DynamicArray3<Element>::addE(Element e) {
	ensureCapacity(size + 1);
	elems[size] = e;
	size++;
}

/**
 * Access the element from a given position
 * poz - the position (poz>=0; poz<size)
 */
template<typename Element>
Element DynamicArray3<Element>::get(int poz) const {
	return elems[poz];
}

template<typename Element>
void DynamicArray3<Element>::set(int poz, Element el) {
	elems[poz] = el;
}

/**
 * Give the size of the array
 * return the number of elements in the array
 */
template<typename Element>
int DynamicArray3<Element>::getSize() {
	return size;
}

/**
 * Clear the array
 * Post: the array will contain 0 elements
 */
template<typename Element>
void DynamicArray3<Element>::clear() {
	size = 0;
}

/**
 * Delete the element from the given position
 * poz - the position of the elem to be deleted, poz>=0; poz<size
 * return the deleted element
 */
template<typename Element>
Element DynamicArray3<Element>::deleteElem(int poz) {
	Element rez = elems[poz];
	for (int i = poz; i < size - 1; i++) {
		elems[i] = elems[i + 1];
	}
	size--;
	return rez;
}


template<typename Element>
void DynamicArray3<Element>::reduceSize() {
	size--;
}

#endif /* TEMPLATE_H_ */