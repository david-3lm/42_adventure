int ft_atoi(const char *nptr)
{
	int count;
	int num;
	int aux;
	int i;

	count = strlen(nptr);
	num = 0;
	while (*nptr)
	{
		if ((*nptr < '0' || *nptr > '9') && count)
			return (0);
		else
		{
			i = 0;
			aux = (*nptr - '0');
			while (i < count - 1)
			{
				aux *= 10;
				i++;
			}
			num += aux;
			count--;
		}
		nptr++;
	}
	return (num);
}
