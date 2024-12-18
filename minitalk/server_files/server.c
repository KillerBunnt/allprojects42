#include "../includes/all.h"
int signalsrecieved;

void processword(unsigned char unicode)
{
	unsigned int		temp;
	unsigned int		powed;

	temp = 0;
	powed = 1;
	if (unicode >> 7 == 0)
		ft_printf("%c", unicode);
	else
		ft_printf("(?)\n");
}

void signalhandlers(int sigcode)
{
	static unsigned char	unicode = 0;

	if (sigcode == SIGUSR1)
		unicode = (unicode << 1) | 1;
	else if (sigcode == SIGUSR2)
		unicode = (unicode << 1);
	signalsrecieved++;
	if (signalsrecieved == 8)
	{
		signalsrecieved = 0;
		processword(unicode);
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