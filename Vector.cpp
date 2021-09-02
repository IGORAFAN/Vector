#include "Vector.h"
#include <iostream>

Vector::Vector()
	: m_ptrArr(new int[m_firstCapacity])
{
}

Vector::Vector(const int &size, const int &defaultValue)
	: m_ptrArr(new int[m_firstCapacity])
{
	for (int iter = 0; iter < size; ++iter)
	{
		PushBack(defaultValue);
	}
}

Vector::Vector(const Vector &vector)
	: m_ptrArr(new int[m_firstCapacity])
{
	for (size_t iter = 0; iter < vector.m_currentSize; ++iter)
	{
		this->PushBack(vector.m_ptrArr[iter]);
	}
}

Vector::~Vector()
{
	delete[] m_ptrArr;
}

int Vector::PopBack()
{
	RellocateMemoryDown();
	int result = m_ptrArr[m_currentSize];

	--m_currentSize;
	return result;
}

int Vector::At(int element)
{
	return m_ptrArr[element - 1];
}

void Vector::Insert(unsigned int position, int data)
{
	--position; //cuz index
	RellocateMemoryUp();
	for (size_t iter = m_currentSize; iter >= position; --iter)
	{
		m_ptrArr[iter] = m_ptrArr[iter - 1];
	}
	m_ptrArr[position] = data;
	++m_currentSize;
}

void Vector::PushBack(const int &data)
{
	RellocateMemoryUp();
	m_ptrArr[m_currentSize] = data;
	++m_currentSize;
}

void Vector::ClearAll()
{
	RellocateMemoryAftClr();
	m_currentSize = 0;
}

void Vector::ShowAll() const
{
	for (size_t iter = 0; iter < m_currentSize; ++iter)
	{
		std::cout << (iter + 1) << " element: " << m_ptrArr[iter] << std::endl;
	}
	std::cout << std::endl;
}

void Vector::Swap(Vector &vector)
{
	int *tempArr = vector.m_ptrArr;
	size_t tempSize = vector.m_currentSize;
	size_t tempCapacity = vector.m_currentCapacity;
	vector.m_ptrArr = this->m_ptrArr;
	vector.m_currentSize = this->m_currentSize;
	vector.m_currentCapacity = this->m_currentCapacity;
	this->m_ptrArr = tempArr;
	this->m_currentSize = tempSize;
	this->m_currentCapacity = tempCapacity;
}

void Vector::RellocateMemoryUp()
{
	if (m_currentSize == m_currentCapacity)
	{
		int *tempPointer = new int[m_currentCapacity + m_resizeStep];
		for (size_t iter = 0; iter < m_currentSize; ++iter)
		{
			tempPointer[iter] = m_ptrArr[iter];
		}
		delete[] m_ptrArr;
		m_ptrArr = tempPointer;
		m_currentCapacity = m_currentCapacity + m_resizeStep;
	}
}

void Vector::RellocateMemoryDown()
{
	if (m_currentSize < (m_currentCapacity - m_resizeStep))
	{
		int *tempPointer = new int[m_currentCapacity - m_resizeStep];
		for (size_t iter = 0; iter < m_currentSize; ++iter)
		{
			tempPointer[iter] = m_ptrArr[iter];
		}
		delete[] m_ptrArr;
		m_ptrArr = tempPointer;
		m_currentCapacity = m_currentCapacity - m_resizeStep;
	}
}

void Vector::RellocateMemoryAftClr()
{
	int *tempPointer = new int[m_firstCapacity];
	delete[] m_ptrArr;
	m_ptrArr = tempPointer;
	m_currentCapacity = m_firstCapacity;
}

bool Vector::IsEmpty() const
{
	return m_currentSize;
}

const size_t Vector::Size() const
{
	return m_currentSize;
}

const size_t Vector::Capacity() const
{
	return m_currentCapacity;
}

int Vector::operator[](size_t index)
{
	return m_ptrArr[index];
}