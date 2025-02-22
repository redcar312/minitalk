#include "minitalk.h"

void    handler(int signo, siginfo_t *info, void *more_info)
{
    static unsigned char current_c;
    static int  bit;
    static pid_t    client_pid;

    client_pid = info->si_pid;
    bit = 0;
    current_c |= (signo == SIGUSR1)
    if (bit == CHAR_BIT)
    {
        bit = 0;
        if (c == '\0')
        {
            write_handler("\n");
            kill_handler(client_pid, SIGUSR2);
        }
        else
            write_handler((char *)current_c);
        current_c = 0;
    }
    else
        current_c <<= 1;
    kill_handler(client_pid, SIGUSR1);
}

void    init_signals(int, void *, bool SA_INFO)
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

int main(void)
{
    pid_t   pid;
    int i;
    pid = get_pid();
    i = print_pid(pid);
    if (i == -1)
    {
        print_error("pid print error");
        exit(0);
    }
    init_signals(SIGUSER1, handler, true);
    init_signals(SIGUSER2, handler, true);
}