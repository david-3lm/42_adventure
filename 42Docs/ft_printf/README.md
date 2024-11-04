# ft_printf

## Descripción
El objetivo de este proyecto es clonar la funcionalidad de la función `printf` de la biblioteca estándar de C (`libc`). La implementación soporta varias especificaciones de formato, incluyendo caracteres, cadenas, números enteros en distintas bases y punteros.

## Dependencias
Este proyecto depende de la biblioteca [[Libft/README]], una colección de funciones útiles que se utiliza comúnmente en proyectos de C. Asegúrate de tener  [[Libft/README]] disponible y correctamente compilada.

## Funcionalidades
La función `ft_printf` replica el comportamiento de la `printf` original, soportando los siguientes especificadores de formato:

- `%c` : Imprime un solo carácter.
- `%s` : Imprime una cadena de caracteres.
- `%d` o `%i` : Imprime un número entero decimal con signo.
- `%u` : Imprime un número entero decimal sin signo.
- `%x` : Imprime un número en formato hexadecimal (letras minúsculas).
- `%X` : Imprime un número en formato hexadecimal (letras mayúsculas).
- `%p` : Imprime una dirección de memoria (puntero).
- `%%` : Imprime un signo de porcentaje literal.

## Compilación
Para compilar `ft_printf`, asegúrate de que `Libft` esté compilada y disponible en el directorio del proyecto. Luego, compila `ft_printf` junto con tus archivos de prueba de la siguiente manera:

```sh
gcc -Wall -Wextra -Werror ft_printf.c test_ft_printf.c -L. -lft -o test_ft_printf
