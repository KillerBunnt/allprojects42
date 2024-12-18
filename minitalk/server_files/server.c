#include "../includes/all.h"
int signalsrecieved;

void processword(unsigned int unicode)
{
	unsigned int		temp;
	unsigned int		powed;

	temp = 0;
	powed = 1;
	if (unicode < 10000000)
	{
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
		ft_printf("(?)\n");
}

void signalhandlers(int sigcode)
{
	static unsigned int	unicode = 0;

	if (sigcode == -1)
	{
		unicode = 0;
		signalsrecieved = 0;
		return ;
	}
	if (sigcode == SIGUSR1)
		unicode = unicode * 10 + 1;
	else if (sigcode == SIGUSR2)
		unicode *= 10;
	signalsrecieved++;
	if (signalsrecieved == 8)
	{
		processword(unicode);
		signalsrecieved = 0;
		unicode = 0;
	}
}

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
		pause();
}