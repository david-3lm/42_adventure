#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// Test case for character
	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');

	// Test case for string
	ft_printf("String: %s\n", "Hello\nWorld\t!");
	printf("String: %s\n", "Hello\nWorld\t!");

	// Test case for decimal number
	ft_printf("Decimal: %d\n", 12345);
	printf("Decimal: %d\n", 12345);

	// Test case for integer
	ft_printf("Integer: %i\n", -12345);
	printf("Integer: %i\n", -12345);


	// Test case for unsigned integer
	ft_printf("Unsigned: %u\n", 12345);
	printf("Unsigned: %u\n", 12345);

	// Test case for hexadecimal (lowercase)
	ft_printf("Hexadecimal (lowercase): %x\n", 0);
	printf("Hexadecimal (lowercase): %x\n", 0);

	// Test case for hexadecimal (uppercase)
	ft_printf("Hexadecimal (uppercase): %X\n", 255);
	printf("Hexadecimal (uppercase): %X\n", 255);

	// Test case for pointer
	int num = 42;
	ft_printf("Pointer: %p\n", NULL);
	printf("Pointer: %p\n", NULL);

	// Test case for percentage
	printf("Percentage: %1\n");
	ft_printf("Percentage: %1\n");

	return 0;
}
