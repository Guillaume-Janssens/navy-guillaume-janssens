/*
** EPITECH PROJECT, 2020
** navy
** File description:
** function for tab
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *load_file(char const *filepath)
{
    int i = 0;
    int fd;
    struct stat buf;
    char *buffer;
    int st;

    st = stat(filepath, &buf);
    if (st == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * buf.st_size + 1);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    i = read(fd, buffer, buf.st_size);
    if (i == -1)
        return (NULL);
    buffer[i] = '\0';
    close(fd);
    return (buffer);
}

void my_cat_tab(char **c, int nb_rows, int nb_size)
{
    int nb = 0;
    
    while(nb < nb_rows) {
	write(1, c[nb], nb_size);
        nb += 1;
    }
}

void fill_buffer(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        buffer[i] = '.';
        i += 1;
    }
}

char **fill_tab(int nb_rows, int nb_size, char **c, char *buffer)
{
    int j = 0;
    int i = 0;
    int k = 0;

    while (i < nb_rows) {
        while (j < nb_size) {
            c[i][j] = buffer[k];
            j += 1;
            k += 1;
	}
        j = 0;
	i += 1;
    }
    return (c);
}

char **create_tab(int nb_rows, int nb_size, char *buffer)
{
    char **c = malloc(sizeof(char *) * nb_rows);
    int w = 0;
    
    while (w < nb_rows) {
        c[w] = malloc(sizeof(char) * nb_size);
        w += 1;
    }
    c = fill_tab(nb_rows, nb_size, c, buffer);
    return (c);
}
