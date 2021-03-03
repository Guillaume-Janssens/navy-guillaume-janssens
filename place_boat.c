/*
** EPITECH PROJECT, 2020
** navy
** File description:
** boat placer
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "printf.h"
#include "my.h"

char **base_map_create()
{
    char *buffer;
    char **c;
    int nb_rows;
    int nb_size;
    struct stat buf;
  
    buffer = load_file("maps/map_navy.txt");
    if (buffer == NULL)
        return (NULL);
    stat("maps/map_navy.txt", &buf);
    nb_rows = my_getnbr(buffer);
    buffer = pass_line(buffer, buf.st_size);
    nb_size = count_cols(buffer);
    c = create_tab(nb_rows, nb_size, buffer);
    return (c);
}

char **read_pos(char *name)
{
    char *buffer;
    char **c;
    int nb_rows;
    int nb_size;
    struct stat buf;

    buffer = load_file(name);
    if (buffer == NULL)
        return (NULL);
    stat(name, &buf);
    nb_rows = 4;
    buffer = not_pass_line(buffer, buf.st_size);
    nb_size = count_cols(buffer);
    c = create_tab(nb_rows, nb_size, buffer);
    return (c);
}

char **my_else(char **base_map, int x, int y, int i)
{
    int w = missile.w;

    if (i == 1)
        base_map = second_boat(base_map, w, x, y);
    else if (i == 2)
        base_map = third_boat(base_map, w, x, y);
    else if (i == 3)
        base_map = fourth_boat(base_map, w, x, y);
    return (base_map);
}

char **put_boats(char **base_map, char *av)
{
    char **pos = read_pos(av);
    int i = 0;
    int x, y;
    int z, w;
    
    while (i <= 3) {
        x = pos[i][3] - '0' + 1;
        y = ((pos[i][2] - 64) * 2);
        z = pos[i][6] - '0' + 1;
        w = ((pos[i][5] - 64) * 2);
        missile.z = z;
        missile.w = w;
        if (i == 0)
            base_map = first_boat(base_map, w, x, y);
        else
            base_map = my_else(base_map, x, y, i);
        i += 1; 
    }
    return (base_map);
}
