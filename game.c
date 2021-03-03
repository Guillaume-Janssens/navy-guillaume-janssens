/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game code
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "printf.h"
#include "my.h"

char **attack_map(int attack, char **map)
{
    int hit = missile.hit;
    int x = (attack % 10) + 1;
    int y = (attack / 10) * 2;

    if (hit == 0)
        map[x][y] = 'o';
    else if (hit == 1)
        map[x][y] = 'x';
    return (map);
}

char **under_attack(char **map)
{
    int attack = missile.attack;

    if (map[attack % 10 + 1][(attack / 10) * 2] == '.') {
        kill(missile.pid, SIGUSR1);
        map[attack % 10 + 1][(attack / 10) * 2] = 'o';
        my_printf("%s: missed\n\n", missile.str);
    }
    else {
        kill(missile.pid, SIGUSR2);
	map[attack % 10 + 1][(attack / 10) * 2] = 'x';
        my_printf("%s: hit\n\n", missile.str);
    }
    return (map);
}

void first_player(int attack, struct sigaction act, char **base_map)
{   
    attack = str_to_int(get_input());
    sender(attack);
    act.sa_sigaction = &get_hit;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    pause();
    base_map = attack_map(attack, base_map);
}

void second_player(struct sigaction act, char **my_map)
{
    my_printf("waiting for enemy's attack...\n");
    act.sa_sigaction = &recieve_attack;
    while (missile.n < 1) {
        sigaction(SIGUSR1, &act, NULL);
        sigaction(SIGUSR2, &act, NULL);
        pause();
    }
    int_to_str(missile.attack);
    under_attack(my_map);
}

void game(char **my_map, int play, char **base_map)
{
    int attack = 0;
    struct sigaction act;

    my_memset(&act, 0, sizeof(act));
    my_printf("\nmy position:\n");
    my_cat_tab(my_map, 10, 18);
    my_printf("\nenemy's positions:\n");
    my_cat_tab(base_map, 10, 18);
    my_printf("\n");
    if (play == 1)
        first_player(attack, act, base_map);
    else if (play == 2)
        second_player(act, my_map);
}
