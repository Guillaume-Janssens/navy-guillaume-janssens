/*
** EPITECH PROJECT, 2020
** my_put_nbr_base
** File description:
** Function that will display numbers in any base.
*/

#include <stdio.h>
#include "printf.h"

void my_putchar(char c);
int my_strlen(char const *str);

int my_put_nbr_base(int nb, char *base)
{
    int len_base = my_strlen(base);
    int result = nb % len_base + 48;
    char b = nb % my_strlen(base) + base[0];

    if (nb > len_base - 1) {
        my_put_nbr_base(nb / len_base, base);
    }
    if (b > '9' && base[10] == 'a') {
        my_putchar(b += 39);
        return (0);
    }
    if (b > '9' && base[10] == 'A') {
        my_putchar(b += 7);
        return (0);
    }
    my_putchar(nb % len_base + 48);
    return (result);
}
