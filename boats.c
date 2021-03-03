/*
** EPITECH PROJECT, 2020
** navy
** File description:
** placing boats on map
*/

#include "my.h"

char **first_boat(char **base_map, int w, int x, int y)
{
    int i = 0;
    int z = missile.z;

    base_map[x][y] = i + 48 + 2;
    base_map[z][w] = i + 48 + 2;
    return (base_map);
}

char **second_boat(char **base_map, int w, int x, int y)
{
    int i = 1;
    int z = missile.z;

    base_map[x][y] = i + 48 + 2;
    if (z == x)
        base_map[z][w - 2] = i + 48 + 2;
    else
        base_map[z - 1][w] = i + 48 + 2;
    base_map[z][w] = i + 48 + 2;
    return (base_map);
}

char **third_boat(char **base_map, int w, int x, int y)
{
    int i = 2;
    int z = missile.z;

    base_map[x][y] = i + 48 + 2;
    if (z == x) {
        base_map[z][w - 2] = i + 48 + 2;
        base_map[z][w - 4] = i + 48 + 2;
    }
    else {
        base_map[z - 1][w] = i + 48 + 2;
        base_map[z - 2][w] = i + 48 + 2;
    }
    base_map[z][w] = i + 48 + 2;
    return (base_map);
}

char **fourth_boat(char **base_map, int w, int x, int y)
{
    int i = 3;
    int z = missile.z;

    base_map[x][y] = i + 48 + 2;
    if (z == x) {
        base_map[z][w - 2] = i + 48 + 2;
        base_map[z][w - 4] = i + 48 + 2;
        base_map[z][w - 6] = i + 48 + 2;
    }
    else {
        base_map[z - 1][w] = i + 48 + 2;
        base_map[z - 2][w] = i + 48 + 2;
        base_map[z - 3][w] = i + 48 + 2;
    }
    base_map[z][w] = i + 48 + 2;
    return (base_map);
}
