/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:31:20 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/26 18:44:47 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*temp;
	size_t			count2;

	count2 = 0;
	if (size && count && UINT_MAX / count < size)
		return (0);
	temp = malloc(count * size);
	if (temp == 0)
		return (0);
	while (count2 < count * size)
	{
		temp[count2] = 0;
		count2++;
	}
	return ((void *)temp);
}
