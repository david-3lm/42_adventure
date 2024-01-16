
// #include "ft_isalnum.c"
// #include "ft_isalpha.c"
// #include "ft_isdigit.c"
// #include "ft_isascii.c"
// #include "ft_isprint.c"
// #include "ft_strlen.c"
// #include "ft_memset.c"
// #include "ft_bzero.c"
// #include "ft_memcpy.c"
// #include "ft_memmove.c"
// #include "ft_strlcpy.c"
// #include "ft_strlcat.c"


#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	int a = 70;
	char *b = "";

	printf("isalpha:\n");
	printf("%d\n", isalpha(a));
	printf("%d\n\n", ft_isalpha(a));

	printf("Digit:\n");
	printf("%d\n", isdigit(a));
	printf("%d\n\n", ft_isdigit(a));

	printf("Alnum:\n");
	printf("%d\n", isalnum(a));
	printf("%d\n\n", ft_isalnum(a));

	printf("ASCII:\n");
	printf("%d\n", isascii(a));
	printf("%d\n\n", ft_isascii(a));

	printf("PRINTABLE:\n");
	printf("%d\n", isprint(a));
	printf("%d\n\n", ft_isprint(a));

	printf("LEN:\n");
	printf("%lu\n", strlen(b));
	printf("%lu\n\n", ft_strlen(b));
	
	char str[50] = "Hola Mundo!";
	char *str2 = str;
	printf("MEMSET:\n");
	printf("%s\n", memset(str, 'd', 3));

	printf("%s\n\n", ft_memset(str2, 'd', 3));

	char str3[50] = "Hola Mundo!";
	char *str4 = str3;
	printf("BZERO:\n");
	void *c= bzero(str3, 3);
	printf("%s\n", c);
	c+=3;
	printf("%s\n", c);
	void *d= ft_bzero(str4, 3);
	printf("%s\n", d);
	d+=3;
	printf("%s\n", d);

	printf("MEMCPY:\n");
	char src[50] = "asdadwdsdwds";
	char dst[50];
	//char dst2[50];
	printf("%s\n", memcpy(dst, src, 6));

	printf("%s\n\n", ft_memcpy(dst, src, 6));

	char srca[] = "Hola, mundo!";
	printf("MEMMOVE:\n");

    char *result = ft_memmove(srca, &srca[2], sizeof(srca));
    printf("El valor devuelto por memmove es %s\n\n", result);

	char srcCpy[] = "Hola, mundo!";
	char dstCpy[50];
	unsigned long len;

	len = strlcpy(dstCpy, srcCpy, 2);
	printf("STRLCPY:\n");

	printf("Copied string: %s\n", dstCpy);
	printf("Length of copied string: %lu\n\n", len);

	printf("_______no_______STRLCAT_________funciona___________:\n");

	char srcCat[] = " mundo!";
	char dstCat[50] = "Hola,";

	len = ft_strlcat(dstCat, srcCat, 1);

	printf("Concatenated string: %s\n", dstCat);
	printf("Length of concatenated string: %lu\n", len);

	printf("UPPERlower:\n");

	printf("TO UPPER: %d\n", ft_toupper('a'));
	printf("to lower: %d\n\n", ft_tolower('A'));

	printf("ATOI:\n");

	char *atoinum = "    2147483649";
	printf("MIO: %d\n", ft_atoi(atoinum));
	printf("LIB: %d\n\n", atoi(atoinum));
}
