#pragma once

class Vector
{
public:
	Vector();
	Vector(const int &size, const int &defaultValue);
	Vector(const Vector &vector);
	~Vector();
	int PopBack();
	int At(int element);
	bool IsEmpty() const;
	void ClearAll();
	void ShowAll() const;
	void Swap(Vector &vector);
	void PushBack(const int &data);
	void Insert(unsigned int position, int data);
	const size_t Size() const;
	const size_t Capacity() const;
	int operator[](size_t index);

private:
	void RellocateMemoryUp();
	void RellocateMemoryDown();
	void RellocateMemoryAftClr();

private:
	const size_t m_resizeStep = 10;
	const size_t m_firstCapacity = 10;
	size_t m_currentCapacity = 10;
	size_t m_currentSize = 0;
	int *m_ptrArr = nullptr;
};
