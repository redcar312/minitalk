#include "minitalk.h"

void    signal_handler(int, void *, bool SA_INFO)
{
    struct sigaction sa;
    if(SA_INFO)
    {
        sa.sa_flags = SA_SIGINFO;
        sa.sa_sigaction = handler;
    }
    else
        sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    if (sigaddset(&sa.sa_mask, SIGUSR1) == -1 || sigaddset(&sa.sa_mask, SIGUSR2) == -1)
    {
        print_error("sigaddset error");
        exit(0);
    }
    if (sigaction(signo, &sa, NULL) == -1)
    {
        print_error("sigaction error");
        exit(0);
    }
}


void write_handler(char *str)
{
    size_t  i;
    ssize_t j;

    i = 0;
    while (str[i])
    {
        j = write(1, &str[i], 1);
        if (j == -1)
        {
                print_error("Write Failed");
                exit(0);
        }
        i++;
    }
}

void    kill_handler(pid_t pid, int signo)
{
    if(kill(pid, signo) == -1)
    {
        print_error("kill error");
        exit(0);
    }
}

void    print_error(char *str)
{
    size_t  i;

    i = 0;
    if(!str)
        return ;
    while(str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int print_pid(pid_t pid, i)
{
    char    c;

    if (i == -1)
        return (i);
    if (pid < 0)
        return (-1);
    if (pid >= 10)
    {
        i = print_pid(pid / 10, i);
        i = print_pid(pid % 10, i);
    }
    if (pid < 10)
    {
        c = pid + '0';
        i = write(1, &pid, 1);
        return (i);
    }
}