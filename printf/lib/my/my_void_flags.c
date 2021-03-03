/*
** EPITECH PROJECT, 2020
** my void
** File description:
** Flags void functions
*/

#include <unistd.h>
#include "printf.h"

void my_char(va_list ap, char const *format, int *i)
{
    if (format[*i] == 'c')
        my_putchar(va_arg(ap, int));
    else
        write(2, "84", 2);
}

void my_string(va_list ap, char const *format, int *i)
{
    if (format[*i] == 's')
        my_putstr(va_arg(ap, char *));
    else
        write(2, "84", 2);
}

void my_integer(va_list ap, char const *format, int *i)
{
    char *base = "0123456789";

    if (format[*i] == 'd' || format[*i] == 'i' ||
        format[*i] == 'u')
        my_put_nbr_base(va_arg(ap, int), base);
    else
        write(2, "84", 2);
}

void my_integer_plus(va_list ap, char const *format, int *i)
{
    char *base = "0123456789";
    int nb = va_arg(ap, int);

    if ((format[*i] == '+' && format[*i + 1] == 'd')
        || (format[*i + 1] == 'i') || (format[*i + 1] == 'u')) {
        if (nb > 0) {
            my_putchar('+');
            my_put_nbr_base(nb, base);
            *i += 1;
        }
        else if (nb < 0) {
            my_putchar('-');
            my_put_nbr_base(nb, base);
            *i += 1;
        }
        else
            my_put_nbr_base(nb, base);
    }
}

void my_integer_octal(va_list ap, char const *format, int *i)
{
    char *base = "01234567";

    if (format[*i] == 'o')
        my_put_nbr_base(va_arg(ap, int), base);
    else
        write(2, "84", 2);
}
