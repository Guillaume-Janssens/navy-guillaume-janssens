/*
** EPITECH PROJECT, 2020
** navy
** File description:
** putnbr
*/

#include <unistd.h>
#include "my.h"

int my_putnbr(int nb)
{
    char c;

    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
    }
    if (nb > 9)
        my_putnbr(nb / 10);
    c = (nb % 10 + 48);
    write(1, &c, 1);
    return (0);
}
