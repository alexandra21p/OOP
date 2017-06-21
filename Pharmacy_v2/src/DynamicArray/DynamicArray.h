/*
 * DynamicArray.h
 *
 *  Created on: 31 Mar 2015
 *      Author: Alexandra
 */

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

typedef void* TElem;

class DynamicArray {
public:
	/**
	 * Default constructor
	 */
	DynamicArray();
	/**
	 * Copy constructor
	 */
	DynamicArray(const DynamicArray &ot);

	/**
	 * destructor
	 */
	~DynamicArray();

	DynamicArray& operator=(const DynamicArray& ot);

	/**
	 * Add an element to the dynamic array to the end of the array
	 * e - is a generic element
	 */
	void addE(TElem e);


	/**
	 * Delete the element from the given position
	 * poz - the position of the elem to be deleted, poz>=0; poz<size
	 * return the deleted element
	 */
	TElem deleteElem(int poz);


	/**
	 * insert TElem e at poz p
	 */
	void insert(TElem e, int poz);


	/**
	 * Access the element from a given position
	 * poz - the position (poz>=0; poz<size)
	 */
	TElem get(int poz);


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

private:
	TElem *elems;
	int capacity;
	int size;

	/**
	 * Create enough space to hold nrElem elements
	 * nrElems - the number of elements that we need to store
	 */
	void ensureCapacity(int nrElems);
};



#endif /* DYNAMICARRAY_H_ */
