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

void	sendchar(int digits, char *charbin, int serverpid)
{
	while (--digits >= 0)
	{
		if (charbin[digits] == '1')
		{
			while (kill(serverpid, SIGUSR1))
				continue ;
		}
		else
		{
			while (kill(serverpid, SIGUSR2))
				continue ;
		}
		usleep(500);
	}
}

void	sendinitial(int digits, int serverpid, char *charbin)
{
	int	temp;

	temp = 7 - digits;
	while (temp-- >= 0)
	{
		while (kill(serverpid, SIGUSR2))
			continue ;
		usleep(500);
	}
	sendchar(digits, charbin, serverpid);
}

int	checkpid(int argcount, int serverpid)
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
	int		serverpid;
	char	*charbin;

	serverpid = ft_atoi(args[1]);
	if (!checkpid(argcount, serverpid))
		return (0);
	index = -1;
	charbin = ft_calloc(32, sizeof(char));
	if (!charbin)
		return (0);
	while (args[2][++index])
	{
		charcode = args[2][index];
		ft_bzero(charbin, sizeof(char) * 32);
		digits = binconv(charcode, charbin, 0);
		digits++;
		if (digits <= 7)
			sendinitial(digits, serverpid, charbin);
		ft_printf("%c", charcode);
	}
}
