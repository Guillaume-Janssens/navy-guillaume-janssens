/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** to print numbers
*/

#include "my.h"

int my_count_neg(char const *str)
{
    int i = 0;
    int neg = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg = neg + 1;
        i += 1;
    }
    return (neg);
}

int my_getnbr(char const *str)
{
    int count = 0;
    int neg = 1;
    int nb = 0;

    while (str[count] == '+' || str[count] == '-')
        count += 1;
    while (str[count] >= '0' && str[count] <= '9') {
        nb =  nb * 10;
        nb = nb + str[count] - 48;
        count += 1;
    }
    if (my_count_neg(str) % 2 != 0)
        neg = -1;
    nb = neg * nb;
    return (nb);
}
