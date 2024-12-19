/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:11:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/18 15:11:59 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

int	binconv(int num, char *bin, int count)
{
	bin[count] = '0' + (num % 2);
	if (num > 1)
		count = binconv (num / 2, bin, count + 1);
	return (count);
}

void sendinitial(int digits, int serverpid)
{
	int temp;

	temp = 7 - digits;
	while (temp-- >= 0)
	{
		ft_printf("0");
		kill(serverpid, SIGUSR2);
		usleep(300);
	}
}

void sendchar(int digits, char *charbin, int serverpid)
{
	while (--digits >= 0)
	{
		ft_printf("%c", charbin[digits]);
		if (charbin[digits] == '1')
			kill(serverpid, SIGUSR1);
		else
			kill(serverpid, SIGUSR2);
		usleep(300);
	}
}

int checkpid(int argcount, int serverpid)
{
	if (argcount != 3)
		return (0);
	if (serverpid < 0)
		return (0);
	return (1);
}

int	main(int argcount, char **args)
{
	int		index;
	int		charcode;
	int		digits;
	char	charbin[22];

	if(!checkpid(argcount, ft_atoi(args[1])))
		return (0);
	index = -1;
	while (args[2][++index])
	{
		charcode = args[2][index];
		ft_memset(charbin, 0, sizeof(char) * 22);
		digits = binconv(charcode, charbin, 0);
		digits++;
		if (digits <= 7)
		{
			sendinitial(digits, ft_atoi(args[1]));
			sendchar(digits, (char *)charbin, serverpid);
			usleep(500);
		}
		ft_printf("(%c, %d, %s)\n", charcode, digits, charbin);
	}
}
