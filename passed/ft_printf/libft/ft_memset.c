/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:44:26 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 16:07:39 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *addr, int fill, unsigned int byte)
{
	unsigned int	count;
	char			*test;

	test = addr;
	count = 0;
	while (count < byte)
	{
		test[count] = fill;
		count++;
	}
	return (test);
}
