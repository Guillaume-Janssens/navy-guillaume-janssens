/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Function that display characters of a string
*/

#include <unistd.h>
#include <stdlib.h>
#include "printf.h"

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        my_putchar(' ');
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}
