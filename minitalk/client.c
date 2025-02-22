#include "minitalk.h"

volatile sig_atomic_t server_status;

void    end_handler(void)
{
    write_handler("Message recieved!\n");
    exit(0);
}

void    response_handler(void)
{
    	server_status = 1;
    	write_handler("send more ");
}

void    send_bit(char c, pid_t server_pid)
{
    int i;
    unsigned char	temp;

    i = CHAR_BIT;
    while (i > 0)
    {
        i--;
       	temp = (unsigned char)c >> i;
        if (temp % 2 == 0)
            kill_handler(server_pid, SIGUSR2);
        else
            kill_handler(server_pid, SIGUSR1);
        while (server_status == 0)
            usleep(30);
        server_status = 0;
    }
}

void send_msg(char *msg, pid_t server_pid)
{
    size_t  i;

    i = 0;
    while (msg[i])
    {
    	signal_handler(SIGUSR1, response_handler, false);
    	signal_handler(SIGUSR2, end_handler, false);
        send_bit(msg[i], server_pid);
        i++;
    }
    send_bit('\0', server_pid);
}

int main(int argc, char **argv)
{
    pid_t pid;
    if (argc != 3 || !argv[2] || !argv[1])
    {    
        print_error("argument error");
        exit(1);
    }
    pid = (pid_t)atoi(argv[1]);
    send_msg(argv[2], pid);
}
