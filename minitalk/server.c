#include "minitalk.h"

static void empty(unsigned char *arr)
{
	size_t	i;
	
	i = 0;
	
	while (arr[i])
	{
		arr[i] = '\0';
		i++;
	}
}


static void	writer(unsigned char c[])
{
	size_t	i;
	ssize_t	j;
	
	i = 0;
	while (c[i])
	{
		
		j = write(1, &c[i], 1);
		if (j == -1)
		{
			print_error("Write Error");
			exit(1);
		}
		i++;
	}
}
void    server_signal_handler(int signo, siginfo_t *info)
{
	static unsigned char c;
	static int bit;
	static unsigned char buffer[2000000];
	static int i;
	static pid_t	client_pid;
	
	client_pid = info->si_pid;
	c |= (signo == SIGUSR1);
	bit++;
	if (bit == CHAR_BIT)
	{
		if(c == '\0')
		{
			buffer[i] = '\0';
			i = 0;
			c = 0;
			bit = 0;
			writer(buffer);
			empty(buffer);
			kill_handler(client_pid, SIGUSR2);
		}
		else
		{
			buffer[i] = c;
			i++;
		}
		c = 0;
		bit = 0;
	}
	else
		c <<= 1;
	 kill_handler(client_pid, SIGUSR1);
}

/*void    server_signal_handler(int signo, siginfo_t *info, void *more_info)
{
    static unsigned char current_c;
    static int  bit;
    static pid_t    client_pid;
    static unsigned char	c[2000000];
    static size_t	i;
    void	*mor;
    
    	mor = more_info;
	client_pid = 0;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	current_c |= (signo == SIGUSR1);
	bit++;
	if (bit == CHAR_BIT)
	{
		if (current_c == '\0')
		{
			current_c = 0;
			bit = 0;
			writer(c);
			i = 0;
			kill_handler(client_pid, SIGUSR2);
		}
		else
			c[i] = current_c;
        	current_c = 0;
        	bit = 0;
        	i++;
	}
    else
        current_c <<= 1;
    kill_handler(client_pid, SIGUSR1);
}
*/

int main(void)
{
    pid_t   pid;
    
    pid = getpid();
    print_pid(pid);
    signal_handler(SIGUSR1, server_signal_handler, true);
    signal_handler(SIGUSR2, server_signal_handler, true);
     while(1)
    	usleep(10);
}
