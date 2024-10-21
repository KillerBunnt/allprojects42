#include "../includes/all.h"
//idea to do (binary code), wait for first signal, sleep for 200microsec, if
int signalsrecieved;

// void signal1handler(int sigcode);
// void signal2handler(int sigcode);

void signalhandlers(int sigcode)
{
	static unsigned int	unicode = 0;
	// char				codestr[5];
	unsigned int		temp;
	unsigned int		powed;
	// if (temp < 0x0080) //one byte
	// if (temp < 0x0800) //2 byte
	// if (temp < 0x10000) //3 byte
	// if (temp <= 0x10FFFF) //4 byte
	if (sigcode == -1)
	{
		unicode = 0;
		signalsrecieved = 0;
		return ;
	}
	if (sigcode == SIGUSR1)
	{
		unicode = unicode * 10 + 1;
		// ft_printf("1");
	}
	else if (sigcode == SIGUSR2)
	{
		unicode *= 10;
		// ft_printf("0");
	}
	signalsrecieved++;
	// ft_printf("|%d|", signalsrecieved);
	if (signalsrecieved == 8)
	{
		// ft_printf("%d\n", unicode);
		if (sigcode < 10000000)
		{
			temp = 0;
			powed = 1;
			while (unicode)
			{
				temp += (unicode % 10) * powed;
				if (powed == 1)
					powed++;
				else
					powed *= 2;
				unicode /= 10;
			}
			ft_printf("%c", temp);
		}
		else
			ft_printf("NEXTCHAR\n");
		signalsrecieved = 0;
		unicode = 0;
	}	
}

// void signal1handler(int sigcode)
// {
// 	ft_printf("RECIEVEDSIG1\n");
// 	if (signalsrecieved == 8)
// 	{
// 		if ()
// 		ft_printf("NEXTCHAR\n");
// 	}
// }

// void signal2handler(int sigcode)
// {

// }

int main()
{
	unsigned int serverpid;
	struct sigaction handle;

	signalsrecieved = 0;
	serverpid = getpid();
	ft_printf("Server's process ID: %u\n", serverpid);
	handle.sa_handler = signalhandlers;
	sigemptyset(&handle.sa_mask);
	
	sigaction(SIGUSR1, &handle, NULL);
	sigaction(SIGUSR2, &handle, NULL);
	while (1)
	{
		pause();
		// usleep(300);
		// if (signalsrecieved < 8)
		// 	signalhandlers(-1);
	}
		
}