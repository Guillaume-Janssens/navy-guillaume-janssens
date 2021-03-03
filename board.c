/*
** EPITECH PROJECT, 2020
** navy
** File description:
** function that change the board
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *pass_line(char *buffer, int size)
{
    int i = 0;
    int j = 0;
    char *new_buffer = malloc(sizeof(char) * size);

    while(buffer[i] != '\n')
        i += 1;
    i += 1;
    while (buffer[i] != '\0') {
        new_buffer[j] = buffer[i];
	j += 1;
        i += 1;
    }
    return (new_buffer);
}

char *not_pass_line(char *buffer, int size)
{
    int i = 0;
    int j = 0;
    char *new_buffer = malloc(sizeof(char) * size);

    while (buffer[i] != '\0') {
        new_buffer[j] = buffer[i];
	j += 1;
        i += 1;
    }
    return (new_buffer);
}

int count_cols(char *buffer)
{
    int i = 0;

    while(buffer[i] != '\n')
        i += 1;
    i += 1;
    return (i);
}
