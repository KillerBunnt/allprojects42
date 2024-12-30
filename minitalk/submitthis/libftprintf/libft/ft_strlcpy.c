/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:10:09 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/25 16:34:47 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *from, size_t size)
{
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = ft_strlen(from);
	if (!from || size == 0)
		return (count2);
	while (count < size - 1 && from[count])
	{
		dest[count] = from[count];
		count++;
	}
	dest[count] = 0;
	return (count2);
}
