/*
** EPITECH PROJECT, 2020
** navy 
** File description:
** function that send the attack
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void sender(int attack)
{
    int c = 0;
    
    while (c < attack) {
        my_kill(1, missile.pid);
        c += 1;
    }
    my_kill(2, missile.pid);
}
