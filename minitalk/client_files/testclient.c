/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testclient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:11:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/18 15:11:59 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	sendchar(char chr, int serverpid)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		usleep(300);
		if (chr & 1)
			kill(serverpid, SIGUSR1);
		else
			kill(serverpid, SIGUSR2);
		chr = chr >> 1;
	}
	pause();
}

int	checkpid(int argcount, int serverpid)
{
	if (argcount != 3)
		return (0);
	if (serverpid < 0)
		return (0);
	return (1);
}

void catchsignal(int sig)
{
	sig = 0;
	return ;
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
