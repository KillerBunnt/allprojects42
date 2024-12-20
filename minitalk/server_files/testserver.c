/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testserver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:29:42 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/19 16:29:45 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void fillbuffer(unsigned char *buffer, int sigcode)
{
	if (sigcode == SIGUSR1)
		*buffer = (*buffer >> 1) | 128;
	else
		*buffer = (*buffer >> 1);
}

void	signalhandlers(int sigcode, siginfo_t *client, void *others)
{
	static int				signalsrecieved = 0;
	static int				index = 0;
	static unsigned char	unicode[4] = {0,0,0,0};
	static unsigned char	buffer;

	usleep(200);
	others = (void *)others;
	signalsrecieved++;
	fillbuffer(&buffer, sigcode);
	if (signalsrecieved == 8)
	{
		if (buffer == 255)
			ft_putstr_fd("\nEND OF MESSAGE\n", 1);
		else if (index < 4)
		{
			unicode[index] = buffer;
			index++;
		}
		if (buffer == 0)
		{
			ft_putstr_fd((char *)unicode, 1);
			while (index >= 0)
				unicode[index--] = 0;
			index = 0;
		}
		buffer = 0;
		signalsrecieved = 0;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	unsigned int		serverpid;
	struct sigaction	handle;

	serverpid = getpid();
	ft_printf("Server's process ID: %u\n", serverpid);
	handle.sa_sigaction = signalhandlers;
	sigaction(SIGUSR1, &handle, NULL);
	sigaction(SIGUSR2, &handle, NULL);
	while (1)
		pause();
}
