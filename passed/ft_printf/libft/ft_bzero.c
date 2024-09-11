/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:29:59 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 15:55:57 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *addr, unsigned int byte)
{
	unsigned int	count;
	char			*test;

	test = addr;
	count = 0;
	while (count < byte)
	{
		test[count] = 0;
		count++;
	}
}
