#include "minitalk.h"
volatile sig_atomic_t server_status;

void    end_handler(int signo)
{
    write_handler("Message recieved!\n");
    exit(1);
}

void    response_handler(int signo)
{
    server_status = 1;
}

void    kill_handler(pid_t pid, int signo)
{
    if(kill(pid, signo) == -1)
    {
        print_error("kill error");
        exit(0);
    }
}
void    send_bit(char c, pid_t server_pid)
{
    int i;
    unsigned char temp;

    temp = (unsigned char)c
    i = 0;
    while(i < CHAR_BIT)
        i++;
    while(i > 0)
    {
        i--;
        if(temp >> i)
            kill_handler(pid, SIGUSR1)
        else
            kill_handler(pid, SIGUSR2);
        while(server_status == 0)
            usleep(30);
        server_status = 0;
    }
}

void send_msg(char *msg, pid_t server_pid)
{
    size_t  i;

    i = 0;
    while(msg[i])
    {
        send_bit(msg[i], server_pid);
        i++;
    }
    send_bit('\0', server_pid)
}

int main(int argc, char **argv)
{
    pid_t pid;
    if(ac != 3)
    {    
        print_error("argument error");
        exit();
    }
    pid = (pid_t)atoi(argv[1]);
    signal_handler(SIGUSR1, response_handler, false);
    signal_hanlder(SIGUSR2, end_handler, false);
    send_msg(argv[2])

}