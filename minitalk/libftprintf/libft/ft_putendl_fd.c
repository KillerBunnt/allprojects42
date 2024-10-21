/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:33:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 16:08:21 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		count;
	char	n;

	n = '\n';
	count = 0;
	while (s[count])
		count++;
	write(fd, s, count);
	write(fd, &n, 1);
}
