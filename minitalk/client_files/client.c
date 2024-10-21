#include "../includes/all.h"

int binconv(int num, char *bin, int count)
{
	bin[count] = '0' + (num % 2);
	if (num > 1)
		count = binconv (num / 2, bin, count + 1);
	return (count);
}

int main(int argcount, char **args)
{
	int index;
	int charcode;
	int digits;
	int temp;
	int serverPID;
	// int clientPID;
	char charbin[22];

	// clientPID = getpid();
	serverPID = ft_atoi(args[1]);
	if (argcount != 3)
		return (0);
	if (serverPID < 0)
		return (0);
	index = -1;
	// ft_memset(charbin, 0, sizeof(charbin));
	// digits = binconv(charcode, charbin, 0);
	// temp = digits % 8;
	// while (++temp <= 8)
	// {
	// 	kill(serverPID, SIGUSR2);
	// 	usleep(200);
	// }
	// while (--digits >= 0)
	// {
	// 	// ft_printf("(%d, %c)", digits, charbin[digits]);
	// 	if (charbin[digits] == '1')
	// 		kill(serverPID, SIGUSR1);
	// 	else
	// 		kill(serverPID, SIGUSR2);
	// 	usleep(200);
	// }
	// temp = 0;
	// while (++temp <= 8)
	// {
	// 	kill(serverPID, SIGUSR1);
	// 	usleep(200)
	// }
	while (args[2][++index])
	{
		charcode = args[2][index];
		ft_memset(charbin, 0, sizeof(charbin));
		digits = binconv(charcode, charbin, 0);
		digits++;
		if (digits <= 7)
		{
			kill(serverPID, SIGUSR2);
			usleep(400);
			temp = 7 - digits;
			while (--temp >= 0)
			{
				kill(serverPID, SIGUSR2);
				usleep(400);
			}
			while (--digits >= 0)
			{
				// ft_printf("(%d, %c)", digits, charbin[digits]);
				if (charbin[digits] == '1')
					kill(serverPID, SIGUSR1);
				else
					kill(serverPID, SIGUSR2);
				usleep(400);
			}
		}
		// else if (digits <= 11)

		// else if (digits <= 16)

		// else if (digits <= 21)

		ft_printf("(%c, %d, %s)\n", charcode, digits, charbin);
	}
}