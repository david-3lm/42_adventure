#include <algorithm>

class ValueNotFoundException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "Value not found";
		}
};

template <typename T>
int easyfind(T arr, int i)
{
    typename T::const_iterator it = std::find(arr.begin(), arr.end(), i);
	if (it != arr.end())
	{
		return *it;
	}
	throw ValueNotFoundException();
}