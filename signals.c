/*
** EPITECH PROJECT, 2020
** signals.c
** File description:
** Files for treating signals
*/

#include <time.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "printf.h"

void *my_memset(void *s, int c, int n)
{
    unsigned char *pointer = s;

    while (n > 0) {
        *pointer = c;
        pointer += 1;
        n -= 1;
    }
    return (s);
}

void handshake(int signal, siginfo_t *siginfo, void *context)
{
    (void)context;
    if (signal == SIGUSR2)
        missile.pid = siginfo->si_pid;
    else if (signal == SIGUSR1)
        missile.pid = siginfo->si_pid;
}

void my_kill(int signal, int pid)
{
    struct sigaction act;

    my_memset(&act, 0, sizeof(act));
    if (signal == 1) {
        kill(pid, SIGUSR1);
        pause();
    }
    else if (signal == 2)
        kill(pid, SIGUSR2);
}

void recieve_attack(int signal, siginfo_t *siginfo, void *context)
{
    (void)context;
    (void)siginfo;
    if (signal == SIGUSR2)
        missile.n = 1;
    else if (signal == SIGUSR1) {
        missile.attack += 1;
        usleep(500);
        kill(missile.pid, SIGUSR2);
    }
}

void get_hit(int signal, siginfo_t *siginfo, void *context)
{
    (void)context;
    (void)siginfo;
    if (signal == SIGUSR2) {
        missile.hit = 1;
        my_printf("%c%c: hit\n\n", missile.str[0], missile.str[1]);
    }
    else if (signal == SIGUSR1) {
        missile.hit = 0;
        my_printf("%c%c: missed\n\n", missile.str[0], missile.str[1]);
    }
}
