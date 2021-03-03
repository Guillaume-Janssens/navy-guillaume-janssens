/*
** EPITECH PROJECT, 2020
** other
** File description:
** other functions
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

int sub_main(int argc, char **argv)
{
    pid_t pid = getpid();
    char **my_map = malloc(sizeof(char) * 170);
    char **base_map = malloc(sizeof(char) * 170);

    if (argc == 2)
	first_user_pid(pid, my_map, argv, base_map);
    else if (argc == 3)
        second_user_connected(my_map, argv, base_map, pid);
    else
        return (84);
    return (0);
}

int check_null(int argc, char **argv)
{
    if (load_file(argv[argc - 1]) == NULL)
        return (84);
    else
        return (0);
}
