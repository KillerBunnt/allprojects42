/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:40:38 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/25 17:20:35 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *addr, unsigned int find, unsigned int byte)
{
	unsigned int	count;
	char			*test;

	test = addr;
	count = 0;
	while (count < byte)
	{
		if ((unsigned char)test[count] == (unsigned char)find)
			return (test + count);
		count++;
	}
	return (0);
}
