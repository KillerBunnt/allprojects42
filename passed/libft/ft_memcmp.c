/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:41:43 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 17:48:28 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t byte)
{
	size_t				count;
	unsigned char		*hold1;
	unsigned char		*hold2;

	count = 0;
	hold1 = (unsigned char *)str1;
	hold2 = (unsigned char *)str2;
	while (count < byte)
	{
		if (!(hold1[count] == hold2[count]))
			return (hold1[count] - hold2[count]);
		count++;
	}
	return (0);
}
