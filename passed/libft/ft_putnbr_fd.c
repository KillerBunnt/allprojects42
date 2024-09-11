/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:49:38 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 16:08:44 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	writeme(int a, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	writeme(n, fd);
}

static void	writeme(int a, int fd)
{
	char	b;

	if (a >= 10 || a <= -10)
		writeme(a / 10, fd);
	if (a < 0)
		b = '0' + (-(a % 10));
	else
		b = '0' + (a % 10);
	write(fd, &b, 1);
}
