/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#pragma once

#include <signal.h>
#include <sys/types.h>

//structures

typedef struct missile_s
{
    int pid;
    int attack;
    int n;
    int hit;
    char *str;
    int z;
    int w;
}missile_t;

extern missile_t missile;

//libC functions

int my_putnbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char const *str);
char *my_revstr(char *str);
int my_strlen(char const *str);

//principal functions for navy

void *my_memset(void *s, int c, int n);
void send_signals(int pid, siginfo_t *siginfo, void *context);
void handshake(int pid, siginfo_t *siginfo, void *context);
char **base_map_create();
char **put_boats(char **base_map, char *av);
char **fourth_boat(char **map, int w, int x, int y);
char **third_boat(char **map, int w, int x, int y);
char **second_boat(char **map, int w, int x, int y);
char **first_boat(char **map, int w, int x, int y);
char *get_input(void);
char *swap_input(char *str, char c);
char **attack_map(int attack, char **map);
void game(char **my_map, int play, char **base_map);
void my_kill(int signal, int pid);
void recieve_signal(int signal, siginfo_t *siginfo, void *context);

//functions for tab and file

int count_cols(char *buffer);
char *pass_line(char *buffer, int size);
char *not_pass_line(char *buffer, int size);
char *load_file(char const *filepath);
void my_cat_tab(char **c, int nb_rows, int nb_size);
void fill_buffer(char *buffer);
char **fill_tab(int nb_rows, int nb_size, char **c, char *buffer);
char **create_tab(int nb_rows, int nb_size, char *buffer);

//functions for signals attack

void sender(int attack);
void recieve_attack(int signal, siginfo_t *siginfo, void *context);
void get_hit(int signal, siginfo_t *siginfo, void *context);

// players functions

void first_player(int attack, struct sigaction act, char **base_map);
void second_player(struct sigaction act, char **my_map);
int first_user_pid(pid_t pid, char **my_map, char **argv, char **base_map);
void second_user_connected(char **my_map, char **argv,
                           char **base_map, pid_t pid);
void rounds(char **my_map, int play, char **base_map);
int check_map(char **my_map);

//tiers functions

void help();
int str_to_int(char *str);
void int_to_str(int x);
int sub_main(int argc, char **argv);
int check_null(int argc, char **argv);
