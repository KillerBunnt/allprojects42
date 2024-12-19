/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:29:42 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/19 16:29:45 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	processword(unsigned char unicode)
{
	ft_putchar_fd(unicode, 1);
}

void	signalhandlers(int sigcode)
{
	static int				signalsrecieved = 0;
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

int	main(void)
{
	unsigned int		serverpid;
	struct sigaction	handle;

	serverpid = getpid();
	ft_printf("Server's process ID: %u\n", serverpid);
	handle.sa_handler = signalhandlers;
	signal(SIGUSR1, &signalhandlers);
	signal(SIGUSR2, &signalhandlers);
	while (1)
		pause();
}
