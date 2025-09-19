#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int s)
{
	this->_array = new T[s];
	for (unsigned int i = 0; i < s; i++)
	{
		this->_array[i] = 0;
	}
	this->_size = s;
}

template<typename T>
Array<T>::Array(const Array &other)
{
	this->_array = new T[other.size()];
	this->_size = other.size();
	for (int i = 0; i < this->_size; i++)
	{
		this->_array[i] = other[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	delete [] this->_array;
	this->_array = new T[other.size()];
	this->_size = other.size();
	for (int i = 0; i < this->_size; i++)
	{
		this->_array[i] = other[i];
	}
}


template<typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template <typename T>
T &Array<T>::operator[](int n)
{
	if (n < 0 || n >= this->_size)
	{
		throw OutOfBoundsException();
	}
	return this->_array[n];
}

template <typename T>
T &Array<T>::operator[](int n) const
{
	if (n < 0 || n >= this->_size)
	{
		throw OutOfBoundsException();
	}
	return this->_array[n];
}

template <typename T>
int Array<T>::size() const
{
	return this->_size;
}