/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:08:13 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/30 14:56:13 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	count2;
	size_t	orig;

	count2 = ft_strlen(src);
	if (size == 0)
		return (count2);
	count = ft_strlen(dest);
	orig = count;
	count2 = 0;
	while (src[count2])
	{
		if (count < (size - 1))
			dest[count] = src[count2];
		else if (count == (size - 1))
			dest[count] = 0;
		count++;
		count2++;
	}
	if (orig > size)
		orig = size;
	dest[count] = '\0';
	return (orig + count2);
}
