/*
** EPITECH PROJECT, 2020
** navy 
** File description:
** controls the rounds of each player and end of game.
*/

#include <unistd.h>
#include "my.h"

int check_map(char **my_map)
{
    int x = 3;
    int y = 3;

    while (x <= 11) {
        while (y <= 16) {
            if (my_map[x][y] >= '2' && my_map[x][y] <= '5')
                return (0);
            y += 1;
        }
        x += 1;
        y = 3;
    }
    return (1);
}

void rounds(char **my_map, int play, char **base_map)
{
    while (check_map(my_map) != 1) {
        if (play == 2) {
            game(my_map, 2, base_map);
            play = 1;
        }
        else if (play == 1) {
            game(my_map, 1, base_map);
            play = 2;
        }
        missile.attack = 0;
        missile.hit = 0;
        missile.str = 0;
    }
}
