#ifndef _STACK_H_
#define _STACK_H_

#include <assert.h>
#include <stdlib.h>

#define DYN_ARRAY_BLOCK_SIZE 16

template<class TYPE>
class cStack
{

private:

	TYPE* data;
	unsigned int allocMemory;
	unsigned int numElements;

public:

	//Constructors
	cStack() : data(NULL), allocMemory(0), numElements(0)
	{
		Reallocate(DYN_ARRAY_BLOCK_SIZE);
	}
	cStack(const unsigned int memSize) : data(NULL), allocMemory(0), numElements(0)
	{
		Reallocate(memSize);
	}

	//Destructors
	~cStack()
	{ 
		delete data; 
	}
	
	//Methods

	//Changes the stack size
	void Reallocate(const unsigned int newSize)
	{
		TYPE* tmp = data;

		allocMemory = newSize;
		data = new TYPE[newSize];
		if (newSize < numElements)
		{
			numElements = newSize;
		}

		for (int i = 0; i < numElements; i++)
		{
			data[i] = tmp[i];
		}

	};

	//Puts an element at the end of the stack
	void Push(const TYPE newElement)
	{
		if (numElements + 1 > allocMemory)
		{
			Reallocate(allocMemory + DYN_ARRAY_BLOCK_SIZE);
		}
		data[numElements] = newElement;
		numElements++;
	}

	//Puts out the last element
	bool Pop(TYPE& value)
	{
		if (numElements != 0)
		{
			value = data[--numElements];
			return true;
		}
		return false;
	}

	//Chooses an element from the stack
	const TYPE Pick(){}

	//other util methods
	unsigned int GetCapacity() const
	{
		return allocMemory;
	}

	unsigned int Count() const
	{
		return numElements;
	}

	void Clear()
	{
		numElements = 0;
	}

	
};

#endif // !_STACK_H_