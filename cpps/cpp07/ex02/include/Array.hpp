#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *_array;
	int _size;
public:
	Array();
	Array(unsigned int s);
	Array(const Array &other);
	~Array();

	Array &operator=(const Array &other);
	T &operator[](int n) const;
	T &operator[](int n);
	int size() const;

	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

template <typename T>
inline const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Fuera de los límites!!!";
}

#include "../src/Array.tpp"
#endif