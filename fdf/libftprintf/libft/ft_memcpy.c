/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:42:46 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 16:05:59 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, unsigned int byte)
{
	unsigned int	count;
	char			*hold1;
	const char		*hold2;

	count = 0;
	hold1 = to;
	hold2 = from;
	if (hold1 == 0 && hold2 == 0)
		return (0);
	while (count < byte)
	{
		hold1[count] = hold2[count];
		count++;
	}
	return (to);
}
