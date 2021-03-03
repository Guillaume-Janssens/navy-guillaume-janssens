/*
** EPITECH PROJECT, 2020
** my_flag_finder
** File description:
** my_flag_finder
*/

#include <stdio.h>
#include "printf.h"

int my_flag_finder(char element)
{
    int i = 0;
    char tab_flags[NOMBRE_DE_FLAG] = {'s', 'd', 'i', 'c', 'o', 'u', 'x', 'X',
        '+','b'};

    while (tab_flags[i] != '\0') {
        if (tab_flags[i] == element) {
            return (i);
        }
        else
            i += 1;
    }
    return (84);
}
