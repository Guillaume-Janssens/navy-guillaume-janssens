/*
** EPITECH PROJECT, 2020
** str int
** File description:
** Functions that managed little functions to change str to int and vice versa
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "printf.h"
#include "my.h"

int str_to_int(char *str)
{
    int x = (str[1] - 48) + (str[0] - 64) * 10;

    return (x);
}

void int_to_str(int x)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = (x / 10) + 'A' - 1;
    str[1] = (x % 10) + '0';
    missile.str = str;
}

