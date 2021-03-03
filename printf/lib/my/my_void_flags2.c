/*
** EPITECH PROJECT, 2020
** my void flags 2
** File description:
** Functions void for flag finder
*/


#include <unistd.h>
#include "printf.h"

void my_integer_hexa(va_list ap, char const *format, int *i)
{
    char *base = "0123456789abcdef";

    if (format[*i] == '%' && format[*i + 1] == 'x')
        my_put_nbr_base(va_arg(ap, int), base);
    else
        write(2, "84", 2);
}

void my_integer_hexa_capital_letters(va_list ap, char const *format, int *i)
{
    char *base = "0123456789ABCDEF";

    if (format[*i] == '%' && format[*i + 1] == 'X')
        my_put_nbr_base(va_arg(ap, int), base);
    else
        write(2, "84", 2);
}

void my_binary_base(va_list ap, char const *format, int *i)
{
    char *base = "01";

    if (format[*i] == '%' && format[*i + 1] == 'b')
        my_put_nbr_base(va_arg(ap, int), base);
    else
        write(2, "84", 2);
}
