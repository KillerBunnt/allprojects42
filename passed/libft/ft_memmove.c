/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:43:34 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 18:01:23 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t byte)
{
	unsigned int	count;
	char			*hold1;
	const char		*hold2;

	hold1 = to;
	hold2 = from;
	if (from == 0 && to == 0)
		return (0);
	if (to == from)
		return (to);
	if (to < from)
		count = 0;
	else
		count = byte - 1;
	while (count < byte && count >= 0)
	{
		hold1[count] = hold2[count];
		if (to < from)
			count++;
		else
			count--;
	}
	return (to);
}
