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
	while (args[2][++index])
	{
		charcode = args[2][index];
		ft_memset(charbin, 0, sizeof(charbin));
		digits = binconv(charcode, charbin, 0);
		digits++;
		ft_printf("(%c, %d, %s)\n", charcode, digits, charbin);
		if (digits <= 7)
		{
			temp = 7 - digits;
			while (temp-- >= 0)
			{
				kill(serverPID, SIGUSR2);
				usleep(400);
			}
			while (--digits >= 0)
			{
				if (charbin[digits] == '1')
					kill(serverPID, SIGUSR1);
				else
					kill(serverPID, SIGUSR2);
				usleep(400);
			}
		}
	}
}