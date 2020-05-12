#pragma once
#include <iostream>

template <class T>
class Vector
{
private:
	T* object;
	size_t size;

	void copy(const Vector& another);
	void destroy();

public:
	Vector();
	Vector(const Vector& another);
	Vector& operator=(const Vector& another);
	~Vector();

	Vector<T> operator+(const Vector<T>& another) const;
	Vector<T>& operator+=(const Vector<T>& another);
	Vector<T>& deleteAfter(size_t number);
	T& operator[](size_t j);
	void swap(size_t first, size_t second);
	void push(const T& another);
	void push_back(const T& another);
	size_t length() const;
	void print() const;

	friend std::ostream& operator<<(std::ostream& stream, Vector<T> vector);
};


template<class T>
inline void Vector<T>::copy(const Vector& another)
{
	this->object = new T[another.size];
	for (size_t i = 0; i < another.size; i++)
	{
		this->object[i] = another.object[i];
	}
	this->size = another.size;
}

template<class T>
inline void Vector<T>::destroy()
{
	delete[] this->object;
}

template<class T>
Vector<T>::Vector()
{
	this->object = nullptr;
	this->size = 0;
}

template<class T>
Vector<T>::Vector(const Vector& another)
{
	copy(another);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector& another)
{
	if (this != &another)
	{
		destroy();
		copy(another);
	}
	return *this;
}

template<class T>
Vector<T>::~Vector()
{
	destroy();
}

template<class T>
Vector<T> Vector<T>::operator+(const Vector& another) const
{
	Vector<T> result;
	result.size = this->size + another.size;
	result.object = new T[result.size];
	for (size_t i = 0; i < this->size; i++)
	{
		result.object[i] = this->object[i];
	}
	for (size_t i = 0; i < another.size; i++)
	{
		result.object[this->size + i] = another.object[i];
	}

	return result;
}

template<class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& another)
{
	T* newBuffer = new T[this->size + another.size];
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->object[i];
	}
	for (size_t i = 0; i < another.size; i++)
	{
		newBuffer[this->size + i] = another.object[i];
	}
	destroy();
	this->size += another.size;
	this->object = newBuffer;
	return *this;
}

template<class T>
inline Vector<T>& Vector<T>::deleteAfter(size_t number)
{
	this->size = number;
	T* biggerBuffer = new T[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		biggerBuffer[i] = this->object[i];
	}
	destroy();
	this->object = biggerBuffer;
	return *this;
}

template<class T>
T& Vector<T>::operator[](size_t j)
{
	return this->object[j];
}

template<class T>
inline void Vector<T>::swap(size_t first, size_t second)
{
	T current = this->object[first];
	this->object[first] = this->object[second];
	this->object[second] = current;
}

template<class T>
void Vector<T>::push(const T& another)
{
	T* newBuffer = new T[this->size + 1];
	newBuffer[0] = another;
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i + 1] = this->object[i];
	}
	destroy();
	this->object = newBuffer;
	size++;
}


template<class T>
void Vector<T>::push_back(const T& another)
{
	T* newBuffer = new T[this->size + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->object[i];
	}
	newBuffer[this->size] = another;
	destroy();
	this->object = newBuffer;
	size++;
}

template<class T>
size_t Vector<T>::length() const
{
	return this->size;
}
