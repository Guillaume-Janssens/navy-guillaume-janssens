/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main
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

missile_t missile = {0, 0, 0, 0, 0, 0, 0};

void help()
{
    my_printf("USAGE\n");
    my_printf("\t./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tfirst_player_pid: only for the 2nd player.");
    my_printf("pid of the first player.\n");
    my_printf("navy_positions:");
    my_printf(" file representing the positions of the ships.\n");
}

void first_user_connection(char **my_map, char **argv, char **base_map)
{
    my_printf("waiting for enemy connection...\n \n");
    pause();
    my_printf("enemy connected\n");
    kill(missile.pid, SIGUSR1);
    my_map = base_map_create();
    base_map = base_map_create();
    my_map = put_boats(my_map, argv[1]);
    rounds(my_map, 1, base_map);
}   

int first_user_pid(pid_t pid, char **my_map, char **argv, char **base_map)
{
    struct sigaction act;

    my_memset(&act, 0, sizeof(act));
    my_printf("my_pid: ");
    my_printf("%d\n", pid);
    act.sa_sigaction = &handshake;
    act.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR2, &act, NULL) == 0)
        first_user_connection(my_map, argv, base_map);
    else
        return (84);
    return (0);   
}

void second_user_connected(char **my_map, char **argv,
                           char **base_map, pid_t pid)
{
    struct sigaction act;
    
    my_printf("my_pid: %d\n", pid);
    my_memset(&act, 0, sizeof(act));
    act.sa_sigaction = &handshake;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    kill(my_getnbr(argv[1]), SIGUSR2);
    pause();
    my_printf("successfully connected\n");
    my_map = base_map_create();
    base_map = base_map_create();
    my_map = put_boats(my_map, argv[2]);
    rounds(my_map, 2, base_map);
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        help();
        return (0);
    }
    else {
        if (check_null(argc, argv) == 84)
            return (84);
        sub_main(argc, argv);
    }
    return (0);
}
