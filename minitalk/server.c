#include "minitalk.h" 

static void	handle_char_print(unsigned char c)
{
	ssize_t	i;
	
	i = write(1, &c, 1);
	if (i == -1)
	{
		print_error("Write Error");
		exit(1);	
	}
}

void    server_signal_handler(int signo, siginfo_t *info, void *more_info)
{
    static unsigned char current_c;
    static int  bit;
    static pid_t    client_pid;
    void *mor;
    
    mor = more_info;
    client_pid = info->si_pid;
    current_c |= (signo == SIGUSR1);
    bit++;
    if (bit == 8)
    {
    
        if (current_c == '\0')
        {
            current_c = 0;
	    bit = 0;
            write(1, "\n", 1);
            kill_handler(client_pid, SIGUSR2);
        }
        else
        {
           	handle_char_print(current_c);
        }
        current_c = 0;
        bit = 0;
    }
    else
        current_c <<= 1;
    kill_handler(client_pid, SIGUSR1);
}

int main(void)
{
    pid_t   pid;
    
    pid = getpid();
    printf("%i \n", pid);
    signal_handler(SIGUSR1, server_signal_handler, true);
    signal_handler(SIGUSR2, server_signal_handler, true);
     while(1)
    	usleep(30);
}
