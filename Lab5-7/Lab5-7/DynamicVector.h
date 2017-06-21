#pragma once
#include "Tutorial.h"

typedef Tutorial TElement;
class DynamicVector
{

private:
	TElement* elems;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);

	// destructor
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// Adds an element to the current DynamicVector.
	void add(TElement e);

	/**
	* Delete the element from the given position
	* poz - the position of the elem to be deleted, poz>=0; poz<size
	* return the deleted element
	*/
	void deleteE(int poz);


	/**
	* Access the element from a given position
	* poz - the position (poz>=0; poz<size)
	*/
	TElement get(int poz);

	void set(int pos, TElement el);

	int getSize() const;

	TElement* getAllElems() const;

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};

