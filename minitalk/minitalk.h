#ifndef TALK_H
#define TALK_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


void    signal_handler(int, void *, bool SA_INFO);
void	write_handler(char *str);
void    kill_handler(pid_t pid, int signo);
void    print_error(char *str);
void 	print_pid(pid_t pid);
void    server_signal_handler(int signo, siginfo_t *info);
int	f_atoi(const char *str);
#endif
