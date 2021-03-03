/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Function principal that reproduce printf behaviour.
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

int my_condition(char const *format, int *i, va_list ap)
{
    int y = 0;

    void (*tab_fct[NOMBRE_DE_FLAG]) (va_list ap, char const *format, int *i) =
        {my_string, my_integer, my_integer,
         my_char, my_integer_octal, my_integer, my_integer_hexa,
         my_integer_hexa_capital_letters, my_integer_plus, my_binary_base};
    
    if (format[*i] == '%' && format[*i + 1] == '%') {
        my_putchar('%');
        *i += 1;
    }
    else if (format[*i] == '%') {
        *i += 1;
        y = my_flag_finder(format[*i]);
        if (y == 84) {
            return (84);
        }
        tab_fct[y](ap, format, i);
    } else
        my_putchar(format[*i]);
    return (0);
}

int my_printf(char const *format, ...)
{
    int i = 0;
    int c = 0;
    va_list ap;

    va_start(ap, format);
    while (format[i] != '\0') {
        c = my_condition(format, &i, ap);
        if (c == 84) {
            return (84);
        }
        i += 1;
    }
    va_end(ap);
    return (0);
}
