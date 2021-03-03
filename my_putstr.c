/*
** EPITECH PROJECT, 2020
** putstr
** File description:
** prints displays a string made of char
*/

#include <unistd.h>
#include <limits.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0')
            return (0);
        i += 1;
    }
return (1);
}
