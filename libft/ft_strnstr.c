#include <stdio.h>
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	i = 0;
	if (!ft_strlen(little))
		return (big);
	while (*big)
	{
		while (big[i] == little[i] && i < len - 1)
			i++;
		if (big[i] == little[i] || !little[i])
			return (big);
		i = 0;
		big++;
	}
	return (0);
}
	//Faltan pruebas