/*
** EPITECH PROJECT, 2020
** my input
** File description:
** Functions that managed inputs
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "printf.h"
#include "my.h"

char *swap_input(char *str, char c)
{
    if (str[0] >= '1' && str[0] <= '8' && str[1] >= 'A' && str[1] <= 'H') {
        c = str[0];
        str[0] = str[1];
        str[1] = c;
    }
    return (str);
}

char *get_input(void)
{
    char *str = malloc(sizeof(char) * 3);
    int n = 0;
    char c = 0;

    my_printf("attack: ");
    usleep(1000);
    while (n < 1) {
        read(0, str, 3);
        str = swap_input(str, c);
	if (str[1] >= '1' && str[1] <= '8' && str[0] >= 'A' && str[0] <= 'H') {
            n = 2;
        }
        else {
            my_printf("wrong position\nattack: ");
            n = 0;
        }
    }
    missile.str = str;
    return (str);
}
