/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:13:52 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/25 17:19:08 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	count;

	count = -1;
	while ((str1[++count] || str2[count]) && count < n)
	{
		if (!((unsigned char)str1[count] == (unsigned char)str2[count]))
		{
			if (((unsigned char)str1[count] < (unsigned char)str2[count]))
				return (-1);
			return (1);
		}
	}
	return (0);
}
