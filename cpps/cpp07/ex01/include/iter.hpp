#include <iostream>

// template <typename T> 
// void iter(T *ptr, const int len, void (*f)(T const &))
// {
// 	T *aux = ptr;
	
// 	for (int i = 0; i < len; i++)
// 	{
// 		f(aux[i]);
// 	}
// }

// template <typename T> 
// void iter(T *ptr, const int len, void (*f)(T &))
// {
// 	T *aux = ptr;
	
// 	for (int i = 0; i < len; i++)
// 	{
// 		f(aux[i]);
// 	}
// }

template <typename T, typename F> 
void iter(T *ptr, const int len, F f)
{
	T *aux = ptr;
	
	for (int i = 0; i < len; i++)
	{
		f(aux[i]);
	}
}