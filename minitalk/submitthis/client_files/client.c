/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testclient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:11:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/22 18:59:34 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

int	manager(int mode)
{
	static int	stop = 0;

	if (!mode)
	{
		if (stop)
		{
			stop = 0;
			return (1);
		}
	}
	else
		stop = 1;
	return (0);
}

void	sendchar(char chr, int serverpid)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (chr & 1)
			kill(serverpid, SIGUSR1);
		else
			kill(serverpid, SIGUSR2);
		chr = chr >> 1;
		while (!manager(0))
			continue ;
	}
}

int	checkpid(int argcount, int serverpid)
{
	if (argcount != 3)
		return (0);
	if (serverpid < 0)
		return (0);
	return (1);
}

void	catchsignal(int sig)
{
	manager(sig);
}

int	main(int argcount, char **args)
{
	int		serverpid;
	int		index;
	char	curchr;

	signal(SIGUSR1, catchsignal);
	serverpid = ft_atoi(args[1]);
	if (!checkpid(argcount, serverpid))
		return (0);
	index = 0;
	curchr = args[2][index];
	while (curchr)
	{
		sendchar(curchr, serverpid);
		curchr = args[2][++index];
		sendchar((char)0, serverpid);
	}
	sendchar((char)255, serverpid);
}
