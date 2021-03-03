/*
** EPITECH PROJECT, 2020
** navy
** File description:
** my revstr
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    char tmp = '0';

    while (i <= (len / 2)) {
        tmp = str[i];
        str[i] = str[(len - 1) - i];
        str[(len - 1) - i] = tmp;
        i += 1;
    }
    return (str);
}
